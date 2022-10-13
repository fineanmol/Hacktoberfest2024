"use strict";

var _interopRequireDefault = require("@babel/runtime/helpers/interopRequireDefault");

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = jssPreset;

var _jssPluginRuleValueFunction = _interopRequireDefault(require("jss-plugin-rule-value-function"));

var _jssPluginGlobal = _interopRequireDefault(require("jss-plugin-global"));

var _jssPluginNested = _interopRequireDefault(require("jss-plugin-nested"));

var _jssPluginCamelCase = _interopRequireDefault(require("jss-plugin-camel-case"));

var _jssPluginDefaultUnit = _interopRequireDefault(require("jss-plugin-default-unit"));

var _jssPluginVendorPrefixer = _interopRequireDefault(require("jss-plugin-vendor-prefixer"));

var _jssPluginPropsSort = _interopRequireDefault(require("jss-plugin-props-sort"));

// Subset of jss-preset-default with only the plugins the Material-UI components are using.
function jssPreset() {
  return {
    plugins: [(0, _jssPluginRuleValueFunction.default)(), (0, _jssPluginGlobal.default)(), (0, _jssPluginNested.default)(), (0, _jssPluginCamelCase.default)(), (0, _jssPluginDefaultUnit.default)(), // Disable the vendor prefixer server-side, it does nothing.
    // This way, we can get a performance boost.
    // In the documentation, we are using `autoprefixer` to solve this problem.
    typeof window === 'undefined' ? null : (0, _jssPluginVendorPrefixer.default)(), (0, _jssPluginPropsSort.default)()]
  };
}