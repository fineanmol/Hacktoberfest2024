import _extends from "@babel/runtime/helpers/esm/extends";
import _objectWithoutProperties from "@babel/runtime/helpers/esm/objectWithoutProperties";
import * as React from 'react';
import PropTypes from 'prop-types';
import clsx from 'clsx';
import { capitalize } from '@material-ui/core/utils';
import { withStyles } from '@material-ui/core/styles';
export var styles = function styles(theme) {
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
var TimelineDot = /*#__PURE__*/React.forwardRef(function TimelineDot(props, ref) {
  var classes = props.classes,
      className = props.className,
      _props$color = props.color,
      color = _props$color === void 0 ? 'grey' : _props$color,
      _props$variant = props.variant,
      variant = _props$variant === void 0 ? 'default' : _props$variant,
      other = _objectWithoutProperties(props, ["classes", "className", "color", "variant"]);

  return /*#__PURE__*/React.createElement("span", _extends({
    className: clsx(classes.root, className, color !== 'inherit' && classes["".concat(variant).concat(capitalize(color))]),
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
  children: PropTypes.node,

  /**
   * Override or extend the styles applied to the component.
   * See [CSS API](#css) below for more details.
   */
  classes: PropTypes.object,

  /**
   * @ignore
   */
  className: PropTypes.string,

  /**
   * The dot can have a different colors.
   */
  color: PropTypes.oneOf(['grey', 'inherit', 'primary', 'secondary']),

  /**
   * The dot can appear filled or outlined.
   */
  variant: PropTypes.oneOf(['default', 'outlined'])
} : void 0;
export default withStyles(styles, {
  name: 'MuiTimelineDot'
})(TimelineDot);