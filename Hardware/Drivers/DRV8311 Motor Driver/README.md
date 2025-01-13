---
modified: 2025-01-12T19:10:09-07:00
---

# DRV8311 Motor Driver

This is a single brushless motor driver based on the DRV8311 Texas Instruments chip. It is capable of 5 amps current in a voltage range of 3 to 24 volts. It has integrated current sense amplifiers and protection logic. It supports up to 200khz PWM frequency.

The chip has 3 current sense outputs, tied to all three ADC pins. The motor output is through a Molex Picoblade (1.25mm pitch) 3-pin connector.

The module is a 4-layer PCB with additional exposed traces for the power and ground to add solder for more current carrying capability. I designed it to carry 10 amps with 1 oz outer copper and 0.5oz inner copper, which can be increased to 20 amps current by adding solder. This was the cheapest method to go with, since 2 oz copper would add an additional 30$ per 5 boards. 

![Schematic PDF](DRV8311%20Motor%20Driver.pdf)

3D model
![](media/DRV8311%203D%20model%20picture.jpg)