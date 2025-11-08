---
aliases:
tags:
modified:
  - 2024-04-26T22:01:06-06:00
  - 2024-04-27T22:10:46-06:00
  - 2024-04-28T21:32:27-06:00
  - 2024-05-03T21:08:05-06:00
  - 2024-05-04T16:27:51-06:00
  - 2024-05-07T22:05:46-06:00
  - 2024-05-08T17:33:46-06:00
  - 2024-05-27T22:30:01-06:00
  - 2025-11-08T12:21:54-07:00
---
Article on designing power path using discrete components: [BQ24650: Power path design using BQ24650 - Power management forum - Power management - TI E2E support forums](https://e2e.ti.com/support/power-management-group/power-management/f/power-management-forum/756067/bq24650-power-path-design-using-bq24650)

# Power Path Chips:
All the chips on here must meet one requirement: Supports an external FET between battery and Vout. Doesn't matter if its load switching or DPPM (Dynamic Power-Path Management) from TI's DQ charger, only that it prioritizes output current

| Name      | Voltage | Current | Price | Notes                                                                                                                                                                                                                                                                                                                                                                                                                   | Link                                                                                      |
| --------- | ------- | ------- | ----- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------- |
| LTC4416   |         |         |       | Can drive 2 supplies                                                                                                                                                                                                                                                                                                                                                                                                    |                                                                                           |
|           |         |         |       |                                                                                                                                                                                                                                                                                                                                                                                                                         |                                                                                           |
| bq2477x   |         |         |       | 1-4 cell i2c controlled charger                                                                                                                                                                                                                                                                                                                                                                                         |                                                                                           |
| bq25060   |         | 1       | 1.62  | Nice simple charger design, 1 cell 1 amp                                                                                                                                                                                                                                                                                                                                                                                |                                                                                           |
| bq25050   |         | 1       | 1.65  | Same as 25060 except it has a single input control, and current sense output.                                                                                                                                                                                                                                                                                                                                           |                                                                                           |
| BQ25730   |         |         | 2.77  | Complex external circuit, supports USB PD. Similar to BQ25700A Needs 5 mosfets. 1-5 cell, and i2c controlled                                                                                                                                                                                                                                                                                                            |                                                                                           |
| bq24780S  |         |         | 2.81  | i2c controlled charger 1-4 cells. Doesn't have power path but instead calls it hybrid power boost. Complex layout, not as bad as BQ25730.  Needs 5 mosfets                                                                                                                                                                                                                                                              |                                                                                           |
| BQ24171   | 4.5-17v | 4A      | 2.85  | 1-3 cell battery charger with external power path. Standalone                                                                                                                                                                                                                                                                                                                                                           |                                                                                           |
| bq24600   |         |         | 2.89  | Very complex with all required external components. 1-6 cell charger. Can't tell if it has power path though                                                                                                                                                                                                                                                                                                            |                                                                                           |
| BQ24133   |         |         | 3.22  | 1-3 cells. Medium complexity circuit Needs 3 mosfets. 2.5 amps charge. Doesn't support battery suplliment                                                                                                                                                                                                                                                                                                               |                                                                                           |
| bq24170   |         |         | 3.36  | 1-3 cell. Medium complexity circuit, needs only 3 mosfets. Virtually identical circuit to BQ24133, except supports higher charge current.                                                                                                                                                                                                                                                                               |                                                                                           |
| LTC4412   | 2.5-28v |         | 4     | Single fet controller (Mimics an Ideal Diode). Can be daisy chained for multiply supples. Very common, and it has lots of potential applications                                                                                                                                                                                                                                                                        |                                                                                           |
| BQ24725A  |         |         | 4.22  | I2c controlled charger, supports big power supplies and 1-4 cells. Needs 5 mosfets. Can't be configured in standalone                                                                                                                                                                                                                                                                                                   |                                                                                           |
| LTC4088-2 |         |         | 4.49  | Charges battery and load shares, with external mosfet for battery. downside is its tailored to USB charging at low currents.  It has fixed charge values (100, 500, or 1000mah), and only has one power input. The -1 and -2 variants don't have a 3.3v regulator, but instead have auto charge current reduction, and show the external gate driver as default. For Li-ion, but should be fine for lipo with 4.2 float |                                                                                           |
| LTC4085   |         |         | 5.38  | Nice charger, similar to 4088. Has support for both wall input and USB. Max charge 1.5 amps. The -3 or -4 variant have a 3.95 float voltage. For Li-ion, but if I get a variant with 4.2 float voltage it should be fine.                                                                                                                                                                                               |                                                                                           |
| LTC4162-L |         |         | 7.24  | Almost perfect! Supports a variety of power inputs. Only requires 2 mosfets and a lot of inductors. I2c telementary, but not required for control. Power path bit is unclear if it has battery suppliment when the power supply is on.                                                                                                                                                                                  | https://www.digikey.com/en/products/detail/analog-devices-inc/LTC4162EUFD-LAD-PBF/9446106 |
| BQ25750   |         |         | 8.39  | 1-14 lipo batteries, High voltage and current. Standalone or i2c controlled                                                                                                                                                                                                                                                                                                                                             |                                                                                           |
A lot of the medium complexity circuits have inductors on the power lines, and resistor voltage dividers for all the settings.

## Honorable mentions

| Name    | Voltage | Current | Price | Notes                                                                   | Link |
| ------- | ------- | ------- | ----- | ----------------------------------------------------------------------- | ---- |
| BQ25180 |         |         | 2.65  | 8 pin BGA package with 1 amp charge current. I2c                        |      |
| LTC1479 |         |         | 19    | Manages a ton of other power related chips. Too complex                 |      |
| BQ2461x |         |         |       | Supports a lot, but it unfortunately does not prioritize output current |      |
| bqTINY  |         |         |       | A series of chips with integrated fets                                  |      |

# Battery Chargers
Chargers without power path control

| Name     | Voltage | Current  | Price | Notes                                                       | Link                                                                                                                                                             |
| -------- | ------- | -------- | ----- | ----------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| TP4056   | 4.2v    | up to 1A | 0.5   | VERY common in chinese battery charging stuff. Seems decent |                                                                                                                                                                  |
| MCP73871 | 4.2v    | 2A       | 3     | Nice all around charger and PMIC                            | [ww1.microchip.com/downloads/en/DeviceDoc/MCP73871-Data-Sheet-20002090E.pdf](https://ww1.microchip.com/downloads/en/DeviceDoc/MCP73871-Data-Sheet-20002090E.pdf) |


# Battery Balancers/ protectors 
| Name     | Voltage | Current | Price | Notes                                                                                                              | Link |
| -------- | ------- | ------- | ----- | ------------------------------------------------------------------------------------------------------------------ | ---- |
| BQ76905  | 27      |         | 1.85  | 2-5 cell i2c protector, battery balancer and battery monitor (coulomb and voltage). Honestly really good for a BMS |      |
| BQ28Z620 |         |         |       | i2c fuel gauge, 1-2 cell, balancing, battery protection. Logic level 1.8v                                          |      |
| bq78z100 |         |         |       | Virtually the same as BQ28Z620, except provides HDQ protocol. Has a more limited current resitor range             |      |
| BQ77307  |         |         |       | 2-7 cell protector, no balancing just measurement                                                                  |      |
| bq298xxx |         |         |       | 1 cell battery protector.                                                                                          |      |


# Top Pick Example
- LTC4088-2 Most expensive
- bq25060. Single cell, simple
- BQ25730. Most complex. Requires i2c host for settings
- bq24780S. Requires SMbus host for settings. For hybrid boost the input current must be over 1.5 amps
- BQ24171. A cheap 2 dollar charger that is stand-alone. Requires 3 mosfets. Switches mode with a 200mV difference

It seems like for anything above 1 cell batteries I have to have a really complex circuit and an additional microchip to control it all. This is frustrating, that I can't find a standalone, cheap, DPPM or Hybrid Boost Mode battery charger chip with external FETs and support for several lipo cells and high amperage.

The ones that require a host also have very low regulator output currents. I mean, seriously 6volts at 13ma?!! I can't run a host very well on that. I did find a low current regulator that could work: TPS62745.

## LTC4162-L special note

Expensive ($7~9), but it only requires two mosfets, and some inductors. Supports i2c telementary, not required. Power path is unclear if the battery can supply current if the system is overloaded.

From the datasheet:
> These drivers make up a dual unidirectional power path system that allows power to be delivered to the system load by either the input supply or the battery, whichever is greater

I think if the system draws too much current the voltage should drop and the system will switch over to the battery. The datasheet says 20mV is the threshold.

# Changelog:
- 2024-05-27 Added battery balancers and protections
- 2025-11-08 Cleaned up a bit

See also:
```dataview
LIST
FROM outgoing([[]])
```
