---
aliases:
tags:
modified:
  - 2024-04-25T22:05:07-06:00
  - 2024-04-26T18:00:30-06:00
  - 2024-04-27T14:00:19-06:00
  - 2024-06-02T22:10:16-06:00
  - 2024-06-03T14:10:25-06:00
  - 2024-07-05T13:40:14-06:00
  - 2025-11-08T12:09:53-07:00
---

# Micro-controller Table
Price Per motor is first calculated by finding the max number of motors: Take the limiting pin count (either ADC or PWM), flooring the division by 8 (since the boards are driver increments of 2 and each has 4 pins), then multiplied by 2 again. The price is then divided by that result.

| Chip                               | Voltage  | Current | Indv Price per 10 Qty | Online Rating | PWM | ADC | Price per Motor | Flash/RAM | MHz | Notes                                                                                                                                                   | Link                                                                                                                           |
| ---------------------------------- | -------- | ------- | --------------------- | ------------- | --- | --- | --------------- | --------- | --- | ------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------ |
| ATTinyXX                           | 3.3-5v   |         | $0.5~$1               |               |     |     |                 |           |     | bad budget option, if it is even fast enough.                                                                                                           |                                                                                                                                |
| Esp32-s3F8 + 16-bit shift register |          |         | $2.85                 |               | 16  | 20  | 0.71            |           |     | PWM through shift register. 4 motors. $0.57 is shift                                                                                                    |                                                                                                                                |
| STM32U073CC                        | 1.7-3.3  |         | $3.03                 |               | 16  | 16  | 0.76            | 256/40kb  | 48  | Seem to be in low stock. Low power chip. Very good value                                                                                                |                                                                                                                                |
| STM32G474RE                        | 1.7-3.3  |         | $8.78                 |               | 52  | 42  | 0.88            | 512/128kb | 170 | 12 are advanced motor control PWM. Digikey is cheaper.                                                                                                  |                                                                                                                                |
| STM32F072R8                        | 1.7-3.3  |         | $3.53                 |               | 16  | 16  | 0.88            | 64/16kb   | 48  |                                                                                                                                                         |                                                                                                                                |
| STM32G071R8                        | 1.7-3.3  |         | $3.57                 |               | 16  | 16  | 0.89            | 64/36kb   | 64  | Its confusing with the PWM, as they have many different timers that have different channel amounts. Can have 5                                          |                                                                                                                                |
| STM32G474RC                        | 1.7-3.3  |         | $7.47                 |               | 52  | 42  | 0.747           | 256/64kb  | 170 | 12 are advanced motor control PWM. Digikey is cheaper. Not all capabilities are exposed in 64 pin package                                               |                                                                                                                                |
| ATSAMD51P20A                       | 1.7-3.3v |         | $8.1                  |               | 40  | 32  | 1.01            | 128kb     | 120 | 15 ADC, 22 PWM, on Adafruit Grand central. In datasheet it can go upto 32 ADC, 40 PWM. This is a beast that could support 5 motors or 10 with bare chip |                                                                                                                                |
| STM32G071RB                        | 1.7-3.3  |         | $4.11                 |               | 16  | 16  | 1.03            | 128/36kb  | 64  |                                                                                                                                                         |                                                                                                                                |
| STM32G0B1RC                        | 1.7-3.3  |         | $5.2                  |               | 20  | 16  | 1.3             | 256/144kb | 64  | Interesting upgrade to the other G0x1s. Can have 4 motors, unless you drop a current sense line . USB c controller built in.                            |                                                                                                                                |
| STM32G473RB                        |          |         | $6.77                 |               | 24  | 42  | 1.13            | 128kb     | 170 | 12 are advanced motor timers. Has usb controller                                                                                                        |                                                                                                                                |
| Esp32-s3F8                         |          |         | $2.28                 |               | 12  | 20  | 1.14            |           |     | Supports running pwm on ANY pin using MCPWM, and has several adcs. Up to 2 motors. This has 8mb flash                                                   |                                                                                                                                |
| STM32G0B1RB                        |          |         | $5.17                 |               | 20  | 16  | 1.29            | 128/144kb | 64  | Mouser. same as other 0b1                                                                                                                               |                                                                                                                                |
| stm32g070rb                        | 1.7-3.3  |         | $2.67                 |               | 12  | 16  | 1.34            | 128/36kb  | 64  | Similar to other g070. Very good value. Rb is the highest pin count at 64                                                                               |                                                                                                                                |
| STM32L412RB                        | 1.7-3.3v |         | $4.55                 |               | 11  | 16  | 2.28            |           | 80  | Low power chip                                                                                                                                          | [Site Unreachable](https://www.mouser.com/ProductDetail/STMicroelectronics/STM32L412RBT6P?qs=l7cgNqFNU1hh%252BU1wOZs5Xg%3D%3D) |
## Notes
The STM 32 G0x1 series seems to be the best budget option for chips, and most 64 pin chips have enough outputs to drive 4 motors. Cortex M0. $3.5~6

The price is higher for STM32 G4XXX, only the lowest option is 3.95 for 64 pin. This is good if I can operate a lot of motors.

Each motor needs 3 pwm out, and 3 adc lines for current sensing. Another unspecified requirement are pins for encoders, which I have not figured out. I will most likely be doing a 3d hall effect sensor over i2c or spi. You can drop a current sense line, but I don't know the performance impact.

All chips on the table have at least one SPI port. I have not identified which chips are easier to set up however.

Most chips are qfn 64, and 32 bit. I have not checked if all the outputs listed are available in that package format

STM32 chips are well supported in Simple FOC.

# Top Picks
- STM32G071RB
- STM32G0B1RC 
- stm32g070cb
- STM32U073CC
- STM32G474RC
- STM32G473RB
- ESP32-S3 with built in flash

## Findings from using STM-32 Cube MX for pin configs.
Note that cost is still per 10 units.

### STM32G071KB 
- 32 pin package 
- Max 10 ADC
- Max 10 PWM
- 1 i2c, 1 spi, 1 swd
- 2 extra gpio.
- Cost 2.85 Mouser

### STM32G071RB 
- 64 pin package 
- Max 12 ADC
- Max 17 PWM
- All comms are able to run with this 2 i2c and 2 spi. USB is not on this chip.
- Cost 4.11

### STM32G0B1KC 
- 32 pin package, no leads.
- Max 9 ADC
- Max 9 PWM
- 1 i2c, 1 spi, 1 usb, and 1 SWD
- 3 extra GPIO, BOOT0 is conflicting. This is a very dense layout.
- cost $4.63. KB is 4.18, 1.39 a motor
- Expensive with 256 kb flash, a little smaller package, USB capability and other features I don't need.
- DO NOT GET THE N version. It is impossible to get all outputs.
![[media/STM32G0B1KCUx.jpg|400]]
### STM32G0B1RC 
- 64 pin package 
- Max 12 ADC
- Max 21 PWM
- All comms are available except USB pwr delivery.
- Has USB-C pwr delivery and USB.
- cost $5.2

### stm32g070kb.
- 32 pin package 
- 9 ADC
- 10 PWM
- 1 I2c and 1 SPI, no usb, 1 SWD
- 3 GPIO pin free
- Cost $1.89
![[media/STM32G070KB.jpg|400]]

### stm32g070cb GOOD DEAL W/O USB
![[media/STM32G070CB.jpg|400]]
- 48 pin package 
- Max 12 adc
- Max 12 PWM (10w/o the config change below)
- All comms are available. No usb
- Cost $2.01
- There is a confusing setting in STMCube MX called Sequencer. If this is set to not fully configurable, then two more ADC pins appear, and I can rearrange stuff to get 12 pwm pins. PPM would then be $0.64! Reading online forums it appears that the only thing that would change is setting different sampling rates for different channels, which I don't care about.
- This package is the same size as KB, except with finer pitch.
- Combined with a cheaper clock (Since I now have OSC in and out), I could actually save quite a few dimes!
- With simplefoc you can only run 3 motors because not all timers support syncing

### stm32g070rb 
- 64 pin package 
- Max 12 adc
- Max 13 PWM
- All comms are available. No usb
- Cost $2.67

### STM32U073CC 
- 48 pin package 
- Max 8 ADC pins
- Max of 14 PWM pins (Don't do N channels, which eliminates all communication interfaces besides SWD
- I can disable output from TIM1_CH4 to get USB, and TIM16_CH1 to get I2C1.
- I can disable TIM2_CH2, TIM3_CH1, and TIM3_CH2 to get SPI1.
- That leaves me with 9 PWM
- The ADC pins and the PWM pins stay in separate areas, broken up by communication interfaces
- cost $3.37
- The 32 pin version also has 8 adc ports
### STM32U073RC. GOOD DEAL, Lot of space
- 64 pin package 
- Max 12 ADC pins
- Max 15 PWM pins
- 3 I2c and 2 SPI buses are available without disabling other pins, but USB needs TIM1_CH4 disabled like above.
- Cost $3.11

### STM32G474RC. BIG BOY
- Max 26 ADC
- Max 29 PWM
- Not all ADC and PWM can be on at once, and I need other communication interfaces. 
- If I enable USB, SPI3 and I2C1, and all other pins in various configurations, then I could have 20 ADC and 20 PWM. 
- Cost $7.47
- 6 motors a chip, $1.25 a motor. Not the best deal.
- It reduces the amount of chips, but I'm not sure about actual space savings because LQFP64 is 10mm x 10mm chip, vs 7mm of a LQFP48.

Config:
![[media/STM32G474RC.jpg|400]]

### STM32G473CB
- 48 pin
- Cost $6 per 10 at digikey
- Max 20 ADC
- Max 27 PWM
- Similar to above, it needs some playing around. With one usb, SPI, and I2c, I can have 13 ADC, and 14 PWM. This maximizes most of the pins
Config:
![[media/STM32G473CB.jpg|400]]

### ESP32-S3 

Yes, this is not an stm32 product. But it is still a top pick due to the price and capability
- 240 mhz dual core
- 12 pwm all through a dedicated motor interface 
- $2.28
- 20 channels and two adcs
- Side note that it has fewer strapped pins than the original esp32
- I2c, spi, and USB.
- Very particular on some pins about behavior.

Helpful website for finding what all the pins do on power up, reset, etc... [Schematic Checklist - ESP32-S3 - — ESP Hardware Design Guidelines latest documentation](https://docs.espressif.com/projects/esp-hardware-design-guidelines/en/latest/esp32s3/schematic-checklist.html)

Specifics: I need to use pins all on the same adc for Simplefoc

# Changelog:
- Migrated microcontrollers to this file from [[Motor Drivers]]
- Reconsidered STM32G070cb as an option, with a simple config change I now get a better clock source option and 4 motor support.
- 2024-06-02 Added ESP32-S3 option
- 2025-11-08 Updated cost per motor calculations to match the move from 3-pin to 4-pin drivers 

See also:
```dataview
LIST
FROM outgoing([[]])
```