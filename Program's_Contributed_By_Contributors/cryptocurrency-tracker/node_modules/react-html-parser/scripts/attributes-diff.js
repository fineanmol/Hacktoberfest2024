// this script diffs the react attribute whitelist with the one react html parser maintains
// to determine if it is out of date
// the build:lib task must have been run before this can work

const currentProperties = require('../lib/dom/attributes/ReactAttributes').default;
const reactProperties = require('react-dom/lib/HTMLDOMPropertyConfig').Properties;

const changes = {};

const currentKeys = Object.keys(currentProperties).map(key => currentProperties[key]);
const reactKeys = Object.keys(reactProperties);

// attributes that have been added to react
reactKeys.forEach(key => {
  if (currentKeys.indexOf(key) === -1) {
    changes[key] = 'add';
  }
});

// attributes that have been removed from react
currentKeys.forEach(key => {
  if (reactKeys.indexOf(key) === -1) {
    changes[key] = 'remove';
  }
});

console.log(changes); // eslint-disable-line no-console
