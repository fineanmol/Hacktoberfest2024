# Change Log

## v2.0.2
### Bug Fixes
- Fix empty inline style attribute breaking rendering [#34](https://github.com/wrakky/react-html-parser/pull/34) ([kevinzwhuang](https://github.com/kevinzwhuang))

## v2.0.1
### Updates
- Added `preprocessNodes` option to ReactHTMLParser function. This function is passed the raw
node tree before `react-html-parser` processes it which it should return after any modifications
are made to it
- Exposed `htmlparser2` library
- Updated the demo site to React v16

## v2.0.0
### Breaking Changes
- ReactHtmlParser now decodes html entities by default
- html, head and body tags are no longer automatically converted to div tags
### Updates
- Add React v16 as a peer dependency
- Added new options parameter to ReactHtmlParser function with following properties:
  - `decodeEntities` (boolean: default true) - whether to decode HTML entities
  - `transform` (function) - function that can be used to transform parsed elements
- Tags and attributes with invalid formats are now ignored and prevent React from blowing up
### Bug Fixes
- Fixed bug where inline styles containing colons would not be generated correctly [#9](https://github.com/wrakky/react-html-parser/issues/9)

## v1.0.3
### Updates
- Added React v15 as a peer dependency
### Bug Fixes
- Match boolean attributes when defined with upper or lower case characters [#5](https://github.com/wrakky/react-html-parser/issues/5)

## v1.0.2
### Bug Fixes
- Don't add children to void elements such as img or br [#1](https://github.com/wrakky/react-html-parser/issues/1)
- Correctly render boolean attributes - disabled, checked, etc [#3](https://github.com/wrakky/react-html-parser/issues/3)

## v1.0.0
### Initial Release
- Render HTML elements and text
- Map HTML attribute names to React HTML prop names
- Convert inline style strings to React style object format
