---
aliases: 
tags: 
append_modified_update: true
modified:
  - 2024-09-16T21:19:03-06:00
  - 2024-09-29T21:48:08-06:00
  - 2024-10-08T20:11:50-06:00
  - 2024-10-27T21:47:33-06:00
---

# Protocol
Ideally I want this board is to be **asymmetrical** in communication, where no one MCU is master. This theoretically would allow me to have a **compute cluster** using onboard MCUs, without relying on a powerful SBC. I will still likely have a host SBC talk with the board for advance AI. Each MCU has a customizable config that can be updated to help it understand it's place and connected motors and sensors. The best multi-master/ multi-drop busses I found are differential, such as RS485, ethernet, and CAN. They all support buses and collision detection, though RS485 is just a hardware spec and you have to write your own multi-master protocol on top.

Yet there are also a lot of **dis-advantages** with this setup, namely **Speed and cost**. Any sort of differential bus is NOT usually supported natively, and therefore will require a 1 dollar transceiver per board. It is also really slow, with CAN bus topping out at 1MB/s. Ethernet is much higher speed, but it requires really expensive chips or a lot of pins. SPI bus in this case would win for speed and cost savings, though it would mean a master and slave architecture

SPI bus has its own problems though, such as not being infinitely expandable. The number of devices is limited to the number of pins on the master, meaning I can't plug in boards forever.

It appears like I am in a sticky conundrum, with no where to turn without sacrifices. I want infinite expandibilty, high speed, and low cost. I could write my own ring-based protocol, but that would be slow speed and probably not that reliable. If I wrote a protocol and wanted it high-speed, the best way to achieve that would be to use an existing hardware protocol..

For a project like my robot dog with limited motor potential, it is easier to choose a protocol. I could probably just use SPI, since I will unlikely have more than 4 hubs. I loose out on asymmetrical, but I save cost and have super high speeds. For any other projects though it is tough, especially since the board will be its own commercial product.

THE ONLY bus that seems to balance everything is I2C. It is low speed like CAN bus, but it is virtually in every micro controller in modern times, which is cheap. If you add a layer on top you get SMbus, which supports arbitration and multimaster easily. Bus speeds are limited to 100khz with SMbus.

A bus that I found very interesting is called I3C. Its meant to be a replacement bus operating at 12.5mhz and supporting everything that i2c does. Think SMbus, with hotplug and a 100x speed. It is not supported by most board yet though.

RS-485 is my ideal second choice, because I can implement whatever protocol I wanted and use some cheap $1 transceivers (like the TI 1420 ($1.03) or  ISP3485EN-L/TR ($0.87)). CAN bus transceivers cost more, even in the same SOIC-8 package. If I wanted a smaller package I could pay more and get THVD1420DRLR for $1.42

Another Idea I had was using a RP2040 as a repeater. If I had a 15x15mm module between, then it could repeate the SPI signals and have infinite number of chip selects. The RP2040 can also have 2 motor driver modules plugged in, (it has exactly 4 ADC), and it can also act as a node itself for computing. Its only a dollar, which is about the price of a differential bus transceiver!

I could write a protocol that supports user-assisted auto addressing. The user could press the BOOT buttons on each board in order, and the address will be broadcasted on the network on by one! The ordered number would also be saved on chip, and each chip would have its own map. This idea works for both multi-master and master-slave architecture, and does not need external connections to setup a network. Each device added afterward initial setup would broadcast its mac address, and would be assigned a number based on the existing map. You can trigger a map reset too. 

For hotplugging rs 485 support I should have the chip assume on powerup that nothing is talking to it, and only after a set delay of idle bus should it respond

I also found an opensource product that does almost exactly what I want for my modular robot control system! Its called [luos_engine](https://github.com/Luos-io/luos_engine). Every MCU knows all the others in the system and can communicate with any of the servicies. This was just a random discussion I found on the SimpleFOC discord about its integration. [Luos Technology | Luos](https://www.luos.io/docs/luos-technology). Luos has its own communication protocol built in, called Robus, which supporst Rs485 or One wire. It supports 700kbs per second for data max on a 1mhz bus. I would write my own motor services and process data commands.

# Changelog:
- 2024-09-16 Created

See also:
```dataview
LIST
FROM outgoing([[]])
```