# Arduino Robotic Arm with Joystick Control

🚧 Status: Functional Prototype Completed – Ongoing Improvements

## Overview
This project is a 5-axis robotic arm controlled using an Arduino Uno and dual joystick inputs. The system enables real-time manual control of multiple servo motors and demonstrates core embedded systems concepts including analog input processing, actuator control, and hardware debugging.

This project was built to strengthen hands-on skills in embedded systems, servo motor control, and real-time hardware interaction.

---

## Features
- 5-DOF robotic arm controlled with servo motors  
- Dual joystick input for directional control  
- Real-time response to analog inputs  
- Button-triggered actions (grip control / reset)  
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
- Servo 1 (Base): Pin 9  
- Servo 2 (Shoulder): Pin 6  
- Servo 3 (Middle): Pin 5  
- Servo 4 (Wrist): Pin 3  
- Servo 5 (Claw): Pin 11  

- Joystick 1 X: A1  
- Joystick 1 Y: A0  
- Joystick 1 Button: Pin 7  

- Joystick 2 X: A3  
- Joystick 2 Y: A4  
- Joystick 2 Button: Pin 12  

---

## Code Structure
- `code/joystick_control.ino` – Handles joystick input processing and maps commands to servo movement  

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

---

## How It Works
- Joystick inputs are read using `analogRead()`  
- Threshold logic determines movement direction  
- Commands are mapped to servo positions  
- Button inputs trigger additional actions such as grip control  

---

## Future Improvements
- Custom PCB design using KiCad  
- Fully 3D-printed robotic arm structure  
- Improved motion control (inverse kinematics)  
- Wireless control (Bluetooth or WiFi integration)  

---
