---
modified: 2024-09-16T21:15:43-06:00
---
# CACKLE - Card Adaptable Controller Kinetic Link Electronics
This is designed to be a super small, open source, adaptable control board. Each module is no bigger than 15mm squared (one unit in this project), but can handle high power micro robotic actuators, such as my [Mighty-Micro-Motors](https://github.com/techy-robot/Mighty-Micro-Motors). Ideally this board can be reused and rebuilt for all sorts of small robots.

# Architecture
There are 4 main types of subboard units:
- Hubs (with an MCU on it, supports 4 drivers, one sensor with a vertical micro connector, and a chain of peers)
- PSUs (typically only one board)
- Modules/ Sensors (vertical mezzenine connector boards for sensors)
- Drivers (Any high power motor driver, plus a SPI bus for feedback sensors)

The base unit for this project is 1.5 cm squared, though there is a slight possibility that this can be 15x10mm instead. The modules and drivers should each be 1 unit, while the Hubs are 1x2 units. With a 12 motor board for example, the board would be 45x90mm.

Ideally I will have spring contacts for all the modules, and you can just clip them in. 

