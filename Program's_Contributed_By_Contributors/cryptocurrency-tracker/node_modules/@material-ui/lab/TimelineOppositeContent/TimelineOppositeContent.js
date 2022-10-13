"use strict";

var _interopRequireWildcard = require("@babel/runtime/helpers/interopRequireWildcard");

var _interopRequireDefault = require("@babel/runtime/helpers/interopRequireDefault");

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = exports.styles = void 0;

var _extends2 = _interopRequireDefault(require("@babel/runtime/helpers/extends"));

var _objectWithoutProperties2 = _interopRequireDefault(require("@babel/runtime/helpers/objectWithoutProperties"));

var React = _interopRequireWildcard(require("react"));

var _propTypes = _interopRequireDefault(require("prop-types"));

var _clsx = _interopRequireDefault(require("clsx"));

var _utils = require("@material-ui/core/utils");

var _styles = require("@material-ui/core/styles");

var _TimelineContext = _interopRequireDefault(require("../Timeline/TimelineContext"));

var _TimelineItemContext = _interopRequireDefault(require("../TimelineItem/TimelineItemContext"));

var styles = function styles() {
  return {
    /* Styles applied to the root element. */
    root: {
      padding: '6px 16px',
      marginRight: 'auto',
      textAlign: 'right',
      flex: 1
    },

    /* Styles applied to the root element if `align="right"`. */
    alignRight: {
      textAlign: 'left'
    }
  };
};

exports.styles = styles;
var TimelineOppositeContent = /*#__PURE__*/React.forwardRef(function TimelineOppositeContent(props, ref) {
  var classes = props.classes,
      className = props.className,
      other = (0, _objectWithoutProperties2.default)(props, ["classes", "className"]);

  var _React$useContext = React.useContext(_TimelineContext.default),
      _React$useContext$ali = _React$useContext.align,
      align = _React$useContext$ali === void 0 ? 'left' : _React$useContext$ali;

  var _React$useContext2 = React.useContext(_TimelineItemContext.default),
      _React$useContext2$cl = _React$useContext2.classes,
      contextClasses = _React$useContext2$cl === void 0 ? {} : _React$useContext2$cl;

  return /*#__PURE__*/React.createElement("div", (0, _extends2.default)({
    className: (0, _clsx.default)(classes.root, contextClasses.oppositeContent, classes["align".concat((0, _utils.capitalize)(align))], className),
    ref: ref
  }, other));
});
process.env.NODE_ENV !== "production" ? TimelineOppositeContent.propTypes = {
  // ----------------------------- Warning --------------------------------
  // | These PropTypes are generated from the TypeScript type definitions |
  // |     To update them edit the d.ts file and run "yarn proptypes"     |
  // ----------------------------------------------------------------------

  /**
   * The content of the component.
   */
  children: _propTypes.default.node,

  /**
   * Override or extend the styles applied to the component.
   * See [CSS API](#css) below for more details.
   */
  classes: _propTypes.default.object,

  /**
   * @ignore
   */
  className: _propTypes.default.string
} : void 0;
TimelineOppositeContent.muiName = 'TimelineOppositeContent';

var _default = (0, _styles.withStyles)(styles, {
  name: 'MuiTimelineOppositeContent'
})(TimelineOppositeContent);

exports.default = _default;