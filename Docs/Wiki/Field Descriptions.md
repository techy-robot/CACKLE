---
modified:
  - 2024-01-11T15:55:30-07:00
  - 2024-05-13T11:26:24-06:00
  - 2024-05-14T21:11:48-06:00
append_modified_update: true
---
Here I will attempt to describe most of the fields in my project planning templates. Most of them are common sense, but some are confusing.

# Metadata Fields
`parentitem` If filled in this means the item belongs to another, usually as a subtask. This is a link. I am thinking of dropping this. UPDATE: I did drop it.

`peeritems` These are items that are grouped with the current action item/goal. It is neither above nor below, but rather just linked. This is an array of links. For milestones it means something else must be accomplished first.

```milestone``` This is the milestone the task belongs to.

`subitems` This items has a sub items, usually used for action items. This is an array of links. Note that VERY simple tasks that deserve to be in a basic checklist should not have their own note, but rather in a hosting note that summarizes the task group, too remove clutter.

`id` A unique ID for that particular note. Goals are the only notes that don't have an id. Honestly this isn't required, I just want it in there, an incrementing id.

Goals are the only things that have a more extensive logs. It can have a `log_type` of `budget`, `hours`, `productivity`, `percentage`, etc... You have a starting value, a current value, and the ideal goal value. The actual log will be kept inline. Try to be descriptive of the person, what it was for, what was done, etc... A log description may not be applicable for all things, but anything done by people should probably have a description linking to that person.

In Action Items the log is solely for time keeping purposes, so I have a separate plugin for that keeping track. The front matter metadata you have to hand update, because data view can't query in custom code blocks.

On a separate note there is a Logs folder where you keep *HIGH LEVEL OVERVIEW* of all the things you did. This is long form writing, meant to capture ideas and stuff more for the outside world.

`completedby` is a field that links to the person who completed the action item.

Unfortunately there are some feilds that are unnecessary but required to display in Full calendar:

`allDay` Almost all of the tasks are all day, and this really isn't required because you can just look at the start and end days/times.

`completed` This is redundant with `status`, and status can have more types. For my usage I am setting the completed field to null, and just using status

`title` This is literally the name of the note. The name of the note ALSO has to include the start date.

The worst part of this is you have to keep these in-sync with your other stuff! And since the date now has to be in the filename as well as the title field, I have to add the alias field just to keep my note referencing more concise. But the aliases field for some reason duplicates events on the calendar! 

I found only one instance where someone used dataview to create a custom calendar: [Custom Full Calendar with DataView - #4 by Bronus - Share & showcase - Obsidian Forum](https://forum.obsidian.md/t/custom-full-calendar-with-dataview/34133/4) This is my only hope for displaying a calendar, but then the fields wouldn't be editable!


# Headers
In addition to the metadata, there is also headers for the more generic stuff ^1

## Comments
This section basically is an organized, thought out, markdown task list, with the "thread starter" comment behind a checkbox and sub comments being indented bullet points. This also is intended as an issue tracker per action item. Comments will not be resolved, but issues will be resolved.

Since this is a markdown task list, there should not be any indents except for subcomments, nor any line breaks except to create a new contact.

### Date tracking
You should add comments in descending order of created date (the comment up top was the first comment). Each comment should have a created date at the end of it, as well as a resolved date, using the Obsidian Tasks emoji format. `➕ YYYY-MM-DD` is created, `✅ YYYY-MM-DD` is resolved. The emojis and dates must be at the end of the line.

### Referencing
At the end of each comment (but before the date tracking) add the link to the commentators contact page (for projects having multiple users). 

Each comment should also have a block reference number, incrementing from 1 at the beginning. So the first comment in the list reference  is `^1`. Subcomments follow the same pattern, except appending a dash at the end, E.G. `1-1`. Block references, unlike normal text, can be after the date emojis and not cause issues with Obsidian Tasks.

The display text should be the name of the file and the block reference. Don't include the date in the title.

### Splitting tasks 
This is an advanced thing that I highly doubt will be used in obsidian as project management.
My idea is that if a group of comments have to be moved, the comments would be replaced with `These comments have been moved to` [[]] (backticks included) . And in that file the first comment would be `Comments moved from` [[]].

## Time tracking 
This field is solely dedicated the Super Simple time tracker plugin. Log any activities with this. Try to split your time into dedicated sections where you work on specific tasks, and log those.

# Changelog 
Log any *major* changes, minor things don't have to be logged.

If there is a log file on that date, link it; if not, write the date manually