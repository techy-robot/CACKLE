---
aliases: 
tags: 
append_modified_update: true
modified:
  - 2024-08-09T20:39:57-06:00
  - 2024-08-11T20:12:22-06:00
  - 2024-09-07T17:55:38-06:00
  - 2024-09-08T09:46:12-06:00
  - 2024-09-16T21:17:40-06:00
  - 2024-09-23T18:45:05-06:00
  - 2024-10-19T17:45:06-06:00
  - 2024-11-06T17:24:05-07:00
---
It is a modular control board design, with 4 main types of units:
- Hubs (with an MCU on it, supports 4 drivers, one sensor with a vertical micro connector, and a chain of peers)
- PSUs (typically only one board)
- Modules/ Sensors (vertical mezzenine connector boards for sensors)
- Drivers (Any high power motor driver, plus a SPI bus for feedback sensors)

The base unit for this project is 1.5 cm squared. The modules and drivers should each be 15x15mm, while the Hubs are 15x30mm. There is a slight possibility it can be 15x10mm instead.

With a 12 motor board that would be 45x90mm

The PSU and any extra peripheral such as speakers will have to be off-board and crammed somewhere else, though small sensors can be mounted vertically on the connectors. If the Battery charger is too difficult to cram in the provided space, I could move the battery charger off the board and have the battery protector in the robot only.

My idea is to use some highspeed dual core MCUs for the hubs, something like the ESP32-s3. The esp32-s3 is low on pins, therefore I will have to use some tricks such as disabling USB, programming over the sensor SPI bus, and using a multiplexor or shift register for SPI chip select. Depending on the chosen inter-hub protocol I may have a few more pins.

Ideally I will have spring contacts for all the modules, and you can just clip them in. But I will have to custom manufacture these board springs that clip into through holes, because I haven't found any commercially available ones. Alternately I can use some Keystone micro SMD tab pins.

3.3v should be supplied to the Drivers, in case I wanted to plug in a bigger or power hungry sensor board, or if I have a driver chip that doesn't have a built in regulator.

The numbering scheme between hubs is bottom up, with the PSU at the very bottom, and hubs connected on top of that. All the sensor and motor ports per hub follow this numbering scheme as well.

I also have ideas to expand the architecture of CACKLE, including adding new modules types. A compute board would be a good idea, which is a 45mm x45mm SBC with connections to pass through power and signals. I also have ideas for various "passive" board types, like power hubs, horizontal or vertical spacers where you want empty space, and blank driver and sensor boards where all the signals are exposed for easier prototyping and soldering. I also have an idea for sensor array's, which are on the opposite ends of a PSU. They measure 15x45 and exist for advanced sensors such as cameras, LIDAR, or anything really that doesn't fit in the normal 10mmx15mm sensor package.



# Changelog:
- 2024-08-09 Created

See also:
```dataview
LIST
FROM outgoing([[]])
```