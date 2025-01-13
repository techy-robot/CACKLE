---
modified: 2025-01-12T16:18:18-07:00
---

# ESP32-S3 Hub

This is a 4-driver hub based on the Espressif ESP32-S3FH4 chip. It has two cores powerful running at 240 mhz, and 4mb of flash memory. Other variants of the ESP32-S3 can be used as long as they have built in flash memory.

The ESP32-S3 chip does not *quite* have enough pins for driving 4 motors and several sensors, so some cuts were made. For example, on all 4 ports for the ADCs, only two out of three pins are actually connected. This will work for brushed and brushless FOC control, but it may not work for other use cases. I also had to use the USB lines for a tri-state shift register, which controls all the SPI chip select lines. I am planning on programming the chip via UART, which means that the RS485 lines must be disconnected.

The SPI bus should be able to operate at 80mhz, though this has not been tested yet. For all practical use-cases I am limiting this to 20mhz.

![Schematic PDF](ESP32-S3%20Hub.pdf)

Partial 3D picture (headers not shown)
![Esp32-s3 hub 3D picture](media/Esp32-s3%20hub%203D%20picture.png)