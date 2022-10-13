"use strict";

var _interopRequireDefault = require("@babel/runtime/helpers/interopRequireDefault");

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = exports.justifySelf = exports.justifyItems = exports.alignSelf = exports.flexShrink = exports.flexGrow = exports.flex = exports.order = exports.alignContent = exports.alignItems = exports.justifyContent = exports.flexWrap = exports.flexDirection = exports.flexBasis = void 0;

var _style = _interopRequireDefault(require("./style"));

var _compose = _interopRequireDefault(require("./compose"));

var flexBasis = (0, _style.default)({
  prop: 'flexBasis'
});
exports.flexBasis = flexBasis;
var flexDirection = (0, _style.default)({
  prop: 'flexDirection'
});
exports.flexDirection = flexDirection;
var flexWrap = (0, _style.default)({
  prop: 'flexWrap'
});
exports.flexWrap = flexWrap;
var justifyContent = (0, _style.default)({
  prop: 'justifyContent'
});
exports.justifyContent = justifyContent;
var alignItems = (0, _style.default)({
  prop: 'alignItems'
});
exports.alignItems = alignItems;
var alignContent = (0, _style.default)({
  prop: 'alignContent'
});
exports.alignContent = alignContent;
var order = (0, _style.default)({
  prop: 'order'
});
exports.order = order;
var flex = (0, _style.default)({
  prop: 'flex'
});
exports.flex = flex;
var flexGrow = (0, _style.default)({
  prop: 'flexGrow'
});
exports.flexGrow = flexGrow;
var flexShrink = (0, _style.default)({
  prop: 'flexShrink'
});
exports.flexShrink = flexShrink;
var alignSelf = (0, _style.default)({
  prop: 'alignSelf'
});
exports.alignSelf = alignSelf;
var justifyItems = (0, _style.default)({
  prop: 'justifyItems'
});
exports.justifyItems = justifyItems;
var justifySelf = (0, _style.default)({
  prop: 'justifySelf'
});
exports.justifySelf = justifySelf;
var flexbox = (0, _compose.default)(flexBasis, flexDirection, flexWrap, justifyContent, alignItems, alignContent, order, flex, flexGrow, flexShrink, alignSelf, justifyItems, justifySelf);
var _default = flexbox;
exports.default = _default;