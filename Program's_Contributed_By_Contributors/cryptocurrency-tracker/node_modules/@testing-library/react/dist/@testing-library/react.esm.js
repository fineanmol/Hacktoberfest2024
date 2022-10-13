import * as testUtils from 'react-dom/test-utils';
import _extends from '@babel/runtime/helpers/esm/extends';
import _asyncToGenerator from '@babel/runtime/helpers/esm/asyncToGenerator';
import _regeneratorRuntime from '@babel/runtime/regenerator';
import * as React from 'react';
import ReactDOM from 'react-dom';
import * as ReactDOMClient from 'react-dom/client';
import { fireEvent as fireEvent$1, configure, prettyDOM, getQueriesForElement } from '@testing-library/dom';
export * from '@testing-library/dom';

var domAct = testUtils.act;

function getGlobalThis() {
  /* istanbul ignore else */
  if (typeof globalThis !== 'undefined') {
    return globalThis;
  }
  /* istanbul ignore next */


  if (typeof self !== 'undefined') {
    return self;
  }
  /* istanbul ignore next */


  if (typeof window !== 'undefined') {
    return window;
  }
  /* istanbul ignore next */


  if (typeof global !== 'undefined') {
    return global;
  }
  /* istanbul ignore next */


  throw new Error('unable to locate global object');
}

function setIsReactActEnvironment(isReactActEnvironment) {
  getGlobalThis().IS_REACT_ACT_ENVIRONMENT = isReactActEnvironment;
}

function getIsReactActEnvironment() {
  return getGlobalThis().IS_REACT_ACT_ENVIRONMENT;
}

function withGlobalActEnvironment(actImplementation) {
  return function (callback) {
    var previousActEnvironment = getIsReactActEnvironment();
    setIsReactActEnvironment(true);

    try {
      // The return value of `act` is always a thenable.
      var callbackNeedsToBeAwaited = false;
      var actResult = actImplementation(function () {
        var result = callback();

        if (result !== null && typeof result === 'object' && typeof result.then === 'function') {
          callbackNeedsToBeAwaited = true;
        }

        return result;
      });

      if (callbackNeedsToBeAwaited) {
        var thenable = actResult;
        return {
          then: function then(resolve, reject) {
            thenable.then(function (returnValue) {
              setIsReactActEnvironment(previousActEnvironment);
              resolve(returnValue);
            }, function (error) {
              setIsReactActEnvironment(previousActEnvironment);
              reject(error);
            });
          }
        };
      } else {
        setIsReactActEnvironment(previousActEnvironment);
        return actResult;
      }
    } catch (error) {
      // Can't be a `finally {}` block since we don't know if we have to immediately restore IS_REACT_ACT_ENVIRONMENT
      // or if we have to await the callback first.
      setIsReactActEnvironment(previousActEnvironment);
      throw error;
    }
  };
}

var act = withGlobalActEnvironment(domAct);
/* eslint no-console:0 */

// dom-testing-library's version of fireEvent. The reason
// we make this distinction however is because we have
// a few extra events that work a bit differently

var fireEvent = function fireEvent() {
  return fireEvent$1.apply(void 0, arguments);
};

Object.keys(fireEvent$1).forEach(function (key) {
  fireEvent[key] = function () {
    return fireEvent$1[key].apply(fireEvent$1, arguments);
  };
}); // React event system tracks native mouseOver/mouseOut events for
// running onMouseEnter/onMouseLeave handlers
// @link https://github.com/facebook/react/blob/b87aabdfe1b7461e7331abb3601d9e6bb27544bc/packages/react-dom/src/events/EnterLeaveEventPlugin.js#L24-L31

var mouseEnter = fireEvent.mouseEnter;
var mouseLeave = fireEvent.mouseLeave;

fireEvent.mouseEnter = function () {
  mouseEnter.apply(void 0, arguments);
  return fireEvent.mouseOver.apply(fireEvent, arguments);
};

fireEvent.mouseLeave = function () {
  mouseLeave.apply(void 0, arguments);
  return fireEvent.mouseOut.apply(fireEvent, arguments);
};

var pointerEnter = fireEvent.pointerEnter;
var pointerLeave = fireEvent.pointerLeave;

fireEvent.pointerEnter = function () {
  pointerEnter.apply(void 0, arguments);
  return fireEvent.pointerOver.apply(fireEvent, arguments);
};

fireEvent.pointerLeave = function () {
  pointerLeave.apply(void 0, arguments);
  return fireEvent.pointerOut.apply(fireEvent, arguments);
};

var select = fireEvent.select;

fireEvent.select = function (node, init) {
  select(node, init); // React tracks this event only on focused inputs

  node.focus(); // React creates this event when one of the following native events happens
  // - contextMenu
  // - mouseUp
  // - dragEnd
  // - keyUp
  // - keyDown
  // so we can use any here
  // @link https://github.com/facebook/react/blob/b87aabdfe1b7461e7331abb3601d9e6bb27544bc/packages/react-dom/src/events/SelectEventPlugin.js#L203-L224

  fireEvent.keyUp(node, init);
}; // React event system tracks native focusout/focusin events for
// running blur/focus handlers
// @link https://github.com/facebook/react/pull/19186


var blur = fireEvent.blur;
var focus = fireEvent.focus;

fireEvent.blur = function () {
  fireEvent.focusOut.apply(fireEvent, arguments);
  return blur.apply(void 0, arguments);
};

fireEvent.focus = function () {
  fireEvent.focusIn.apply(fireEvent, arguments);
  return focus.apply(void 0, arguments);
};

configure({
  unstable_advanceTimersWrapper: function unstable_advanceTimersWrapper(cb) {
    return act(cb);
  },
  // We just want to run `waitFor` without IS_REACT_ACT_ENVIRONMENT
  // But that's not necessarily how `asyncWrapper` is used since it's a public method.
  // Let's just hope nobody else is using it.
  asyncWrapper: function () {
    var _asyncWrapper = _asyncToGenerator( /*#__PURE__*/_regeneratorRuntime.mark(function _callee(cb) {
      var previousActEnvironment;
      return _regeneratorRuntime.wrap(function _callee$(_context) {
        while (1) {
          switch (_context.prev = _context.next) {
            case 0:
              previousActEnvironment = getIsReactActEnvironment();
              setIsReactActEnvironment(false);
              _context.prev = 2;
              _context.next = 5;
              return cb();

            case 5:
              return _context.abrupt("return", _context.sent);

            case 6:
              _context.prev = 6;
              setIsReactActEnvironment(previousActEnvironment);
              return _context.finish(6);

            case 9:
            case "end":
              return _context.stop();
          }
        }
      }, _callee, null, [[2,, 6, 9]]);
    }));

    function asyncWrapper(_x) {
      return _asyncWrapper.apply(this, arguments);
    }

    return asyncWrapper;
  }(),
  eventWrapper: function eventWrapper(cb) {
    var result;
    act(function () {
      result = cb();
    });
    return result;
  }
}); // Ideally we'd just use a WeakMap where containers are keys and roots are values.
// We use two variables so that we can bail out in constant time when we render with a new container (most common use case)

/**
 * @type {Set<import('react-dom').Container>}
 */

var mountedContainers = new Set();
/**
 * @type Array<{container: import('react-dom').Container, root: ReturnType<typeof createConcurrentRoot>}>
 */

var mountedRootEntries = [];

function createConcurrentRoot(container, _ref) {
  var _hydrate = _ref.hydrate,
      ui = _ref.ui,
      WrapperComponent = _ref.wrapper;
  var root;

  if (_hydrate) {
    act(function () {
      root = ReactDOMClient.hydrateRoot(container, WrapperComponent ? /*#__PURE__*/React.createElement(WrapperComponent, null, ui) : ui);
    });
  } else {
    root = ReactDOMClient.createRoot(container);
  }

  return {
    hydrate: function hydrate() {
      /* istanbul ignore if */
      if (!_hydrate) {
        throw new Error('Attempted to hydrate a non-hydrateable root. This is a bug in `@testing-library/react`.');
      } // Nothing to do since hydration happens when creating the root object.

    },
    render: function render(element) {
      root.render(element);
    },
    unmount: function unmount() {
      root.unmount();
    }
  };
}

function createLegacyRoot(container) {
  return {
    hydrate: function hydrate(element) {
      ReactDOM.hydrate(element, container);
    },
    render: function render(element) {
      ReactDOM.render(element, container);
    },
    unmount: function unmount() {
      ReactDOM.unmountComponentAtNode(container);
    }
  };
}

function renderRoot(ui, _ref2) {
  var baseElement = _ref2.baseElement,
      container = _ref2.container,
      hydrate = _ref2.hydrate,
      queries = _ref2.queries,
      root = _ref2.root,
      WrapperComponent = _ref2.wrapper;

  var wrapUiIfNeeded = function wrapUiIfNeeded(innerElement) {
    return WrapperComponent ? /*#__PURE__*/React.createElement(WrapperComponent, null, innerElement) : innerElement;
  };

  act(function () {
    if (hydrate) {
      root.hydrate(wrapUiIfNeeded(ui), container);
    } else {
      root.render(wrapUiIfNeeded(ui), container);
    }
  });
  return _extends({
    container: container,
    baseElement: baseElement,
    debug: function debug(el, maxLength, options) {
      if (el === void 0) {
        el = baseElement;
      }

      return Array.isArray(el) ? // eslint-disable-next-line no-console
      el.forEach(function (e) {
        return console.log(prettyDOM(e, maxLength, options));
      }) : // eslint-disable-next-line no-console,
      console.log(prettyDOM(el, maxLength, options));
    },
    unmount: function unmount() {
      act(function () {
        root.unmount();
      });
    },
    rerender: function rerender(rerenderUi) {
      renderRoot(wrapUiIfNeeded(rerenderUi), {
        container: container,
        baseElement: baseElement,
        root: root
      }); // Intentionally do not return anything to avoid unnecessarily complicating the API.
      // folks can use all the same utilities we return in the first place that are bound to the container
    },
    asFragment: function asFragment() {
      /* istanbul ignore else (old jsdom limitation) */
      if (typeof document.createRange === 'function') {
        return document.createRange().createContextualFragment(container.innerHTML);
      } else {
        var template = document.createElement('template');
        template.innerHTML = container.innerHTML;
        return template.content;
      }
    }
  }, getQueriesForElement(baseElement, queries));
}

function render(ui, _temp) {
  var _ref3 = _temp === void 0 ? {} : _temp,
      container = _ref3.container,
      _ref3$baseElement = _ref3.baseElement,
      baseElement = _ref3$baseElement === void 0 ? container : _ref3$baseElement,
      _ref3$legacyRoot = _ref3.legacyRoot,
      legacyRoot = _ref3$legacyRoot === void 0 ? false : _ref3$legacyRoot,
      queries = _ref3.queries,
      _ref3$hydrate = _ref3.hydrate,
      hydrate = _ref3$hydrate === void 0 ? false : _ref3$hydrate,
      wrapper = _ref3.wrapper;

  if (!baseElement) {
    // default to document.body instead of documentElement to avoid output of potentially-large
    // head elements (such as JSS style blocks) in debug output
    baseElement = document.body;
  }

  if (!container) {
    container = baseElement.appendChild(document.createElement('div'));
  }

  var root; // eslint-disable-next-line no-negated-condition -- we want to map the evolution of this over time. The root is created first. Only later is it re-used so we don't want to read the case that happens later first.

  if (!mountedContainers.has(container)) {
    var createRootImpl = legacyRoot ? createLegacyRoot : createConcurrentRoot;
    root = createRootImpl(container, {
      hydrate: hydrate,
      ui: ui,
      wrapper: wrapper
    });
    mountedRootEntries.push({
      container: container,
      root: root
    }); // we'll add it to the mounted containers regardless of whether it's actually
    // added to document.body so the cleanup method works regardless of whether
    // they're passing us a custom container or not.

    mountedContainers.add(container);
  } else {
    mountedRootEntries.forEach(function (rootEntry) {
      // Else is unreachable since `mountedContainers` has the `container`.
      // Only reachable if one would accidentally add the container to `mountedContainers` but not the root to `mountedRootEntries`

      /* istanbul ignore else */
      if (rootEntry.container === container) {
        root = rootEntry.root;
      }
    });
  }

  return renderRoot(ui, {
    container: container,
    baseElement: baseElement,
    queries: queries,
    hydrate: hydrate,
    wrapper: wrapper,
    root: root
  });
}

function cleanup() {
  mountedRootEntries.forEach(function (_ref4) {
    var root = _ref4.root,
        container = _ref4.container;
    act(function () {
      root.unmount();
    });

    if (container.parentNode === document.body) {
      document.body.removeChild(container);
    }
  });
  mountedRootEntries.length = 0;
  mountedContainers.clear();
}

function renderHook(renderCallback, options) {
  if (options === void 0) {
    options = {};
  }

  var _options = options,
      initialProps = _options.initialProps,
      wrapper = _options.wrapper;
  var result = /*#__PURE__*/React.createRef();

  function TestComponent(_ref5) {
    var renderCallbackProps = _ref5.renderCallbackProps;
    var pendingResult = renderCallback(renderCallbackProps);
    React.useEffect(function () {
      result.current = pendingResult;
    });
    return null;
  }

  var _render = render( /*#__PURE__*/React.createElement(TestComponent, {
    renderCallbackProps: initialProps
  }), {
    wrapper: wrapper
  }),
      baseRerender = _render.rerender,
      unmount = _render.unmount;

  function rerender(rerenderCallbackProps) {
    return baseRerender( /*#__PURE__*/React.createElement(TestComponent, {
      renderCallbackProps: rerenderCallbackProps
    }));
  }

  return {
    result: result,
    rerender: rerender,
    unmount: unmount
  };
} // just re-export everything from dom-testing-library
/* eslint func-name-matching:0 */

var _process$env;
// or teardown then we'll automatically run cleanup afterEach test
// this ensures that tests run in isolation from each other
// if you don't like this then either import the `pure` module
// or set the RTL_SKIP_AUTO_CLEANUP env variable to 'true'.

if (typeof process === 'undefined' || !((_process$env = process.env) != null && _process$env.RTL_SKIP_AUTO_CLEANUP)) {
  // ignore teardown() in code coverage because Jest does not support it

  /* istanbul ignore else */
  if (typeof afterEach === 'function') {
    afterEach(function () {
      cleanup();
    });
  } else if (typeof teardown === 'function') {
    // Block is guarded by `typeof` check.
    // eslint does not support `typeof` guards.
    // eslint-disable-next-line no-undef
    teardown(function () {
      cleanup();
    });
  } // No test setup with other test runners available

  /* istanbul ignore else */


  if (typeof beforeAll === 'function' && typeof afterAll === 'function') {
    // This matches the behavior of React < 18.
    var previousIsReactActEnvironment = getIsReactActEnvironment();
    beforeAll(function () {
      previousIsReactActEnvironment = getIsReactActEnvironment();
      setIsReactActEnvironment(true);
    });
    afterAll(function () {
      setIsReactActEnvironment(previousIsReactActEnvironment);
    });
  }
}

export { act, cleanup, fireEvent, render, renderHook };
