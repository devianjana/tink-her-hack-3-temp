# Advanced Robot Cleaner

## Introduction
I plan to build a robot that can identify obstacles that ultrasonic sensors can't detect, making the robot more futuristic and efficient.

## Project Developer
**Devi Anjana Anoop S**

## Project Type
**Hardware Project**

## Project Description
This is a fully functional robot designed to navigate through shelves without getting stuck. Additionally, it will identify and clean areas under shelves where traditional robot cleaners fail to reach.

## Problem Statement
I own a robot cleaner at home, but due to the presence of multiple shelves, it often gets stuck between gaps and requires human intervention to move.

## How I Solved This Issue
To overcome this problem, I implemented a solution that integrates additional sensors and mechanical components for enhanced obstacle detection and cleaning.

### Technology Used
- **Arduino IDE** (Version 2.3.4) for programming and testing

### Components Used
- **Gear Motors** (x2)
- **Lithium-Ion Batteries**
- **Arduino Uno Rev3**
- **Motor Driver (L298N)**
- **Ultrasonic Sensor**
- **Servo Motors** (x2)
- **Limit Switches** (x2)
- **Jumper Wires**
- **Breadboard**
- **Cardboard** (for body structure)

## Solution
The Arduino Uno is responsible for controlling all the components:
- **Ultrasonic Sensor:** Used to detect obstacles ahead.
- **Limit Switches:** Placed at the front to detect low obstacles and shelves.
- **Servo Motors:** Activated when a shelf is detected, allowing the robot to clean the area underneath.
- **Pushbutton Switch:** Helps detect corner obstacles where ultrasonic sensors may fail. When triggered, the robot moves back and engages the servos to clean the under-area.

### Circuit Diagram
A detailed circuit diagram with added servo motors and limit switches is provided in the repository.

## Project Status
- **Building Stage**: Currently assembling and testing the robot for real-world functionality.

## Program Output
The robot follows the programmed logic to detect obstacles, back up when necessary, and clean under shelves using servo-driven brooms.

## Video Explanation
A video demonstration is available showing how the code is uploaded to the Arduino via a laptop, and how the robot efficiently performs its cleaning task using servo motors and limit switches.

---

### Future Enhancements
- Adding AI-based obstacle recognition.
- Improving battery efficiency.
- Integrating better material for durability.

### Contributions
Feel free to contribute to this project by submitting pull requests or reporting issues.

### License
This project is open-source and available under the **MIT License**.

---

### Contact
For any queries or suggestions, reach out to **devianjanaanoop9a@gmail.com**.

---

