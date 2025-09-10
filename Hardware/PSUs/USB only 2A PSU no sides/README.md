---
modified: 2025-09-09T20:54:29-06:00
---

# USB Only PSU no sides

The main ICs are an mcu, and a 5v 2a switching regulator. The system can theoretically handle 20 volt spikes, but this is mostly meant for 5v output on one side only.

The MCU has several purposes:
- Manage USB-C PD negotiations over the CC pins (built in PHY)
- Report voltage & current sensor data over the bus
- Act as a host adapter to convert USB or SPI data to rs485 bus commands and back. Helpful for debugging the system via a laptop, or if your main compute board needs to control the motors and sensors and doesn't have RS485 built in.

The CH32X035G8U6 MCU will be swapped from to a STM32G071 x8/xB for sourcing reasons, which also implements usb pd but is a little more expensive. To get a  QFN28/32 chip with USB PD, I need the N version. My options on digikey are STM32G071GBU6N ($2.74) and STM32G071KBU6N ($2.94)


Also looking for USB C connectors on [DigiKey](https://www.digikey.com/en/products/filter/usb-dvi-hdmi-connector-assemblies/312?s=N4IgjCBcoEwOxVAYygMwIYBsDOBTANCAPZQDaIALHAJwBscFIhFMtYArDE5fBWF4Q5hqMaiAC6hAA4AXKCADKMgE4BLAHYBzEAF9CMAByIQKSBhwFiZSmAMBmauwnS5kRSo3a9IUcdPm8QhJIcgdRWgAGZxBZeSU1LV1CAFouaBMoFQBXS2DyJ3EdbzTyLOwAIwACFEkQWmNVABN5ZLAIiBd5bhkATylceXRsFCKgA).