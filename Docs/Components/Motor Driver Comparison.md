---
modified:
  - 2024-03-10T20:55:09-06:00
  - 2024-03-25T23:00:11-04:00
  - 2024-03-26T23:00:08-04:00
  - 2024-03-27T23:03:02-04:00
  - 2024-03-28T20:45:51-05:00
  - 2024-03-29T21:33:36-06:00
  - 2024-04-18T10:13:47-06:00
  - 2024-04-23T19:48:00-06:00
  - 2024-04-25T20:01:09-06:00
  - 2024-04-27T14:00:26-06:00
  - 2024-04-29T18:03:12-06:00
  - 2024-10-14T22:05:33-06:00
---

I want a FOC controller that is compact and not to expensive. This is not in the task/goal system.

Helpful page for TI drivers: [Brushless DC (BLDC) motor drivers | TI.com](https://www.ti.com/motor-drivers/brushless-dc-bldc-drivers/overview.html)

# Position Control

FOC controllers already can detect relative position of a motor. However it is not that precise, and at slow speed useless. Since my motors will be on a reduction gear box, it should be fine. I will have to figure out absolute position anyway. 3d Hall effect sensors are an attractive option, because they don't need an encoder wheel.

Another option is designing a complex driver that can inject high-frequency pulses and measuring those to get absolute motor position.

# Types
Most of these chips still require output gate transistors.

- Integrated XXX. A chip that has everything already built in to drive. Replace XXX with the control algorithm. It may or may not be a FOC, but it still is standalone and space saving. 
- Normal cheap ESC.
- Driver. These have FETs and current sensors, but they still need a microchip to support. Has 3 PWM inputs usually
- Microcontroller [[Microcontroller Comparison]]. Useful for installing Simple FOC, it may be a good cheap option, but a microchip + driver takes up more space
- 
# Driver Table

| Driver      | Type                   | Voltage | Drive Current | Indv Price per 10 Qty    | Online Rating | Notes                                                                                                                    | Link                                                                                                               |
| ----------- | ---------------------- | ------- | ------------- | ------------------------ | ------------- | ------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------ |
| AMT49406    | Integrated FOC         | 5.5-50v | Needs FETs    | $2.91                    |               | First option I found for code-less FOC. Similar is A89301                                                                | [AMT49406GESSR \| Digikey](https://www.digikey.com/en/products/detail/allegro-microsystems/AMT49406GESSR/10498710) |
| TI DRV8311  | Driver                 | 3-20v   | 5A            | $1.41                    |               | S and P variants have a 1 pwm input mode that automatically generates signals. Also SPI interface, which can be a driver | [Site Unreachable](https://www.mouser.com/new/texas-instruments/ti-drv8311-bldc-motor-driver/)                     |
| TI MCT8315Z | Integrated trapezoidal | 4.5-40v | 4A            | ($0.98 per 1k) exception |               | 1 PWM input. Cant purchase from distributer                                                                              | [MCT8315Z data sheet, product information and support \| TI.com](https://www.ti.com/product/MCT8315Z)              |
| TI DRV10974 | Integrated sinusoidal  | 4.4-20v | 2.5A          | $1.21                    |               | Order from Arrow. Smallest ESC.                                                                                          | [DRV10974 data sheet, product information and support \| TI.com](https://www.ti.com/product/DRV10974)              |
| TI DRV10970 | Integrated sinusoidal  | 5-20v   | 3A            | $2.2                     |               | Similar to DRV10974  except more current, and require hall sensors. In TSSOP package                                     |                                                                                                                    |
| TI DRV8313  | Driver                 | 8-65v   | 2.5A          | $3.19                    |               |                                                                                                                          | [DRV8313 data sheet, product information and support \| TI.com](https://www.ti.com/product/DRV8313)                |
| TI DRV8317  | Driver                 | 4.5-24v | 5A            |                          |               | Need to order 1k                                                                                                         |                                                                                                                    |
| ST SPIN233  | Driver                 | 1.8-10v | 1.3A          | $1.96                    |               | Nice and simple triple half bridge, Smallest ESC. Over priced for functionality                                          | [Fetching Title#mc68](https://www.st.com/en/motor-drivers/stspin233.html)                                          |
| TI DRV8316c | Driver                 | 4.5-40v | 8A            |                          |               | Has better current sensing than 8316. Need to be in 3k orders.                                                           |                                                                                                                    |
| ST L6234    | Driver                 | 7-45v   | 5A            |                          |               | Basic, bigger package                                                                                                    |                                                                                                                    |
| MCF8316A    | Integrated FOC         | 4.5-40v | 8A            | $4.12                    |               | An interesting option from TI. I think it is limited to 12-24 volt motors                                                |                                                                                                                    |


## Top Picks:
- TI DRV8311.
- TI DRV10974. 

Both are cost effective. DRV10974 is more design compact, with a sinusoidal wave generation built in. Sinusoidal is the best thing below FOC control. It also is a little bit smaller, with 4 pins on each side

However the DRV8311 supports a voltage and current range more suitable for my application. The docs specifically state 1s-4s for mobile applications. Unbalanced 5x7 pin count. It supports SPI control(S variant, P variant for multi-device address selector), which will reduce a lot of pin count if it works. Maybe I can do FOC control over SPI, but this is a bit of a stretch. Note that the P variant has NO support for hardware, and vice-versa. I will have to buy two chip versions and test each to see how SPI FOC works. This may help[TMC6200 SPI With Simple FOC - hardware support - SimpleFOC Community](https://community.simplefoc.com/t/tmc6200-spi-with-simple-foc/4157/3) BTW the S variant IS NOT PRUCHASABLE.


