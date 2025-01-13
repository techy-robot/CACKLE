---
modified: 2025-01-12T19:09:42-07:00
---

# DRV8213 brushed Motor Driver

This is a single motor driver based on the DRV8213RTER Texas Instruments chip. It is capable of 4 amps current in a voltage range of 1.65 to 11 volts. This is basically a 2-pin H-bridge driver with integrated protection logic. Driving one pin with PWM will cause the motor to go in one direction, driving both pins will cause braking, and disabling both pins will enable coasting.

The chip has one current sense output, which is tied to both ADC pins A and B on the driver module. Pin C of the ADC pins is tied to FAULT, which is pulled low on triggering.  Motor control inputs are on Pins A and B, and the motor output is through a JST PH (2mm Pitch) 2-pin connector which matches the same pin order as the input. The JST-PH connector is 5mm high and is positioned near the center of the board.

The module is a 4-layer PCB with additional exposed traces for the power and ground to add solder for more current carrying capability. I designed it to carry 10 amps with 1 oz outer copper and 0.5oz inner copper, which can be increased to 20 amps current by adding solder. This was the cheapest method to go with, since 2 oz copper would add an additional 30$ per 5 boards. 

![Schematic PDF](DRV8213%20brushed%20Motor%20Driver.pdf)

3D model:
![](media/DRV8213%203D%20model%20picture.jpg)