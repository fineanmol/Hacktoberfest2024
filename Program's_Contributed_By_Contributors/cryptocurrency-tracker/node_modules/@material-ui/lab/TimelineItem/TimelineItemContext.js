"use strict";

var _interopRequireWildcard = require("@babel/runtime/helpers/interopRequireWildcard");

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = void 0;

var React = _interopRequireWildcard(require("react"));

/**
 * @ignore - internal component.
 */
var TimelineItemContext = React.createContext({});

if (process.env.NODE_ENV !== 'production') {
  TimelineItemContext.displayName = 'TimelineItemContext';
}

var _default = TimelineItemContext;
exports.default = _default;