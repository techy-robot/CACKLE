---
aliases:
tags:
modified:
  - 2024-10-14T22:13:06-06:00
  - 2025-09-23T16:41:40-06:00
  - 2025-11-08T11:32:59-07:00
---

I am trying to save money while still acheiving what I need. Currently, for signal lines I am using 2x2 1.27mm right angle pin headers, and for Power, I'm using Keystone 6100 and 6102 quick connect edge connectors. For vertical Mezzanine connectors, I am using TE 3-2363961-0 receptacle and TE 3-2363962-0 connector, 30 pins.

The power connectors are expensive, around $1.8 per pair. I have found a sister product that is much cheaper however, and provides almost the exact same functionality. Its Keystone 3579, which is tin plated instead of gold plated. It can still carry 10 amps per connector. The matching component is 3569, which is a fuse clip. Now, this is much longer than the 610x receptacle, and the blade doesn't stick completely into it. I had a fun idea of chopping the part in half, and using it twice. The length would match, it would just be unstable on the board (ie not usable on a PnP).

If I cut in half, the price per pair would be $0.83! This seems like a pretty good deal for a high current SMD connector, at least compared to everything else I've seen. I would probably get lower only if I stamped my own spring connectors.

# Alternative connectors:
- https://www.digikey.com/en/products/detail/amphenol-cs-fci/10120045-401LF/4996150. 4 position LED lighting connector. This has a much wider spacing than I want, but is a good style with the blades. The connector is Hermaphroditic too.
- https://www.digikey.com/en/products/detail/hirose-electric-co-ltd/TB4-10P-1F-800/26223934 This is interesting, fpc connector to a different type of connector. There is no board to board option though.
- https://www.digikey.com/en/products/detail/sullins-connector-solutions/EBC06MMBD/1922770 This is the only right angle edge card connector I can find, there are millions of female connectors.
- https://www.digikey.com/en/products/detail/amphenol-cs-fci/10162583-411111LF/15216696 Something that has right angle header but no right angle receptacle.
- [504275-E : ERNI PCB Headers & Receptacles \| TE Connectivity](https://www.te.com/en/product-504275-E.html) This is pretty good.
- [917360-6 : AMPMODU PCB Headers & Receptacles \| TE Connectivity](https://www.te.com/en/product-917360-6.html) Looks like what I want, but its obselete!!

# Changelog:
- 2024-10-14 Created

See also:
```dataview
LIST
FROM outgoing([[]])
```