"use strict";

var _interopRequireDefault = require("@babel/runtime/helpers/interopRequireDefault");

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = useTheme;

var _react = _interopRequireDefault(require("react"));

var _ThemeContext = _interopRequireDefault(require("./ThemeContext"));

function useTheme() {
  var theme = _react.default.useContext(_ThemeContext.default);

  if (process.env.NODE_ENV !== 'production') {
    // eslint-disable-next-line react-hooks/rules-of-hooks
    _react.default.useDebugValue(theme);
  }

  return theme;
}