# Early Flood Detection System using Flood Rate Index (FRI) and IoT

## Overview

Floods remain one of the most destructive natural disasters, causing severe damage to infrastructure, agriculture, and human life. Many regions lack early warning mechanisms, resulting in delayed responses and increased risk. This project presents a low-cost Early Flood Detection System that continuously monitors water levels and provides real-time alerts using IoT technology.

The system uses an ultrasonic sensor to measure water level variations and calculates a Flood Rate Index (FRI) to determine flood risk severity. Based on the measured values, the system categorizes flood conditions into safe, warning, and danger levels. Visual alerts using LEDs, audible alerts using a buzzer, and remote alerts through a cloud platform ensure timely notification.

This solution is designed to be inexpensive, scalable, and easy to deploy in flood-prone regions.

---

## Key Features

Real-time water level monitoring using ultrasonic sensor
Flood Risk evaluation using Flood Rate Index (FRI)
Three-stage flood warning system (Safe, Warning, Danger)
LED indicators for local visual alerts
Buzzer for audible alerts
IoT-based remote monitoring using Blynk platform
Low power consumption design
Portable and compact system
Cloud-based notification system

---

## System Architecture

The system consists of the following main components:

Ultrasonic Sensor
ESP32 Microcontroller
LED Indicators
Active Buzzer
Power Supply
Blynk Cloud Platform
Web Application Dashboard

### Working Architecture

1. Ultrasonic sensor measures water level
2. ESP32 processes sensor data
3. Flood Rate Index (FRI) is calculated
4. Water level thresholds are compared
5. LED indicators activate based on level
6. Buzzer alerts for warning/danger
7. Data sent to cloud platform
8. Notifications sent to user

---

## Components Used

| Component                 | Description                               |
| ------------------------- | ----------------------------------------- |
| ESP32                     | Main microcontroller with WiFi capability |
| HC-SR04 Ultrasonic Sensor | Measures water level                      |
| Green LED                 | Safe water level indicator                |
| Orange LED                | Warning level indicator                   |
| Red LED                   | Danger level indicator                    |
| Active Buzzer             | Audible alert system                      |
| Breadboard                | Prototype assembly                        |
| Jumper Wires              | Circuit connections                       |
| Lithium-Ion Batteries     | Power supply                              |
| Resistors                 | Circuit protection                        |
| Blynk IoT Platform        | Cloud monitoring                          |

---

## Pin Configuration

| Component          | GPIO Pin |
| ------------------ | -------- |
| Green LED          | GPIO 27  |
| Orange LED         | GPIO 26  |
| Red LED            | GPIO 25  |
| Ultrasonic Trigger | GPIO 14  |
| Ultrasonic Echo    | GPIO 12  |
| Buzzer             | GPIO 33  |

---

## Working Principle

The ultrasonic sensor sends sound waves toward the water surface. The waves reflect back to the sensor, and the ESP32 calculates the distance using time-of-flight measurement.

Distance Calculation:

Distance = (Time × Speed of Sound) / 2

When water level rises, the measured distance decreases. The ESP32 processes this data and determines the flood risk level using predefined thresholds.

The system categorizes flood conditions into:

Safe Level
Warning Level
Danger Level

Based on the category, LEDs and buzzer are activated and notifications are sent through IoT platform.

---

## Flood Rate Index (FRI)

Flood Rate Index is used to determine how quickly water levels are rising.

FRI improves prediction accuracy compared to simple threshold-based systems.

Flood conditions based on FRI:

Safe Level
FRI < 0.4

Warning Level
0.4 ≤ FRI < 0.75

Danger Level
FRI ≥ 0.75

This allows early prediction before dangerous water levels occur.

Refer FRI.md for more details about this method.

---

## Software Implementation

The system is programmed using Arduino IDE for ESP32. The software continuously reads ultrasonic sensor data and updates the outputs accordingly.

Software modules include:

Sensor Reading Logic
Threshold Comparison Logic
Flood Rate Index Calculation
LED Control Logic
Buzzer Control Logic
Blynk Notification Logic

The ESP32 connects to WiFi and sends real-time data to the cloud platform.

---

## System Flow

1. System powers on
2. ESP32 connects to WiFi
3. Ultrasonic sensor measures distance
4. Water level calculated
5. Flood Rate Index calculated
6. Threshold comparison
7. LED activation
8. Buzzer activation
9. Cloud notification
10. Repeat continuously

---

## Results and Testing

The system was tested under different water level conditions. The ultrasonic sensor successfully detected water level changes in real time. LED indicators and buzzer responded accurately to threshold levels.

The cloud platform displayed real-time water levels and alerts. Notifications were received instantly, confirming reliability of the system.

Testing confirmed:

Accurate water level detection
Fast response time
Reliable IoT communication
Stable operation

---

## Advantages

Low cost implementation
Easy deployment
Real-time monitoring
Remote notifications
Low power consumption
Compact design
Scalable architecture

---

## Limitations

Ultrasonic sensor is not waterproof
WiFi connectivity required
Limited sensing range (400 cm)

---

## Future Improvements

GSM module for SMS alerts
Solar powered system
Multiple sensor nodes
Machine learning based flood prediction
Dedicated mobile application
Advanced cloud analytics

---

## Applications

River monitoring
Dam monitoring
Drainage monitoring
Urban flood detection
Smart city infrastructure
Disaster management systems

---

## Hardware Prototype

The hardware prototype consists of ESP32, ultrasonic sensor, LEDs, and buzzer assembled on a breadboard. The system continuously monitors water levels and provides alerts.

---

## IoT Dashboard

The system uses Blynk IoT platform to display:

Water level
Flood risk level
Alerts
System status

---

## Project Structure

```
Early-Flood-Detection-System/
│
├── Paper/
│   └── Flood_Detection_System.pdf
│
├── Images/
│   ├── Architecture.png
│   ├── Circuit.png
│   ├── Prototype.png
│
├── Code/
│   └── ESP32_Flood_System.ino
│
└── README.md
```

---

## Authors

Srishaanth Raman S.M
B.Tech Computer Science and Engineering (IoT)
Jain University, Bengaluru

D.S. Nandhushri
B.Tech Computer Science and Engineering (Data Science)
Jain University, Bengaluru

Sai Shreyas K.S
B.Tech Computer Science and Engineering (IoT)
Jain University, Bengaluru

Shivarchan C
B.Tech Computer Science and Engineering (Data Science)
Jain University, Bengaluru

Vishnu Siddharth
B.Tech Computer Science and Engineering (IoT)
Jain University, Bengaluru

---

## License

This project is released for academic and research purposes.

---

## Zenodo DOI
 The DOI link is as given below
     https://doi.org/10.5281/zenodo.19474429

---     

## Citation

If you use this work, please cite:

Early Flood Detection System using Flood Rate Index and IoT
Srishaanth Raman S.M et al.

---

## Contact

For queries or collaborations:

Srishaanth Raman S.M
Email: [srishaanth210106@gmail.com](mailto:srishaanth210106@gmail.com)
