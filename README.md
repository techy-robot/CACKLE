---
modified: 2025-01-01T19:31:14-07:00
---
# CACKLE - Card Adaptable Controller Kinetic Link Electronics
This is designed to be a super small, open source, adaptable control board. Each module is arranged in units of 1.5cm squared, but can handle high power micro robotic actuators, such as my [Mighty-Micro-Motors](https://github.com/techy-robot/Mighty-Micro-Motors). Ideally this board can be reused and rebuilt for all sorts of small robots.

You can read up on specific modules in their respective folders in Hardware, or take a look at the overall architecture

# Architecture
There are currently 6 types of sub-boards:
- Hubs (with an MCU on it, supports 2 or 4 drivers, 2 expansion cards, and a chain of peers)
- PSUs (typically only one board)
- Expansion Cards (vertical mezzenine connector boards for breaking out sensors and other interfaces)
- Drivers (Any high power driver)
- nanoSPI devices (Small 7-pin flex cable SPI devices, mostly for sensors)
- Passives (spacers, end caps, etc...)

The base unit for this project is 1.5 cm squared. The expansion cards and drivers should each be 1 unit, the Hubs 1x1 or 1x2, and the PSUs 3x1 units. With a 12 motor board with PSU for example, the board would be 45x105mm. nanoSPI devices can be much smaller due to the flex cable, such as a 5mm diameter tip and 2.4mm wide cable.

Unfortunately I was unable to create a 45x15mm PSU for the first version, it had to be extended up by 5mm to fit the high current circuitry.

My initial idea was to have spring contacts to allow easy clip in clip out, but finding no connectors quite what I wanted and unable to manufacture my own, I went with 1.27mm pitch pin headers and micro Keystone edge board connectors for power.

Original (bit outdated) sketch of the architecture:
![Cackle Design Outline](media/CACKLE%20Design%20Outline.jpg)

3D model demo:
![CACKLE 3D model demo](CACKLE%203D%20model%20demo.png)

# Goals
- Adaptable 
- Small
- Extendable by other developers
- Easy to use
- Powerful

# Features
## Required:
- Small modules
- Hubs with an mcu that can talk to its peers and a master
- Motor driver boards that can handle several amps
- Sensor ports with protocols like i2c and SPI
- Extendable architecture
- PSUs
- LED status lights

## Nice to Have
- Distributed computing with a multi-master network
- Easy automatic hardware configuration
- Ability to stack hubs vertically using the Expansion Card system, in addition to horizontal chaining.

# A Note on Project Management
This project is managed transparently in this very repo. I am using Obsidian.md as my notetaking, documentation, and project management tool. A lot of the markdown files you will see in this repo might look a bit weird; that is due to the Wiki-links instead of markdown links and the YAML file front-matter that Obsidian supports. My system works well for one person, but I'm not sure how future proof this system is. You can find my sample vault here, which explains more: [GitHub - techy-robot/Project-Management-Obsidian-Sample-Vault](https://github.com/techy-robot/Project-Management-Obsidian-Sample-Vault). 
