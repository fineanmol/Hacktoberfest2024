[![Build Status](https://travis-ci.org/cssinjs/css-vendor.svg?branch=master)](https://travis-ci.org/cssinjs/css-vendor) [![Greenkeeper badge](https://badges.greenkeeper.io/cssinjs/css-vendor.svg)](https://greenkeeper.io/)

## CSS vendor prefix detection and property feature testing.

### Vendor prefixes

```javascript
console.log(cssVendor.prefix.js) // e.g. WebkitTransform

console.log(cssVendor.prefix.css) // e.g. -webkit-transform
```

### Property support feature test

`cssVendor.supportedProperty(prop)`

Test if property is supported, returns false if not. Returns string if supported. May add a vendor prefix if needed.

```javascript
console.log(cssVendor.supportedProperty('animation')) // e.g. -webkit-animation
```

### Value support feature test

`cssVendor.supportedValue(prop, value)`

Test if value is supported, returns false if not. Returns string if supported. May add a vendor prefix if needed.

```javascript
console.log(cssVendor.supportedValue('display', 'flex')) // e.g. -webkit-flex
```

## Run tests

```bash
yarn
yarn test
```

## License

MIT
