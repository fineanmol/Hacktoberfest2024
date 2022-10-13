"use strict";

var _interopRequireWildcard = require("@babel/runtime/helpers/interopRequireWildcard");

var _interopRequireDefault = require("@babel/runtime/helpers/interopRequireDefault");

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = void 0;

var _extends2 = _interopRequireDefault(require("@babel/runtime/helpers/extends"));

var _objectWithoutProperties2 = _interopRequireDefault(require("@babel/runtime/helpers/objectWithoutProperties"));

var React = _interopRequireWildcard(require("react"));

var PropTypes = _interopRequireWildcard(require("prop-types"));

var _Tabs = _interopRequireDefault(require("@material-ui/core/Tabs"));

var _TabContext = require("../TabContext");

var TabList = /*#__PURE__*/React.forwardRef(function TabList(props, ref) {
  var childrenProp = props.children,
      other = (0, _objectWithoutProperties2.default)(props, ["children"]);
  var context = (0, _TabContext.useTabContext)();

  if (context === null) {
    throw new TypeError('No TabContext provided');
  }

  var children = React.Children.map(childrenProp, function (child) {
    return /*#__PURE__*/React.cloneElement(child, {
      // SOMEDAY: `Tabs` will set those themselves
      'aria-controls': (0, _TabContext.getPanelId)(context, child.props.value),
      id: (0, _TabContext.getTabId)(context, child.props.value)
    });
  });
  return /*#__PURE__*/React.createElement(_Tabs.default, (0, _extends2.default)({}, other, {
    ref: ref,
    value: context.value
  }), children);
});
process.env.NODE_ENV !== "production" ? TabList.propTypes = {
  children: PropTypes.arrayOf(PropTypes.element)
} : void 0;
var _default = TabList;
exports.default = _default;