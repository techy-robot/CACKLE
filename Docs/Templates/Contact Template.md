---
name:
  - 
aliases: 
tags: 
birthday: YYYY-MM-DD
location: 
locations: 
address: 
city: 
state: 
itemtype: contact
---
Picture

phone:: 
email:: 
## Family
- 
## Notes
- 

## Locations Traveled
- 

# Projects
- 

# Changelog:
- <% tp.date.now("YYYY-MM-DD") %> Created
## Mentions:
```dataview
table without id
    link(file.link, title) as "Files",
    length(filter(file.outlinks, (x) => contains(x, this.file.link))) as "Mentions"
where contains(this.file.inlinks, file.link)
sort file.name asc
```