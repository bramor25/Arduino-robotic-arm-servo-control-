# Arduino Robotic Arm with Joystick and Ultrasonic Control

🚧 Status: Functional Prototype Completed – Ongoing Improvements

## Overview
This project is a 5-axis robotic arm controlled using an Arduino Uno with both manual joystick input and automated ultrasonic sensing. The system demonstrates real-time control of servo motors, sensor-based decision making, and embedded system integration.

This project was built to strengthen hands-on skills in embedded systems, actuator control, sensor integration, and hardware debugging.

---

## Features
- 5-DOF robotic arm controlled with servo motors  
- Dual joystick input for manual control  
- Ultrasonic sensor for object detection  
- Automated pick-and-place sequence based on distance  
- Real-time response to analog and digital inputs  
- External power integration for stable servo operation  

---

## Hardware Used
- Arduino Uno (Elegoo R3)  
- Sensor Shield V5  
- 5x Servo Motors  
- 2x Analog Joysticks  
- HC-SR04 Ultrasonic Sensor  
- External Battery Pack  
- Breadboard and jumper wires  

---

## Pin Connections
### Servos
- Servo 1 (Base): Pin 9  
- Servo 2 (Shoulder): Pin 6  
- Servo 3 (Elbow): Pin 5  
- Servo 4 (Wrist): Pin 3  
- Servo 5 (Claw): Pin 11  

### Joystick
- Joystick X: A1  
- Joystick Y: A0  
- Joystick Button: Pin 7  

### Ultrasonic Sensor
- Trig Pin: 2  
- Echo Pin: 4  

---

## Code Structure
- `code/joystick_control.ino`  
  Handles real-time joystick input and maps analog values to servo movement  

- `code/ultrasonic_pick_and_place.ino`  
  Uses HC-SR04 distance measurements to trigger automated servo movement sequences for object pickup and release  

---

## Challenges and Fixes
- **Servo jitter issue**  
  - Cause: insufficient power from Arduino USB  
  - Fix: added external battery pack for stable operation  

- **False joystick movement**  
  - Cause: floating analog inputs when not connected  
  - Fix: proper wiring and threshold tuning  

- **Button input conflict**  
  - Cause: initial use of pin 0 (RX pin) interfered with serial communication  
  - Fix: reassigned to a dedicated digital input pin  

- **Unstable distance triggering**  
  - Cause: ultrasonic sensor readings fluctuate slightly  
  - Fix: adjusted thresholds and timing delays for more consistent detection  

---

## How It Works
### Manual Mode
- Joystick inputs are read using `analogRead()`  
- Threshold logic determines movement direction  
- Commands are mapped to servo positions  

### Automatic Mode
- Ultrasonic sensor measures distance to object  
- When object is within a set threshold, a pick-and-place sequence is triggered  
- Predefined servo movements control grabbing and placement  

---

## System Diagram
![Block Diagram](images/block_diagram.png)



## Future Improvements
- Custom PCB design using KiCad  
- Fully 3D-printed robotic arm structure  
- Improved motion control (inverse kinematics)  
- Wireless control (Bluetooth or WiFi integration)  
- Mode switching between manual and automatic control  

---
