---
aliases:
tags:
modified:
  - 2025-06-06T20:38:58-06:00
  - 2025-09-09T16:25:11-06:00
  - 2025-11-08T11:31:44-07:00
---

# New Module Types
- A compute board would be nice, I'm thinking it would be a 45mm x45mm SBC with connectors to pass power and signals through
- I also have an idea for sensor array's, which are on the opposite ends of a PSU. They measure 15x45 and exist for advanced sensors such as cameras, LIDAR, or anything really that doesn't fit in the normal expansion board form factor
- Jumbo sized driver modules that are 30x30. This is for really complex items that need highpower and more surface area, like a mosfet or relay.
- Isolators for power and signals that prevent interference
- Translators, for rs485 to canbus or usb or whatever.

# New Modules

## Drivers
- DRV8850 motor driver, a high current (5-8amps), low voltage (5v) H-bridge driver. Needs 4 control pins
- DRV8231A HV brushed Motor Driver
- TMC2130 Stepper Drivers

## Passives
- Power hub passive board, 4 spoke design
- Horizontal board spacer
- Blank driver board with through holes for prototyping

# Other ideas
- Shrink the base unit from 15mm squared to 10mm squared.
- Power Bypass connection ecosystem, a bunch of thick wires and jumpers between boards instead of board to board. This should be for highvoltage or high currant applications


# Changelog:
- 2025-06-06 Created
- 2025-11-08 Updated ideas list to remove already implemented ideas

See also:
```dataview
LIST
FROM outgoing([[]])
```