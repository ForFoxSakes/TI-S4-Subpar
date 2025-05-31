# Subpar 🐠

Een onderzeeërsimulator in Gazebo, gecombineerd met documentatie, verslagen en analyses voor het TI-S4 project.

## 🧭 Inhoud

- `simulator/`: Submarine sim met Gazebo wereld(en), modellen en code
- `docs/`: Markdown-bestanden, verslagen, reflecties en bronnen
- `.devcontainer/`: Containeromgeving om alles makkelijk te draaien in VS Code

## 🚀 DevContainer gebruiken

1. Open repo in Visual Studio Code
2. Kies “Reopen in Container”
3. Voor Gazebo simulatie:
   - Voer op je host uit: `xhost +local:`
   - Start simulatie in container via launch script of `gazebo worlds/onderzeewereld.world`
4. Voor documentatie en notebooks:
   - Navigeer naar `docs/`
   - Start Jupyter: `jupyter lab`

## 🤿 Waarom Subpar?

Het is een ironische verwijzing naar onder water én een subtiele sneer naar de prestaties van de simulator 😄
