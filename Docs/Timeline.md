---
modified: 2024-09-16T20:09:19-06:00
---
axis_format:: %Y-%b
duration::6 months

```dataviewjs
function taskParser(task, currIndex) {
    //This expects a dataview Page

    let mermaidLine = ``;//multi-line string
    
    //Remove the date from the filename if included
    let namestart = task.file.name.toString();
    const re = new RegExp(/^.*(\d\d\d\d-\d\d-\d\d)(.*)$/);
    let name = namestart.replace(re, "$2");

    //---------------Task Type flags--------------
    
    // I am using the task system to instead color types of action items
    let mile = "";
    let stats = "";
    if (task.itemtype!==undefined) {
        if (task.itemtype === "milestone") {
            mile += "milestone, ";
            stats += "done, ";//grey

            //If it is a milestone also add a section header
            mermaidLine += `section ` + name + `\n`;
        }
        else if (task.itemtype === "subtask") {
            stats += "active, ";//white
        }
        else {
            stats = "";//accent color for normal tasks
        }
        
    }
    
    let critStat = "";
    if (task.priority!==undefined && task.priority === "Critical") {
        critStat = "crit, ";//red boarder
    } else {
        critStat = "";
    }

    //---------------Time-------------------
    let dueDate = "";
    if (task.deadline!==undefined && task.deadline != null) {
        dueDate = task.deadline.toFormat("yyyy-MM-dd");
    }

    let endDate = "";
    if (task.endDate!==undefined && task.endDate != null) {
        endDate = task.endDate.toFormat("yyyy-MM-dd");
    }

    let startDate = "";
    if (task.date!==undefined && task.date != null) {
        startDate = task.date.toFormat("yyyy-MM-dd");
    }

    let skip = false;//Should it skip this whole task b/c of missing varieble?

    let start = "";
    let end = "";
    //If it has a start date and end date
    if (startDate.length > 0  && endDate.length > 0) {
        start += startDate;
        end += endDate;
    }
    //If it thas a start date and a due date
    else if (startDate.length > 0  && dueDate.length > 0) {
        start += startDate;
        end += dueDate;
    }
    //If it has an end date and a due date
    else if (startDate.length == 0 && endDate.length > 0 && dueDate.length > 0) {
        start += endDate;
        end += dueDate;
    }
    else {
        skip = true;
    }
    //If it has a duration?

    currIndex = currIndex + ", ";
    
    let c = name.charAt(0);
    
    //Mermaid can't parse numbers in a title if it is the first character
    if (c >= '0' && c <= '9') {
        name = "." + name;
    }

    if (skip && mile.length == 0) {
        mermaidLine == ``;//if it doesn't have required dates
    }
    else if (task === undefined ){//If it is undefined, just create a section called undefined.
	    mermaidLine += `section undefined\n`;
    }
    else if (skip && mile.length > 0 && startDate.length > 0)//If it has milestone only
	    mermaidLine += name + ` : ` + mile + critStat + stats + currIndex + start + `, 0d \n`;
    else if (mile.length > 0) {//If it has both dates and milestone flag
        mermaidLine += name + ` : ` + critStat + stats + currIndex + start + ", " + end + `\n`;//draw time bar
        mermaidLine += `.` + ` : ` + mile + critStat + stats + currIndex + end + `, 0d\n`;//draw the milestone
    }
    else {
	    mermaidLine += name + ` : ` + critStat + stats + currIndex + start + ", " + end + `\n`;//draw a normal bar
    }

    return mermaidLine;
}

function recursiveOutlinks(inputPage) {
    let pages = new Set();
    let stack = [inputPage];//required for starting. This is the top level of the files you want to explore

    pages.add(inputPage);//optional, includes the current starting page in the result
    
    while (stack.length > 0) {
        let elem = stack.pop();
        let meta = dv.page(elem);
        if (!meta || meta.subitems === undefined || meta.subitems == null) continue; /* ignore links to pages that don't exist yet, and ignore processing the page if it doesn't have subitems */
        
        let outlinks;//should be an array of links
        // || meta.subitems.length === undefined
        if (meta.subitems.length == 1) {
            outlinks = [dv.parse(meta.subitems[0].toString())];
        }
        else if (meta.subitems.length === undefined) {
            outlinks = [dv.parse(meta.subitems.toString())];
        }
        else {
            //I think sort only works on dataarrays, and subitems is a normal array...
	        //converts array of links to array of pages
	        outlinks = meta.subitems.map(l => dv.page(l));
	        //sorts pages by start date
	        
            outlinks = dv.array(outlinks).sort(s => s.date, 'asc');
            //converts pages to an array of links
            outlinks = outlinks.map(p => p.file.link);
        }


        for (let linkedFile of outlinks) {

            if (pages.has(linkedFile.path)) continue; /* only look at pages we haven't seen yet, otherwise we could get stuck following circular links forever */
            pages.add(linkedFile.path);
            stack.push(linkedFile.path);
        }
    }
    // Data is now the file metadata for every page that is directly OR indirectly linked BY the current page
    return dv.array(Array.from(pages)).map(p => dv.page(p));
}


//Right now I'm thinking calling the function recursivly is more efficient than splicing an array. Try both first.
function loopGantt(milestonePages) {
    let mermaidlines = ``;

	//for each milestone section
    for (let k = 0; k < milestonePages.length; k++) {

        //Finds all tasks that link to this milestone. Note that this is thrown off if you crosslink stuff, because I don't h
        let pageGroup = milestonePages[k].file.inlinks.map(p => dv.page(p)).where(p => p.itemtype == "task");

	    //create milestone section and bar
	    try {
		    mermaidlines += taskParser(milestonePages[k], "mile" + k);
		}
		catch {
			mermaidlines += `section ` + milestonePages[k].file.name + `\n`;
		}
		let data;
		pageGroup = pageGroup.sort(s => s.date, 'asc');
	
	    //Iterate over top level tasks (for the milestone) and find all sub tasks
	    
	    //For some reason the for loop fails if length is 0, even though it should already skip it.
	    if (pageGroup.length !== 0) {
    	    for (let i = 0; i < pageGroup.length; i++) {
        	    //if it is the first value it can't concat
        	    if (data === undefined) {
            	    data = recursiveOutlinks(pageGroup[i].file.path);
        	    }
        	    else {
            	    data = data.concat(recursiveOutlinks(pageGroup[i].file.path));
        	    }
    		}
    		//Iterate over the subtasks found
    		for (let i = 0; i < data.length; i++) {
    			mermaidlines += taskParser(data[i], "mile" + k + "task" + i);
    		}
		}
		
	}


    //Another loop to pull all tasks without milestone.
    let tasks = dv.pages('-"Templates"')
    .where(p => p.itemtype == "task")
    .where(p => p.milestone == null || p.milestone == undefined);
	
	let data;
	tasks = tasks.sort(s => s.date, 'asc');
	//Iterate over top level tasks and find all sub tasks
	//For some reason the for loop fails if length is 0, even though it should already skip it.
	if (tasks.length !== 0) {
	    for (let i = 0; i < tasks.length; i++) {
    	    //if it is the first value it can't concat
    	    if (data === undefined) {
        	    data = recursiveOutlinks(tasks[i].file.path);
    	    }
    	    else {
        	    data = data.concat(recursiveOutlinks(tasks[i].file.path));
    	    }
		}

        mermaidlines += `section undefined\n`;
		//Iterate over the subtasks found
		for (let i = 0; i < data.length; i++) {
			mermaidlines += taskParser(data[i], "mile" + milestonePages.length + "task" + i);
		}
	}

    return mermaidlines;
}

const Mermaid = `gantt
    dateFormat YYYY-MM-DD
    title Timeline
    tickInterval 1month
    weekday monday
    axisFormat  ` + dv.current().axis_format + ` \n `;

// Change the query below to match your needs, but this might throw off the whole system. I have another query above for "undefined"
//Current query finds milestone files and sorts by date. Then it will search tasks that link to the milestone.
let query = dv.pages('-"Docs/Templates"')
.where(p => p.itemtype == "milestone")
.sort(p => p.date, "asc");

//add dummy task so that today's date is always shown:
//let today = new Date().toISOString().slice(0, 10); 
let today = dv.date('today').plus(dv.duration(dv.current().duration)).toISODate(); 

dv.paragraph('```mermaid\n' + Mermaid + loopGantt(query)+ ". :active, " + today + ", " + today + "\n\n" + '\n```');

//digonstic rendering. Uncomment to get a render of the mermaid text
//dv.paragraph('```\n' + Mermaid + loopGantt(query)+ ". :active, " + today + ", " + today + "\n\n" + '\n```');

```

Colors:
- Grey - Milestone
- Accent Color - Task
- White - subtask
- Red - critical task

All elements that are missing an essential component will be skipped.

Milestones are rendered as a date box plus the milestone. All tasks that link the milestone will be placed in the milestone section, and any task that doesn't have a milestone will go in the undefined section. Sub tasks will be placed under their parent tasks.

I need to have a DQL section under milestones that queries for all tasks that explicitly reference that milestone. Maybe recursively, or maybe not

I need another diagram of different type to actually show the action item relationships, because mermaid gantt can't show that 😒. 