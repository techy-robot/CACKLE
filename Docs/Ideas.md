---
aliases:
tags:
append_modified_update: true
modified:
  - 2025-06-06T20:38:58-06:00
  - 2025-09-09T16:25:11-06:00
---

# New Module Types
- A compute board would be nice, I'm thinking it would be a 45mm x45mm SBC with connectors to pass power and signals through
- Various "passive" board types, like power hubs, horizontal or vertical spacers where you want empty space, and blank driver and sensor boards where all the signals are exposed for easier prototyping and soldering.
- I also have an idea for sensor array's, which are on the opposite ends of a PSU. They measure 15x45 and exist for advanced sensors such as cameras, LIDAR, or anything really that doesn't fit in the normal 10mmx15mm sensor package.
- Jumbo sized modules, that are 30x30. This is for really complex items that need highpower and more surface area, like a mosfet or relay.
- Isolators for power and signals that prevent interferance
- Translators, for rs485 to canbus or usb or whatever.
- 1 sided PSUs and PSUs with no driver output

# New Modules
- DRV8850 motor driver, a high current (5-8amps), low voltage (5v) H-bridge driver. Needs 4 control pins

# Other ideas
- Move from 3pwm outputs to 4 pwm outputs for each port on the hubs, in-case you wanted to have a manual h-bridge a dual motor controller, or a stepper driver that didn't have step/dir control.
- Shrink the base unit from 15mm squared to 10mm squared.
- Power Bypass connection ecosystem, a bunch of thick wires and jumpers between boards instead of board to board. This should be for highvoltage or high currant applications


# Changelog:
- 2025-06-06 Created

See also:
```dataview
LIST
FROM outgoing([[]])
```