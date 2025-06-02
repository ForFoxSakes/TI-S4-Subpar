<?xml version="1.0" ?>
<sdf version="1.7">
  <model name="SubparDrone">
    <static>false</static>

    <!-- HOOFDBODY -->
    <link name="body">
      <pose>0 0 0.2 0 0 0</pose>
      <inertial>
        <mass>20</mass>
        <inertia>
          <ixx>13.33</ixx>
          <iyy>6.67</iyy>
          <izz>20</izz>
          <ixy>0</ixy>
          <ixz>0</ixz>
          <iyz>0</iyz>
        </inertia>
      </inertial>
      <collision name="collision_body">
        <geometry><box><size>2 4 2</size></box></geometry>
      </collision>
      <visual name="visual_body">
        <geometry><box><size>2 4 2</size></box></geometry>
        <material><diffuse>0.5 0.5 0.5 1</diffuse></material>
        <transparency>0.9</transparency>
      </visual>
    </link>

    <!-- YAW joint (draait rond Z) -->
    <joint name="joint_motor_p_p_p_yaw" type="revolute">
      <parent>body</parent>
      <child>motor_p_p_p_yaw</child>
      <pose>1 2 1 0 0 0</pose>  <!-- Dit is de joint positie relatief tot body -->
      <axis>
        <xyz>0 0 1</xyz>
        <limit>
          <lower>-3.14</lower>
          <upper>3.14</upper>
        </limit>
      </axis>
    </joint>

    <!-- YAW-link: geen pose nodig, wordt bepaald door joint -->
    <link name="motor_p_p_p_yaw">
      <inertial>
        <mass>0.01</mass>
        <inertia>
          <ixx>0.0001</ixx>
          <iyy>0.0001</iyy>
          <izz>0.0001</izz>
          <ixy>0</ixy>
          <ixz>0</ixz>
          <iyz>0</iyz>
        </inertia>
      </inertial>
      <visual name="debug_marker_yaw">
        <geometry><box><size>0.2 0.2 0.2</size></box></geometry>
        <material><diffuse>1 1 0 1</diffuse></material>
      </visual>
    </link>

    <!-- PITCH joint (draait rond Y) -->
    <joint name="joint_motor_p_p_p_pitch" type="revolute">
      <parent>motor_p_p_p_yaw</parent>
      <child>motor_p_p_p_pitch</child>
      <pose>0 0 0.5 0 0 0</pose>  <!-- Offset omhoog relatief tot yaw link -->
      <axis>
        <xyz>0 1 0</xyz>
        <limit>
          <lower>-1.57</lower>
          <upper>1.57</upper>
        </limit>
      </axis>
    </joint>

    <!-- PITCH-link -->
    <link name="motor_p_p_p_pitch">
      <inertial>
        <mass>0.01</mass>
        <inertia>
          <ixx>0.0001</ixx>
          <iyy>0.0001</iyy>
          <izz>0.0001</izz>
          <ixy>0</ixy>
          <ixz>0</ixz>
          <iyz>0</iyz>
        </inertia>
      </inertial>
      <visual name="debug_pitch_marker">
        <geometry><box><size>0.1 0.1 0.1</size></box></geometry>
        <material><diffuse>0 0 1 1</diffuse></material>
      </visual>
    </link>

    <!-- FIXED joint tussen pitch en motorbol -->
    <joint name="joint_motor_p_p_p_fixed" type="fixed">
      <parent>motor_p_p_p_pitch</parent>
      <child>motor_p_p_p</child>
      <pose>0 0 0 0 0 0</pose>
    </joint>

    <!-- MOTORBOL -->
    <link name="motor_p_p_p">
      <inertial>
        <mass>0.02</mass>
        <inertia>
          <ixx>0.0018</ixx>
          <iyy>0.0018</iyy>
          <izz>0.0018</izz>
          <ixy>0</ixy>
          <ixz>0</ixz>
          <iyz>0</iyz>
        </inertia>
      </inertial>
      <collision name="collision_motor_p_p_p">
        <geometry><sphere><radius>0.3</radius></sphere></geometry>
      </collision>
      <visual name="visual_motor_p_p_p">
        <geometry><sphere><radius>0.3</radius></sphere></geometry>
        <material><diffuse>1 0 0 1</diffuse></material>
      </visual>
      <visual name="marker_motor_p_p_p">
        <pose>0.4 0 0 0 0 0</pose>
        <geometry><box><size>0.2 0.05 0.05</size></box></geometry>
        <material><diffuse>0 1 0 1</diffuse></material>
      </visual>
    </link>

    <!-- Plugin -->
    <plugin name="subpar::SubparDronePlugin"
            filename="/workspaces/TI-S4-Subpar/subpar/simulator/build/libSubparDronePlugin.so"/>
  </model>
</sdf>