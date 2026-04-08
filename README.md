# Arduino Robotic Arm with Joystick Control


🚧 Status: Work in Progress


## Project Overview

This project is a 5-axis robotic arm controlled using an Arduino Uno and dual joystick inputs. The system uses a sensor shield to simplify servo connections and an ultrasonic sensor to detect distance for potential obstacle awareness.

 The goal of this project was to gain hands-on experience with:

- Microcontroller programming
- Servo motor control
- Analog sensor inputs
- Real-time hardware troubleshooting

## Hardware Used

- Arduino Uno
  
- Sensor Shield V5
  
- 5x Servo Motors
  
- 2x Analog Joysticks
  
-HC-SR04 Ultrasonic Sensor

- External battery pack
  
-Breadboard and jumper wires

-LM2596 DC-DC Buck Power Converter 

## System Architecture

Joystick inputs are read using Arduino analog pins. 
The values are mapped to servo angles and transmitted to the servo motors through the sensor shield.

## Engineering Challenges

- Servo jitter caused by insufficient power when using Arduino 5V rail
- Joystick center calibration issues
- Managing stable power distribution for multiple servos
