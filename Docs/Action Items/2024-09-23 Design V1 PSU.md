---
title: Design V1 PSU
aliases:
  - Design V1 PSU
modified: 2024-11-09T14:15:15-07:00
tags: 
completed: 
itemtype: task
status: New
date: 2024-10-25
startTime: 
endDate: 2024-11-10
endTime: 
deadline: 2024-11-10
allDay: true
priority: Normal
effort: L
id: 
planned_hours: 50
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

# Comments:
- [ ] I found several design errata from the original, such as swapped polarity on the balance plug, and incorrect input voltage source. My prototype will need modification ➕ 2024-10-27 ^1
- [ ] I should add a secondary rs485 transceiver for redundancy for the host. The battery charge mcu should not have to act as a passthrough for the main compute module. Still, for this prototype it is unneccessary ➕ 2024-11-08 ^2
- [ ] Use XT30 connectors for the main battery plug ➕ 2024-11-08 ^3
- [ ] The BQ24780s does not handle charge profiles by itself, the i2c host has to handle all the battery charge profiles by itself. ➕ 2024-11-08 ^4

# Time Tracking:
```simple-time-tracker
{"entries":[{"name":"Initial arrangment of schem","startTime":"2024-10-26T02:39:49.000Z","endTime":"2024-10-26T03:48:16.000Z"},{"name":"schematic verification","startTime":"2024-10-26T22:47:46.000Z","endTime":"2024-10-27T00:24:49.000Z"},{"name":"rearranging schematic","startTime":"2024-10-27T00:57:04.000Z","endTime":"2024-10-27T02:34:08.000Z"},{"name":"component research, schematic work","startTime":"2024-10-27T22:02:31.000Z","endTime":"2024-10-28T00:08:18.000Z"},{"name":"verification and component switching","startTime":"2024-10-28T00:53:49.000Z","endTime":"2024-10-28T01:40:12.000Z"},{"name":"Adding MCU","startTime":"2024-11-07T02:06:24.000Z","endTime":"2024-11-07T03:01:16.000Z"},{"name":"Starting routing from scratch","startTime":"2024-11-08T00:29:47.000Z","endTime":"2024-11-08T01:08:36.609Z"},{"name":"Working on MCU section again","startTime":"2024-11-08T02:23:47.000Z","endTime":"2024-11-08T05:26:09.000Z"},{"name":"schematic work","startTime":"2024-11-08T16:56:29.000Z","endTime":"2024-11-08T17:57:02.000Z"},{"name":"research of components","startTime":"2024-11-08T22:13:40.000Z","endTime":"2024-11-09T01:58:19.000Z"}]}
```

# Changelog:
- 2024-09-23 Created