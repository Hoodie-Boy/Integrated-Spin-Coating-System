# Integrated Spin Coating System

An Arduino-based integrated spin coating system designed to combine rotational speed control, optical feedback, light intensity measurement, and programmable thermal control into a unified platform with a TFT touchscreen interface.

## Project Overview

The system is being developed as an integrated platform for spin coating applications. The project consists of several independently developed control and measurement subsystems that will be combined into a single embedded system.

### Main Subsystems

1. **Motor Speed Control**

   * DC motor
   * PID-based speed control
   * Optical sensor for rotational feedback
   * Motor driver
   * Direction control

2. **Light Intensity Measurement**

   * Light intensity sensor
   * Arduino-based data acquisition
   * Lux measurement and monitoring

3. **Thermal Control**

   * Temperature sensor
   * PID temperature control
   * Heater control
   * Cooling fan control
   * Programmable heating and cooling cycles

4. **User Interface**

   * 3.5-inch TFT touchscreen
   * Real-time system monitoring
   * Parameter configuration
   * Motor, temperature, and light-intensity display

## System Architecture

The final system will integrate the three control subsystems into a single Arduino-based control platform.

```text
                    ┌─────────────────────┐
                    │   3.5" TFT Touch    │
                    │      Interface      │
                    └──────────┬──────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │       Arduino       │
                    │   Main Controller   │
                    └──────────┬──────────┘
                               │
             ┌─────────────────┼─────────────────┐
             │                 │                 │
             ▼                 ▼                 ▼
      ┌─────────────┐   ┌─────────────┐   ┌─────────────┐
      │ Motor PID   │   │ Light Sensor│   │ Temperature │
      │ Controller  │   │             │   │     PID     │
      └──────┬──────┘   └─────────────┘   └──────┬──────┘
             │                                   │
             ▼                                   ▼
        DC Motor                              Heater
                                                 │
                                                 ▼
                                               Fan
```

## Development Status

| Subsystem                   | Status         |
| --------------------------- | -------------- |
| Motor PID Control           | Completed      |
| Optical Feedback            | Completed      |
| Light Intensity Measurement | Completed      |
| Temperature PID Control     | In Development |
| TFT Touchscreen Interface   | Planned        |
| System Integration          | Planned        |

## Hardware

The project is based primarily on Arduino-compatible hardware and includes:

* Arduino microcontroller
* DC motor
* Motor driver
* Optical sensor
* Light intensity sensor
* Temperature sensor
* Heater
* Cooling fan
* 3.5-inch TFT touchscreen
* Supporting power and interface circuitry

The exact hardware configuration will be documented as the system develops.

## Control System

The system uses PID control for closed-loop regulation of motor speed and temperature.

### Motor Control

The optical sensor provides rotational feedback to the controller. The measured rotational speed is compared with the desired setpoint, and the PID controller adjusts the motor drive accordingly.

### Temperature Control

The thermal subsystem uses temperature feedback to regulate the heater and cooling fan. The controller operates according to programmed temperature setpoints and timing conditions.

## Repository Structure

```text
docs/          → Technical documentation
hardware/      → Schematics, PCB, wiring and BOM
firmware/      → Arduino firmware for each subsystem
software/      → Supporting software and data logging
media/         → Project images, videos and diagrams
tests/         → Experimental and validation results
```

## Future Development

* Integrate all subsystems into one firmware
* Implement TFT touchscreen interface
* Add real-time parameter monitoring
* Add user-configurable process parameters
* Improve temperature and speed control
* Add data logging
* Develop a complete system enclosure
* Validate the integrated system experimentally

## Author

**Amir Mohammadi**

Electrical Engineering

## License

This project is released under the MIT License.
