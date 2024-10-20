---
title: Design V1 Hub
aliases:
  - Design V1 Hub
modified: 2024-10-19T18:18:56-06:00
tags: 
completed: 
itemtype: task
status: In Progress
date: 2024-10-07
startTime: 
endDate: 2024-10-21
endTime: 
deadline: 
allDay: true
priority: Normal
effort: L
id: 
planned_hours: 30
logged_hours: 
product_version: 
subitems: 
peeritems: 
milestone: "[[2024-09-23 Design V1 of all 4 modules|Design V1 of all 4 modules]]"
createdby: 
assignees: 
completedby: 
---
`BUTTON[complete, uncomplete]`

# Description:

This is the central point of the modular control board. It talks to other hubs, drivers motor modules, and has multiple sensor interfaces. This is the most complex board followed by the PSU. See [[Architecture]].

This is a 6 layer board, which tries to follow the order Sig/Gnd/Pwr/Sig/Gnd/Sig. I did have to sacrifice the lower ground layer and route a few signals to make it all work together.

# Comments:
- [x] Shift all the motor pwm pins down, and stick the FREEx pins and the i2c pins near the end. Now, only the motor pins and the analog pins will have glitching. Since it is a low level glitch, and there are no pullups on those lines, it should be fine. ➕ 2024-10-17 ✅ 2024-10-17 ^1
- [x] Move out the pin headers a few 0.1mms so that the headers are exactly the distance required for connection to the motor cards ➕ 2024-10-18 ✅ 2024-10-18 ^2
- [x] Fix port 2 and 4 being swapped ➕ 2024-10-18 ✅ 2024-10-18 ^3
- [x] If I go with a 6 layer board design I will have more space to route, and JLC offers free filled vias with the increased cost, saving me even more space. ➕ 2024-10-18 ✅ 2024-10-18 ^4
- [ ] The Free 1 and Free 2 pins might be more capable going on an analog capable pin. This, however, would require a fairly complex restructuring of the routing, which causes delay for not much gain ➕ 2024-10-19 ^5
- [ ] There is a potentially big cross talk problem on layer In3. There is a high speed differential pair running on that layer, along with the lowspeed i2c lines, all right next to thick power traces. ➕ 2024-10-19 ^6

# Time Tracking:
```simple-time-tracker
{"entries":[{"name":"Schematic work","startTime":"2024-09-30T02:20:10.000Z","endTime":"2024-09-30T03:48:27.000Z"},{"name":"Schematic work","startTime":"2024-10-08T02:10:23.000Z","endTime":"2024-10-08T03:20:52.000Z"},{"name":"Finished rough schematic","startTime":"2024-10-09T01:45:54.000Z","endTime":"2024-10-09T03:20:43.000Z"},{"name":"Component Research","startTime":"2024-10-13T23:14:51.000Z","endTime":"2024-10-14T00:10:14.000Z"},{"name":"Designing footprint for mezzanine connectors","startTime":"2024-10-14T00:47:13.000Z","endTime":"2024-10-14T02:04:04.000Z"},{"name":"Component downsizing research, finished layout","startTime":"2024-10-15T20:15:11.000Z","endTime":"2024-10-16T01:59:11.000Z"},{"name":"started wire fanout","startTime":"2024-10-16T22:00:40.000Z","endTime":"2024-10-16T23:51:07.000Z"},{"name":"routing","startTime":"2024-10-17T21:36:40.000Z","endTime":"2024-10-18T00:03:41.000Z"},{"name":"routing and part rearrangement","startTime":"2024-10-18T15:54:34.000Z","endTime":"2024-10-18T16:56:00.000Z"},{"name":"routing 6 layers","startTime":"2024-10-18T19:45:01.000Z","endTime":"2024-10-19T00:06:37.000Z"},{"name":"debugging how to route a tricky wire","startTime":"2024-10-19T00:50:32.000Z","endTime":"2024-10-19T03:08:28.000Z"},{"name":"routing tricky wires","startTime":"2024-10-19T20:01:01.000Z","endTime":"2024-10-20T00:20:07.374Z"}]}
```

# Changelog:
- 2024-09-23 Created