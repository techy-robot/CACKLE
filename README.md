---
modified: 2024-09-23T19:20:53-06:00
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
Sketch of the architecture:
![Cackle Design Outline](media/CACKLE%20Design%20Outline.jpg)

# Goals
- Adaptable 
- Small size
- Extendable by other developers
- Fun and easy to use
- Powerful

# Features
## Required:
- Small modules
- Hubs with an mcu that can talk to its peers and a master
- Motor driver boards that can handle several amps
- Sensor ports with protocols like i2c and SPI
- Extendable architecture

## Nice to Have
- PSUs
- LED status lights
- Distributed computing with a multi-master network
- Easy automatic hardware configuration
- Vertical control board stacking in addition to horizontal expansion.

# A Note on Project Management
This project is managed transparently in this very repo. I am using Obsidian.md as my notetaking, documentation, and project management tool. A lot of the markdown files you will see in this repo might look a bit weird; that is due to the Wiki-links instead of markdown links and the YAML file front-matter that Obsidian supports. My system works well for one person, but I'm not sure how future proof this system is. You can find my sample vault here, which explains more: [GitHub - techy-robot/Project-Management-Obsidian-Sample-Vault](https://github.com/techy-robot/Project-Management-Obsidian-Sample-Vault). 
