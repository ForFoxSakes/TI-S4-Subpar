import subprocess
from pynput import keyboard

pitch = 0
yaw = 0
thrust = 0

def publish():
    direction_str = f"pitch: {pitch}, yaw: {yaw}"
    subprocess.run([
        "gz", "topic", "-t", "/direction_input",
        "-m", "gz.msgs.StringMsg",
        "-p", f"data: '{direction_str}'"
    ])
    subprocess.run([
        "gz", "topic", "-t", "/thrust_input",
        "-m", "gz.msgs.Double",
        "-p", f"data: {thrust}"
    ])
    print(f"📤 pitch={pitch}°, yaw={yaw}°, thrust={thrust} N")

def on_press(key):
    global pitch, yaw, thrust
    changed = False

    try:
        if key.char == 'w':
            thrust += 1
            changed = True
        elif key.char == 's':
            thrust = max(0, thrust - 1)
            changed = True
        elif key.char == 'a':
            yaw -= 5
            changed = True
        elif key.char == 'd':
            yaw += 5
            changed = True
        elif key.char == 'q':
            pitch += 5
            changed = True
        elif key.char == 'e':
            pitch -= 5
            changed = True
        elif key.char == 'x':
            thrust = 0
            changed = True
        elif key.char == 'r':
            pitch = 0
            yaw = 0
            changed = True
    except AttributeError:
        pass

    if changed:
        publish()

print("🎹 Besturing actief:")
print("  W/S → thrust op/af")
print("  A/D → yaw links/rechts")
print("  Q/E → pitch op/af")
print("  R → reset richting, X → thrust 0")
print("  Ctrl+C om te stoppen\n")

with keyboard.Listener(on_press=on_press) as listener:
    listener.join()
