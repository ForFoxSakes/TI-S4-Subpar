# 1. Inleiding

Een simulatiesysteem voor een onderzeedrone dat door de brandweer wordt gebruikt voor trainingen en door ontwikkelaars voor firmwaretesten. De simulatie biedt een veilige en realistische virtuele omgeving waarin zowel de beweging van de drone als omgevingsfactoren zoals waterstroming, temperatuur en zichtbaarheid nauwkeurig worden nagebootst. Dit zorgt voor hoge trainingswaarde en betrouwbare testresultaten voor firmware-ontwikkelaars.  
Bronnen: Inleiding en scope uit `0. Inleiding.md` en `5. Requirement Analyse`

## 2. Systeemarchitectuur & Modules

### 2.1 Systeemarchitectuur (hoog niveau)
- **Simulatie Engine** (Gazebo)
- **Hardware Emulator** (virtuele hardware)
- **User Interface** (QT frontend)
- **Scenario Manager** (beheer scenario’s)
- **Firmware Interface** (firmware testen)
- **Logging & Analytics**
- **Security Manager**
- **Data Storage**


### 2.2 Modules (samenvatting)
| Module                   | Type         | Locatie/File                                 |
|--------------------------|--------------|-----------------------------------------------|
| Simulatie Engine         | Gazebo-plugin| `plugins/simulation_engine.cc`               |
| Hardware Emulator        | Model + plugin| `models/drone/model.sdf`, `plugins/sensors_plugin.cc` |
| Scenario Manager         | ROS-node     | `ros_nodes/scenario_manager.py`               |
| Firmware Interface       | ROS-node     | `ros_nodes/firmware_test_node.cpp`            |
| Logging & Analytics      | Backend      | `services/logger.js`, `db/log_handler.py`    |
| User Interface           | Frontend     | `frontend/`                                   |
| Security Manager         | Backend      | `services/auth.js`                            |
| Data Storage             | Database     | PostgreSQL / InfluxDB config                  |

Bron: Module Design Document【62†source】

## 3. Code & Implementatie

Hieronder een overzicht van de belangrijkste bestaande plugins en de `subscriber.cc`, inclusief hun functionaliteit.

### 3.1 GuiPlugin
**Locatie:** `simulator/plugins/GuiPlugin.cc`

- **Doel:** Basisplugin voor joint en thruster status via topics.
- **LoadConfig:** Leest XML-configuratie uit SDF.
- **Initialize & SubscribeTopics():**  
  - `/subpar/joint1/cmd` → `OnJoint1()`  
  - `/subpar/joint2/cmd` → `OnJoint2()`  
  - `/subpar/thrust/cmd`  → `OnThrust()`
- **Callbacks:**  
  - `OnJoint1()/OnJoint2()`: Verwerken hoek status en post op GUI
  - `OnThrust()`: Verwerkt thrust-status (double) en post op GUI

### 3.2 SubparDronePlugin
**Locatie:** `simulator/plugins/SubparDronePlugin.cc`

- **Doel:** Core-logica van de subpar-drone.
- **Lifecycle hooks:**  
  - `Configure()`: Ophalen joint-entities (`j1`, `j2`).  
  - `PreUpdate()`: Toepassen van `angle_j1`, `angle_j2`, en `thrustValue`:
    ```cpp
    this->model.SetJointPosition(j1, angle_j1);
    this->model.SetJointPosition(j2, angle_j2);
    this->model.SetLinkRelativeForce(thrustLink, {0, 0, thrustValue});
    ```
- **Callbacks:**  
  - `OnDirectionStringMsg(const StringMsg&)`: Verwerkt teksten als "forward", "left".  
  - `OnThrustMsg(const Double&)`: Stelt `thrustValue` in.  
  - `OnKey(const Int32&)`: Vangt key-events (pijltjestoetsen).  
- **Registratie:**
  ```cpp
  GZ_ADD_PLUGIN(subpar::SubparPublisherPlugin,
                gz::sim::System,
                gz::sim::ISystemConfigure,
                gz::sim::ISystemPreUpdate)
  ```

### 3.3 SubparStabilizerPlugin
**Locatie:** `simulator/plugins/SubparStabilizerPlugin.cc`

- **Doel:** Extra stabilisatielaag voor hover, roll, pitch.
- **Configure():** Ophalen joint-componenten.
- **PreUpdate():** Berekent en past corrigerende hoeken toe.
- **Callbacks:**
  - `OnHoverCmd(const Double&)`  
  - `OnRollCmd(const Double&)`  
  - `OnPitchCmd(const Double&)`

### 3.4 Subscriber Node
**Locatie:** `simulator/subscriber/subscriber.cc`

- **Opzet:** subscriber op sensor `/imu_data`.
- **Codevoorbeeld:**
  ```cpp
  gz::transport::Node node;
  node.Subscribe<gz::msgs::IMU>(
    "/imu_data",
    [&](const gz::msgs::IMU &msg) {
      std::cout << "AngVel Z: " << msg.angular_velocity().z()
                << ", LinAcc X: " << msg.linear_acceleration().x()
                << std::endl;
    });
  gz::transport::waitForShutdown();
  ```

> **Conclusie:** Deze plugins vormen een basis besturingssysteem: van basis gui posting (GuiPlugin) tot  dronelogica (SubparDrone) en stabilisatie (SubparStabilizer), aangevuld met real-time sensor-uitlezing via de subscriber.

## 4. Volgende stappen & planning

**Kortetermijn**:
- GUI Plugin uitwerken om status weer te geven
- Stabilisatie setup implementeren in huidige simulatie

**Langetermijn**:
- Firmware Interface implementeren (laden en debuggen).
- Scenario Manager en ROS-servicekoppelingen uitbreiden.
- Logging & Analytics integratie voltooien.
- Security Manager (authenticatie, autorisatie).
- Volledige React UI voor visualisatie en besturing.
- Backend data-opslag en rapportage genereren.

Bron: Systeem Design & Module Design documenten

## 5. Teststrategie & acceptatiecriteria

- **Functionele tests:** Scenario-executie, firmwaretesten (FT‑001 t/m FT‑003)
- **Gebruikerstesten:** UI-intuïtiviteit (UT‑001, UT‑002)
- **Prestatie-/belastingtesten:** Realtime simulatie onder belasting (PT‑001, PT‑002)
- **Veiligheidstesten:** Autorisatie en data-encryptie (VT‑001, VT‑002)

**Acceptatiecriteria:**
- ≥90% functionele tests succesvol.
- Geen kritieke bugs.
- Positieve gebruikersfeedback.

## 6. Rough klassendiagram

```plaintext
      +--------------------------+
      | GazeboSimulationEngine   |
      +--------------------------+
      | +simulateEnvironment()   |
      | +publishSensorData()     |
      +-----------+--------------+
                  |
+-----------------+----------------+
| HardwareEmulator                 |
+---------------------------------+
| +generateSensorOutput()         |
| +actuatorResponse()             |
+--------------+------------------+
               |
     +---------+----------+
     | ScenarioManager     |
     +--------------------+
     | +loadScenario()     |
     | +setParameters()    |
     +---------+----------+
               |
     +---------+----------+
     | Logging & Analytics |
     +--------------------+
     | +logSessionData()   |
     | +generateReport()   |
     +---------+----------+
               |
     +---------+----------+
     | User Interface     |
     | (React)            |
     +--------------------+
     | +visualizeDrone()  |
     | +controlDrone()    |
     +--------------------+
```  

## 7. Demonstratie

---



