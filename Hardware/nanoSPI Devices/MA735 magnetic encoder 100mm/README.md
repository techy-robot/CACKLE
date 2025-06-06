---
modified: 2025-05-05T16:26:33-07:00
---

# nanoSPI MA735 magnetic encoder

This is a super compact SPI magnetic encoder, with the flex cable being 2.4mm wide and 100mm long, and the tip around 5.6mm diameter. It is quite simple, and supports on shaft or side-shaft mounting with correction.

It supports a max of 25mhz bus speed, though practically speaking this is closer to 20mhz. It supports SPI mode 0 or 3, detecting automatically.

The sensor itself, MagAlpha MA735, has some quirks to it. It is variable resolution ranging from 9 to 13 bit which is inversely proportional to its speed. If you want the max measurement speed at 60k rpm, then you will have to read 9-bit angles. This is all dictated by the Filter Window setting, resolution and speed are derived from this setting.

This can be used as a template for other nanoSPI sensors, or cables.

Also, the connectors for these sensors with a 0.35mm pitch are SUPER finicky to actually solder by hand, reflow is 1000% recommended. You will burn the plastic onto a soldering iron in one swipe.

![Schematic PDF](MA735%20encoder%20board.pdf)