/** @license Material-UI v4.11.5
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */
"use strict";

var _interopRequireWildcard = require("@babel/runtime/helpers/interopRequireWildcard");

Object.defineProperty(exports, "__esModule", {
  value: true
});
var _exportNames = {
  createGenerateClassName: true,
  createStyles: true,
  getThemeProps: true,
  jssPreset: true,
  makeStyles: true,
  mergeClasses: true,
  ServerStyleSheets: true,
  styled: true,
  StylesProvider: true,
  ThemeProvider: true,
  useTheme: true,
  withStyles: true,
  withTheme: true
};
Object.defineProperty(exports, "createGenerateClassName", {
  enumerable: true,
  get: function get() {
    return _createGenerateClassName.default;
  }
});
Object.defineProperty(exports, "createStyles", {
  enumerable: true,
  get: function get() {
    return _createStyles.default;
  }
});
Object.defineProperty(exports, "getThemeProps", {
  enumerable: true,
  get: function get() {
    return _getThemeProps.default;
  }
});
Object.defineProperty(exports, "jssPreset", {
  enumerable: true,
  get: function get() {
    return _jssPreset.default;
  }
});
Object.defineProperty(exports, "makeStyles", {
  enumerable: true,
  get: function get() {
    return _makeStyles.default;
  }
});
Object.defineProperty(exports, "mergeClasses", {
  enumerable: true,
  get: function get() {
    return _mergeClasses.default;
  }
});
Object.defineProperty(exports, "ServerStyleSheets", {
  enumerable: true,
  get: function get() {
    return _ServerStyleSheets.default;
  }
});
Object.defineProperty(exports, "styled", {
  enumerable: true,
  get: function get() {
    return _styled.default;
  }
});
Object.defineProperty(exports, "StylesProvider", {
  enumerable: true,
  get: function get() {
    return _StylesProvider.default;
  }
});
Object.defineProperty(exports, "ThemeProvider", {
  enumerable: true,
  get: function get() {
    return _ThemeProvider.default;
  }
});
Object.defineProperty(exports, "useTheme", {
  enumerable: true,
  get: function get() {
    return _useTheme.default;
  }
});
Object.defineProperty(exports, "withStyles", {
  enumerable: true,
  get: function get() {
    return _withStyles.default;
  }
});
Object.defineProperty(exports, "withTheme", {
  enumerable: true,
  get: function get() {
    return _withTheme.default;
  }
});

var _utils = require("@material-ui/utils");

var _createGenerateClassName = _interopRequireWildcard(require("./createGenerateClassName"));

Object.keys(_createGenerateClassName).forEach(function (key) {
  if (key === "default" || key === "__esModule") return;
  if (Object.prototype.hasOwnProperty.call(_exportNames, key)) return;
  Object.defineProperty(exports, key, {
    enumerable: true,
    get: function get() {
      return _createGenerateClassName[key];
    }
  });
});

var _createStyles = _interopRequireWildcard(require("./createStyles"));

Object.keys(_createStyles).forEach(function (key) {
  if (key === "default" || key === "__esModule") return;
  if (Object.prototype.hasOwnProperty.call(_exportNames, key)) return;
  Object.defineProperty(exports, key, {
    enumerable: true,
    get: function get() {
      return _createStyles[key];
    }
  });
});

var _getThemeProps = _interopRequireWildcard(require("./getThemeProps"));

Object.keys(_getThemeProps).forEach(function (key) {
  if (key === "default" || key === "__esModule") return;
  if (Object.prototype.hasOwnProperty.call(_exportNames, key)) return;
  Object.defineProperty(exports, key, {
    enumerable: true,
    get: function get() {
      return _getThemeProps[key];
    }
  });
});

var _jssPreset = _interopRequireWildcard(require("./jssPreset"));

Object.keys(_jssPreset).forEach(function (key) {
  if (key === "default" || key === "__esModule") return;
  if (Object.prototype.hasOwnProperty.call(_exportNames, key)) return;
  Object.defineProperty(exports, key, {
    enumerable: true,
    get: function get() {
      return _jssPreset[key];
    }
  });
});

var _makeStyles = _interopRequireWildcard(require("./makeStyles"));

Object.keys(_makeStyles).forEach(function (key) {
  if (key === "default" || key === "__esModule") return;
  if (Object.prototype.hasOwnProperty.call(_exportNames, key)) return;
  Object.defineProperty(exports, key, {
    enumerable: true,
    get: function get() {
      return _makeStyles[key];
    }
  });
});

var _mergeClasses = _interopRequireWildcard(require("./mergeClasses"));

Object.keys(_mergeClasses).forEach(function (key) {
  if (key === "default" || key === "__esModule") return;
  if (Object.prototype.hasOwnProperty.call(_exportNames, key)) return;
  Object.defineProperty(exports, key, {
    enumerable: true,
    get: function get() {
      return _mergeClasses[key];
    }
  });
});

var _ServerStyleSheets = _interopRequireWildcard(require("./ServerStyleSheets"));

Object.keys(_ServerStyleSheets).forEach(function (key) {
  if (key === "default" || key === "__esModule") return;
  if (Object.prototype.hasOwnProperty.call(_exportNames, key)) return;
  Object.defineProperty(exports, key, {
    enumerable: true,
    get: function get() {
      return _ServerStyleSheets[key];
    }
  });
});

var _styled = _interopRequireWildcard(require("./styled"));

Object.keys(_styled).forEach(function (key) {
  if (key === "default" || key === "__esModule") return;
  if (Object.prototype.hasOwnProperty.call(_exportNames, key)) return;
  Object.defineProperty(exports, key, {
    enumerable: true,
    get: function get() {
      return _styled[key];
    }
  });
});

var _StylesProvider = _interopRequireWildcard(require("./StylesProvider"));

Object.keys(_StylesProvider).forEach(function (key) {
  if (key === "default" || key === "__esModule") return;
  if (Object.prototype.hasOwnProperty.call(_exportNames, key)) return;
  Object.defineProperty(exports, key, {
    enumerable: true,
    get: function get() {
      return _StylesProvider[key];
    }
  });
});

var _ThemeProvider = _interopRequireWildcard(require("./ThemeProvider"));

Object.keys(_ThemeProvider).forEach(function (key) {
  if (key === "default" || key === "__esModule") return;
  if (Object.prototype.hasOwnProperty.call(_exportNames, key)) return;
  Object.defineProperty(exports, key, {
    enumerable: true,
    get: function get() {
      return _ThemeProvider[key];
    }
  });
});

var _useTheme = _interopRequireWildcard(require("./useTheme"));

Object.keys(_useTheme).forEach(function (key) {
  if (key === "default" || key === "__esModule") return;
  if (Object.prototype.hasOwnProperty.call(_exportNames, key)) return;
  Object.defineProperty(exports, key, {
    enumerable: true,
    get: function get() {
      return _useTheme[key];
    }
  });
});

var _withStyles = _interopRequireWildcard(require("./withStyles"));

Object.keys(_withStyles).forEach(function (key) {
  if (key === "default" || key === "__esModule") return;
  if (Object.prototype.hasOwnProperty.call(_exportNames, key)) return;
  Object.defineProperty(exports, key, {
    enumerable: true,
    get: function get() {
      return _withStyles[key];
    }
  });
});

var _withTheme = _interopRequireWildcard(require("./withTheme"));

Object.keys(_withTheme).forEach(function (key) {
  if (key === "default" || key === "__esModule") return;
  if (Object.prototype.hasOwnProperty.call(_exportNames, key)) return;
  Object.defineProperty(exports, key, {
    enumerable: true,
    get: function get() {
      return _withTheme[key];
    }
  });
});

/* eslint-disable import/export */

/* Warning if there are several instances of @material-ui/styles */
if (process.env.NODE_ENV !== 'production' && process.env.NODE_ENV !== 'test' && typeof window !== 'undefined') {
  _utils.ponyfillGlobal['__@material-ui/styles-init__'] = _utils.ponyfillGlobal['__@material-ui/styles-init__'] || 0;

  if (_utils.ponyfillGlobal['__@material-ui/styles-init__'] === 1) {
    console.warn(['It looks like there are several instances of `@material-ui/styles` initialized in this application.', 'This may cause theme propagation issues, broken class names, ' + 'specificity issues, and makes your application bigger without a good reason.', '', 'See https://mui.com/r/styles-instance-warning for more info.'].join('\n'));
  }

  _utils.ponyfillGlobal['__@material-ui/styles-init__'] += 1;
}