"use strict";

var _interopRequireDefault = require("@babel/runtime/helpers/interopRequireDefault");

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = exports.whiteSpace = exports.visibility = exports.textOverflow = exports.overflow = exports.displayRaw = exports.displayPrint = void 0;

var _style = _interopRequireDefault(require("./style"));

var _compose = _interopRequireDefault(require("./compose"));

var displayPrint = (0, _style.default)({
  prop: 'displayPrint',
  cssProperty: false,
  transform: function transform(value) {
    return {
      '@media print': {
        display: value
      }
    };
  }
});
exports.displayPrint = displayPrint;
var displayRaw = (0, _style.default)({
  prop: 'display'
});
exports.displayRaw = displayRaw;
var overflow = (0, _style.default)({
  prop: 'overflow'
});
exports.overflow = overflow;
var textOverflow = (0, _style.default)({
  prop: 'textOverflow'
});
exports.textOverflow = textOverflow;
var visibility = (0, _style.default)({
  prop: 'visibility'
});
exports.visibility = visibility;
var whiteSpace = (0, _style.default)({
  prop: 'whiteSpace'
});
exports.whiteSpace = whiteSpace;

var _default = (0, _compose.default)(displayPrint, displayRaw, overflow, textOverflow, visibility, whiteSpace);

exports.default = _default;