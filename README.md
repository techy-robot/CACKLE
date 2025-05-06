---
modified: 2025-05-05T23:28:19-07:00
---
# CACKLE - Card Adaptable Controller Kinetic Link Electronics
![](media/sideview%20RL%20with%20arrows.jpg)

This is designed to be a super small, open source, adaptable control board. Each module is arranged in units of 1.5cm squared, but can handle high power micro robotic actuators, such as my [Mighty-Micro-Motors](https://github.com/techy-robot/Mighty-Micro-Motors). Ideally this board can be reused and rebuilt for all sorts of small robots.

You can read up on specific modules in their respective folders in Hardware, or take a look at the overall architecture

Real Life pictures:
![](media/front%20view%20PSU%20macro%20RL.jpg)
![](media/front%20view%20macro%20RL.jpg)
![](media/overview%20RL.jpg)

3D model demo:
![CACKLE 3D model demo](media/CACKLE%203D%20model%20demo.png)

# Architecture
There are currently 6 types of sub-boards:
- Hubs (with a MCU on it, supports 2 or 4 drivers, 2 expansion cards, and a chain of peers)
- PSUs (typically only one board)
- Expansion Cards (vertical mezzanine connector boards for breaking out sensors and other interfaces)
- Drivers (Any high power driver)
- nanoSPI devices (Small 7-pin flex cable SPI devices, mostly for sensors)
- Passives (spacers, end caps, etc...)

The base unit for this project is 1.5 cm squared. The expansion cards and drivers should each be 1 unit, the Hubs 1x1 or 1x2, and the PSUs 3x1 units. For example, with a 12 motor board you would need 1 PSU, 3 1-by-2 hubs, and 12 drivers; the board would be 45x105mm. nanoSPI devices can be much smaller due to the  2.4mm wide flex cable, such as a 5mm diameter magnetic encoder.

Unfortunately I was unable to create a 45x15mm PSU for the first version, it had to be extended up by 5mm to fit the high current circuitry.

My initial idea was to have spring contacts to allow easy clip in clip out, but finding no connectors quite what I wanted and unable to manufacture my own, I went with 1.27mm pitch pin headers and micro Keystone edge board connectors for power.

Original (bit outdated) sketch of the architecture:
![Cackle Design Outline](media/CACKLE%20Design%20Outline.jpg)

# Goals
- Adaptable 
- Small
- Extendable by other developers
- Easy to use
- Powerful

# Features
## Required:
- Super Small modules
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


# Software
As of now software is very limited in scope, I have not had the time to fully assembly and test the boards I have made. I am planning on using SimpleFOC and Luos Engine. SimpleFOC is a motor driver library for Field Oreinted Control for motors. Luos Engine is a lightweight-distributed communication engine that aims to make hardware as modular as software. Combined, I have covered 50% of the use-cases of the code necessary for this project.

See [Software](Software/README.md) for more.

# Contributing
Feal free to contribute in any way possible! This is an open-source project, and with so many modules yet to be explored, I encourage you to help test boards, create modules or code, or ask about the project!

- GitHub Discussions: Participate in discussions on GitHub to share your experiences and ask questions.
- Contribute: Help develop the project, create PRs with new features or modules
- Report: Open issues, give me feedback!

Read the Architecture notes and [CONTRIBUTING.md](CONTRIBUTING.md) for more in-depth on this.

# A Note on Project Management
This project is managed transparently in this very repo. I am using Obsidian.md as my notetaking, documentation, and project management tool. A lot of the markdown files you will see in this repo might look a bit weird; that is due to the Wiki-links instead of markdown links and the YAML file front-matter that Obsidian supports. My system works well for one person, but I'm not sure how future proof this system is. You can find my sample vault here, which explains more: [GitHub - techy-robot/Project-Management-Obsidian-Sample-Vault](https://github.com/techy-robot/Project-Management-Obsidian-Sample-Vault). 
