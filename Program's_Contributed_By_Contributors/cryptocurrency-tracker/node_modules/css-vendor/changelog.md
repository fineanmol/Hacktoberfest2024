## 2.0.7 / 2019-10-04

- Return parameters for transition/transition-property without prefix if they don't need to be prefixed
- Update dependencies

## 2.0.6 / 2019-08-15

- Freed from prefixing values when content property used
- Update dependencies

## 2.0.5 / 2019-06-20

- Freed from prefixing values with custom CSS variables for transition/transition-property properties

## 2.0.4 / 2019-06-15

- Fixed server compatibility

## 2.0.3 / 2019-06-15

- Added support for text-orientation property
- Removed support for text-decoration-skip-ink property
- Exempt properties which starts from '-' (already prefixed properties) or '--' (custom CSS variables) from prefixing 
- Update dependencies

## 2.0.2 / 2019-04-08

- Fix prefix for backdrop-filter on Edge 17/18

## 2.0.1 / 2019-03-21

- Fix prefixing values
- Update dependencies

## 2.0.0 / 2019-02-11

- Remove default exports

## 1.2.1 / 2019-02-11

- Fix prefixing flex value for IE 10
- Workaround esm with default export

## 1.2.0 / 2019-02-10

- Support for inline props syntax. e.g. border-inline-end, margin-inline-start
- Support place-self
- Support text-decoration-skip-ink
- Bundle with rollup
- Add prettier

## 1.1.0 / 2018-07-08

- Added supportedKeyframes function, to prefix @keyframes at-rule

## 1.0.4 / 2018-07-04

- Fix for dashed property values

## 1.0.3 / 2018-02-15

- Fixed functions in values

## 1.0.2 / 2018-01-22

- Catch errors when testing a property

## 1.0.1 / 2018-01-15

- Fix Number.isNaN

## 1.0.0 / 2018-01-02

- Added support for various properties for old browsers, undetectable with feature tests:
  - appearance
  - break-*
  - clip-path
  - filter
  - flex
  - (border|margin|padding)-inline
  - mask-*
  - scroll-snap
  - transform
  - transition
  - writing-mode
- Use autoprefixer data to generate tests for full compatibility.

## 0.3.8 / 2016-11-17

- better cache prefill
- fix supportedValue
- migrate tests
- introduce browserstack config and travis

## 0.3.7 / 2016-10-31

- use cross-env
- use is-in-browser

## 0.3.6 / 2016-10-17

- cheeck webkit prefix as last, because other browsers use it as well
- update deps

## 0.3.5 / 2016-08-23

- better browser env detection
- update deps

## 0.3.4 / 2016-06-15

- catch IE exceptions when feature testing a value

## 0.3.3 / 2015-04-13

- do nothing server-side

## 0.3.2 / 2015-03-24

- update babel, lint

## 0.3.1 / 2015-10-21

- release package with lib dir

## 0.3.0 / 2015-10-21

- migrate to ES6 with babel
- remove bower.json
- simplify packaging

## 0.2.5 / 2014-22-09

- make it requirable serverside

## 0.2.4 / 2014-21-09

- make it requirable serverside

## 0.2.3 / 2014-02-08

- don't make feature tests for values like '10px'

## 0.2.2 / 2014-02-08

- slightly change the api - now always return the corrected value, even if prefix is not needed

## 0.2.0 / 2014-02-07

- add supported value feature test

## 0.1.0 / 2014-11-29

- first release in a separate repository for plugins
