# MechaDrake — Technical Overview

This document provides a concise technical overview of MechaDrake: objectives, hardware and software architecture, and core specifications.

## Objectives
- Build a robust, impact-resistant combat robot capable of both manual and autonomous operation.
- Implement distributed control across Arduino, ESP32, and Raspberry Pi.
- Integrate a low-latency vision pipeline for target detection and tracking.

## Core specifications
- Drive: 4WD with dual high-torque BLDC motors
- Power: 6S Li-Po (split rails for drive and logic)
- Controllers: Arduino (real-time), ESP32 (telemetry & comms), Raspberry Pi 4 (AI/vision)

