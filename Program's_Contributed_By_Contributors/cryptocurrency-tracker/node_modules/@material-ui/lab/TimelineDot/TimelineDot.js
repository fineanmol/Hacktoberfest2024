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

var styles = function styles(theme) {
  return {
    /* Styles applied to the root element. */
    root: {
      display: 'flex',
      alignSelf: 'baseline',
      borderStyle: 'solid',
      borderWidth: 2,
      padding: 4,
      borderRadius: '50%',
      boxShadow: theme.shadows[2],
      marginTop: 8,
      marginBottom: 8
    },

    /* Styles applied to the root element if `color="grey"` and `variant="default"`. */
    defaultGrey: {
      borderColor: 'transparent',
      color: theme.palette.grey[50],
      backgroundColor: theme.palette.grey[400]
    },

    /* Styles applied to the root element if `color="grey"` and `variant="outlined"`. */
    outlinedGrey: {
      boxShadow: 'none',
      color: theme.palette.grey.contrastText,
      borderColor: theme.palette.grey[400],
      backgroundColor: 'transparent'
    },

    /* Styles applied to the root element if `color="primary"` and `variant="default"`. */
    defaultPrimary: {
      borderColor: 'transparent',
      color: theme.palette.primary.contrastText,
      backgroundColor: theme.palette.primary.main
    },

    /* Styles applied to the root element if `color="primary"` and `variant="outlined"`. */
    outlinedPrimary: {
      boxShadow: 'none',
      backgroundColor: 'transparent',
      borderColor: theme.palette.primary.main
    },

    /* Styles applied to the root element if `color="secondary"` and `variant="default"`. */
    defaultSecondary: {
      borderColor: 'transparent',
      color: theme.palette.secondary.contrastText,
      backgroundColor: theme.palette.secondary.main
    },

    /* Styles applied to the root element if `color="secondary"` and `variant="outlined"`. */
    outlinedSecondary: {
      boxShadow: 'none',
      backgroundColor: 'transparent',
      borderColor: theme.palette.secondary.main
    }
  };
};

exports.styles = styles;
var TimelineDot = /*#__PURE__*/React.forwardRef(function TimelineDot(props, ref) {
  var classes = props.classes,
      className = props.className,
      _props$color = props.color,
      color = _props$color === void 0 ? 'grey' : _props$color,
      _props$variant = props.variant,
      variant = _props$variant === void 0 ? 'default' : _props$variant,
      other = (0, _objectWithoutProperties2.default)(props, ["classes", "className", "color", "variant"]);
  return /*#__PURE__*/React.createElement("span", (0, _extends2.default)({
    className: (0, _clsx.default)(classes.root, className, color !== 'inherit' && classes["".concat(variant).concat((0, _utils.capitalize)(color))]),
    ref: ref
  }, other));
});
process.env.NODE_ENV !== "production" ? TimelineDot.propTypes = {
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
  className: _propTypes.default.string,

  /**
   * The dot can have a different colors.
   */
  color: _propTypes.default.oneOf(['grey', 'inherit', 'primary', 'secondary']),

  /**
   * The dot can appear filled or outlined.
   */
  variant: _propTypes.default.oneOf(['default', 'outlined'])
} : void 0;

var _default = (0, _styles.withStyles)(styles, {
  name: 'MuiTimelineDot'
})(TimelineDot);

exports.default = _default;