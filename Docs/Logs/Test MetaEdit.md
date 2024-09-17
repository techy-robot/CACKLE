---
options:
  - "1"
  - "2"
  - "3"
  - "5"
selected: 1
modified: 2024-04-24T22:21:25-06:00
---

Options: `INPUT[inlineList:options]`

```meta-bind-js-view
{options} as options
---
const options = context.bound.options.map(x => `option(${x})`).join(", ");
const str = `\`INPUT[inlineSelect(${options}):selected]\``;
return engine.markdown.create(str);
```