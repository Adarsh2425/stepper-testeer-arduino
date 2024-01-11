# Stepper Motor Testing Project

## Overview

This project involves testing a stepper motor using an Arduino Nano and the AccelStepper library. The stepper motor is controlled with different microstepping settings to observe its behavior and performance.

## Features

- **Microstepping Test:** Evaluate the stepper motor's performance with various microstepping settings (1, 2, 4, 8, 16).
- **Customizable Waveforms:** Experiment with different waveforms for each microstepping setting to observe motion characteristics.
- **Simple and Clean Code:** The code is well-documented and easy to understand, making it a suitable starting point for stepper motor projects.

## Hardware Requirements

- Arduino Nano
- Stepper Motor
- Stepper Motor Driver (e.g., A4988)
- Jumper Wires

## Setup

### Stepper Motor Driver Connections

- Connect the `STEP` pin of the stepper motor driver to pin `2` on the Arduino Nano.
- Connect the `DIR` pin of the stepper motor driver to pin `3` on the Arduino Nano.
- Connect the `ENABLE` pin of the stepper motor driver to pin `8` on the Arduino Nano.

### Microstepping Pins

- Connect the microstepping pins (`microstepPin1`, `microstepPin2`, `microstepPin3`) of the stepper motor driver to the corresponding pins (`9`, `10`, `11`) on the Arduino Nano.

### Power Supply

- Connect the power supply to the stepper motor driver and ensure it is suitable for your stepper motor specifications.

### Stepper Motor Connections

- Connect the stepper motor to the stepper motor driver's output.

## How to Use

1. Open the Arduino IDE and upload the sketch to the Arduino Nano.
2. Observe the serial monitor for testing results.
3. Experiment with different microstepping settings by adjusting the `setMicrostep` function in the code.
4. Customize waveform functions (`setSinusoidalWaveform` and `setTrapezoidalWaveform`) for specific microstepping settings.

## Customization

Feel free to customize the code for your specific stepper motor, driver, and application needs. Adjust parameters such as `setMaxSpeed` and `setAcceleration` based on your motor specifications.

## Author

[Adarsh Gajula]
