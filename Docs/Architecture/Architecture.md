---
aliases:
tags:
modified:
  - 2024-08-09T20:39:57-06:00
  - 2024-08-11T20:12:22-06:00
  - 2024-09-07T17:55:38-06:00
  - 2024-09-08T09:46:12-06:00
  - 2024-09-16T21:17:40-06:00
  - 2024-09-23T18:45:05-06:00
  - 2024-10-19T17:45:06-06:00
  - 2024-11-06T17:24:05-07:00
  - 2024-11-22T22:24:30-07:00
  - 2025-01-01T19:29:53-07:00
  - 2025-03-02T16:29:23-07:00
  - 2025-11-08T10:41:12-07:00
---
# Types of sub-boards
- Hubs (with an MCU on it, supports 2 or 4 drivers, 2 expansion cards, and a chain of peers)
- PSUs (typically only one board)
- Expansion Cards (vertical mezzenine connector boards for breaking out sensors and other interfaces)
- Drivers (Any high power driver)
- nanoSPI devices (Small 7-pin flex cable SPI devices, mostly for sensors)
- Passives (spacers, end caps, etc...)

# Dimensions
The base unit for this project is 1.5 cm squared. The expansion cards and drivers should each be 1 unit squared, the Hubs 1x1 or 1x2, and the PSUs 3x1 units. With a 12 motor board with PSU for example, the board would be 45x105mm. nanoSPI devices can be much smaller due to the flex cable, such as a 5mm diameter tip and 2.4mm wide cable.

Any board on the ends of the main board (PSUs or sensor arrays) can be extended beyond the 1 unit vertical limitation. For example, the V1 PSU is 20mm instead of 15mm high, meaning its 3x1 & 1/3 units.

# Communication Protocol
The Hubs communicated over a 3.3v (NOT 5v!) RS485 bus using Modbus or a derivative communication protocol. It is a multi master system.

Sensors can communicate to the hubs using I2c or SPI, and the hubs can subsequently advertise the sensor resources on the main network.

The one exception to the RS485 network is for GPU intensive modules, such as displays or cameras. Those are expected to go directly to the board requiring the resources and not to be broadcasted over the network, due to bandwidth limitations.

# MCU requirements
Highspeed 32-bit MCUs for the hubs are ideal with over 100mhz clock speed. Dual-core MCUs are nice but not required. The chips should operated on 3.3volts and not be sensitive to voltage fluctuations. 

The chips should also have DMA access or a highspeed peripherial for PWM and ADC pins, and all external driver connections must be connected directly to them. Other pins do not have to be connected directly to the hub since they are less demanding. 

At least one I2c and one SPI bus is required for the expansion ports and the nanoSPI connectors. If the device has multiple buses and can afford it in pins, you can split the networks per expansion connector or between nanoSPI connectors and expansion connectors.

Only 2 ADC lines per driver slot are required, though 3 is nice. There isn't currently a need for 3 ADC lines because both brushed and brushless motor drivers can work fine with only 2 current sense feedback lines. This may change

The first chip I used is the esp32-s3. This chip is a low on pins, so some tricks such as disabling USB, programming over the sensor SPI bus, and using a shift register for SPI chip selects were used. I also have exposed only 2 adc lines per driver.

# Numbering Scheme
The numbering scheme between hubs is bottom up, with the PSU at the very bottom as address 0, and hubs connected on top of that with subsequent numbers. All the sensor and motor ports per hub follow this numbering scheme as well, with a left to right scheme added. Even the individual driver pins follow the bottom up scheme

# Changelog:
- 2024-08-09 Created
- 2025-01-01 Updated ideas and spec
- 2024-03-02 Added jumbo size and power bypass ideas

See also:
```dataview
LIST
FROM outgoing([[]])
```