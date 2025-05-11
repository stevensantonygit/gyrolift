# GyroLift: Active Gyroscopic Stabilization System for High-Altitude Payloads

**GyroLift** is an experimental project that aims to stabilize a high-altitude balloon payload using an active gyroscopic mechanism controlled by an ESP32 microcontroller. The goal is to counteract pitch, roll, and yaw in real-time using rotating aluminum disks powered by DC motors.

>**Hypothesis**: If we place a glass of water filled to the brim inside the payload, the gyroscopic stabilization system will prevent the water from spilling—even at high altitudes and under turbulence.

---

## Project Overview

Traditional passive stabilization techniques often fall short under rapid or unexpected motion. In **GyroLift**, we actively stabilize the system using:

- **Three-axis DC motor-controlled aluminum disks**: Mimicking the behavior of a reaction wheel or gyroscope, each axis counters motion using angular momentum.
- **Real-time motion sensing**: With M5Stack's built-in IMU sensors to track acceleration and orientation changes.
- **Custom control logic via ESP32**: Commands are sent to the motors based on sensor data to actively resist changes in orientation.

---

## Hardware Used

| Component            | Purpose                                                 |
|---------------------|---------------------------------------------------------|
| ESP32               | Central microcontroller to read sensor data and control motors |
| M5StickC PLUS2      | Provides built-in IMU (gyro + accelerometer)            |
| M5Stack IMU Module  | Additional 9-axis motion tracking (gyroscope + accelerometer) |
| DC Motors (x3)      | Spin aluminum disks to counteract pitch, roll, and yaw  |
| Aluminum Disks (x3) | Provide angular momentum for stabilization              |
| Carbon Fiber Box    | Lightweight and rigid payload housing                   |

---

## How It Works

1. **Orientation Sensing**: The M5StickC PLUS2's IMU detects changes in pitch, roll, and yaw.
2. **Processing**: The ESP32 reads these values and determines which motors need to spin and in what direction.
3. **Gyroscopic Stabilization**: Aluminum disks spin on each axis, generating angular momentum to counteract external forces.
4. **Feedback Loop**: The system continuously updates and corrects orientation in real-time.

---

## Testing Methodology

To test the efficiency of the stabilization system:
- A **glass of water** is placed inside the payload.
- The payload is subjected to sudden or random movement.
- The system's ability to prevent water from spilling will serve as a **visual indicator of stabilization success**.
- PID tuning for more responsive control.
- Data logging and visualization via SD card or WiFi.
- Thermal management for high-altitude use.
- Integration with GPS for real-time positioning.

---

## 📁 Repository

Find all source code, circuit schematics, and logs in this repository:  
🔗 **[https://github.com/stevensantonygit/gyrolift](https://github.com/stevensantonygit/gyrolift)**

---

## 🧑‍💻 Authors

- **Stevens and Johann**  
- **[stevensantonygit](https://github.com/stevensantonygit)**
- **[JohannJosephAntony](https://github.com/JohannJosephAntony)**

Feel free to fork, contribute, or reach out with ideas!

---

## 📸 Media & Demo

Coming soon! Stay tuned for demo videos and flight logs.

