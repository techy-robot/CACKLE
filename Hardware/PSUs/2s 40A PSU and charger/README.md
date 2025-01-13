---
modified: 2025-01-12T19:11:32-07:00
---

# 2s 40A PSU and charger

This is a rather complex power supply unit. It supports USB-C Power Delivery at 9volt 2 amps, and can charge a 2 cell lipo battery. It can pump out 40 amps if the battery supports the current. It also had battery protection and balancing built in, and a RS485 communication unit that can translate USB or SPI data to RS485.

The outer copper is 2oz, and the inner is 0.5 oz. Additional metal is needed to support the full current.

The main ICs on board are the TI BQ24780S battery charger, TI BQ76905 battery balancer and monitor, and a CH32X035G8U6 mcu. The system can theoretically handle 20 volt spikes, but the battery and all down line items could become damaged. I think there is also some 16v capacitors on the power lines that would be damaged. This is really meant for 9v usb-c charging to an 8.4v max lipo.

There are 2 plated through hole pads for the main battery wires, and a JST XH 3-pin connector for the balance plug in the common pin arrangement for Turnigy batteries.

The MCU has several purposes:
- Manage USB-C PD negotiations over the CC pins (built in PHY)
- Interact with the battery charger to keep it alive and change settings for charge profiles and curves
- Trigger battery balancing
- Report battery sensor data over the bus
- Act as a host adapter to convert USB or SPI data to rs485 bus commands and back. Helpful for debugging the system via a laptop, or if your main compute board needs to control the motors and sensors and doesn't have RS485 built in.

![Schematic PDF](2s%2040A%20PSU%20and%20charger.pdf)

Partial 3D image, some connectors missing:
![2s 40a PSU 3D picture](media/2s%2040a%20PSU%203D%20picture.png)