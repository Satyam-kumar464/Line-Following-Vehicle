# CAD-Designed Line Following Vehicle

**FDP Project — 2025**

A CAD-designed autonomous line-following vehicle integrating mechanical design, PCB design, Arduino-based control, IR sensors and DC motors.

<img width="350" height="207" alt="image" src="https://github.com/user-attachments/assets/3e86dcd7-7207-4237-bdc5-c39ade354606" />


---

## Project Overview

This project was developed as an FDP project in 2025.

The objective was to design and develop a compact line-following vehicle capable of detecting and following a predefined path using infrared sensors.

The project combines:

- Mechanical CAD design
- PCB design
- Arduino-based control
- IR sensor interfacing
- DC motor control
- Mechanical-electrical integration
- Physical prototype testing

---

# System Architecture

The overall system can be represented as:

```text
             IR Sensors
                  |
                  v
             Arduino UNO
                  |
                  v
            Motor Driver
                  |
          +-------+-------+
          |               |
          v               v
      Left Motor      Right Motor
          |               |
          +-------+-------+
                  |
                  v
              Vehicle
