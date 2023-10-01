

// A memoized function is a function that will never be called twice with the same inputs. Instead it will return a cached value.
// fn can be any function and there are no constraints on what type of values it accepts. Inputs are considered identical if they are === to each other.

function memoize(fn) {
  const cache = new Map();

  function explore(args) {
    let node = cache;
    for (const arg of args) {
      if (!node.has(arg)) {
        node.set(arg, new Map());
      }
      node = node.get(arg);
    }

    if (node.has('value')) {
      return node.get('value');
    } else {
      const value = fn(...args);
      node.set('value', value);
      return value;
    }
  }

  return function memoized(...args) {
    return explore(args);
  };
}
