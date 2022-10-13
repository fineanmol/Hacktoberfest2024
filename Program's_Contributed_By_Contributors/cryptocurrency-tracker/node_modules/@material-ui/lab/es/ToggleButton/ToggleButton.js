import _objectWithoutPropertiesLoose from "@babel/runtime/helpers/esm/objectWithoutPropertiesLoose";
import _extends from "@babel/runtime/helpers/esm/extends";
// @inheritedComponent ButtonBase
import * as React from 'react';
import PropTypes from 'prop-types';
import clsx from 'clsx';
import { alpha, withStyles } from '@material-ui/core/styles';
import ButtonBase from '@material-ui/core/ButtonBase';
import { capitalize } from '@material-ui/core/utils';
export const styles = theme => ({
  /* Styles applied to the root element. */
  root: _extends({}, theme.typography.button, {
    boxSizing: 'border-box',
    borderRadius: theme.shape.borderRadius,
    padding: 11,
    border: `1px solid ${alpha(theme.palette.action.active, 0.12)}`,
    color: alpha(theme.palette.action.active, 0.38),
    '&$selected': {
      color: theme.palette.action.active,
      backgroundColor: alpha(theme.palette.action.active, 0.12),
      '&:hover': {
        backgroundColor: alpha(theme.palette.action.active, 0.15)
      },
      '& + &': {
        borderLeft: 0,
        marginLeft: 0
      }
    },
    '&$disabled': {
      color: alpha(theme.palette.action.disabled, 0.12)
    },
    '&:hover': {
      textDecoration: 'none',
      // Reset on mouse devices
      backgroundColor: alpha(theme.palette.text.primary, 0.05),
      '@media (hover: none)': {
        backgroundColor: 'transparent'
      },
      '&$disabled': {
        backgroundColor: 'transparent'
      }
    }
  }),

  /* Pseudo-class applied to the root element if `disabled={true}`. */
  disabled: {},

  /* Pseudo-class applied to the root element if `selected={true}`. */
  selected: {},

  /* Styles applied to the `label` wrapper element. */
  label: {
    width: '100%',
    // Ensure the correct width for iOS Safari
    display: 'inherit',
    alignItems: 'inherit',
    justifyContent: 'inherit'
  },

  /* Styles applied to the root element if `size="small"`. */
  sizeSmall: {
    padding: 7,
    fontSize: theme.typography.pxToRem(13)
  },

  /* Styles applied to the root element if `size="large"`. */
  sizeLarge: {
    padding: 15,
    fontSize: theme.typography.pxToRem(15)
  }
});
const ToggleButton = /*#__PURE__*/React.forwardRef(function ToggleButton(props, ref) {
  const {
    children,
    classes,
    className,
    disabled = false,
    disableFocusRipple = false,
    onChange,
    onClick,
    selected,
    size = 'medium',
    value
  } = props,
        other = _objectWithoutPropertiesLoose(props, ["children", "classes", "className", "disabled", "disableFocusRipple", "onChange", "onClick", "selected", "size", "value"]);

  const handleChange = event => {
    if (onClick) {
      onClick(event, value);

      if (event.isDefaultPrevented()) {
        return;
      }
    }

    if (onChange) {
      onChange(event, value);
    }
  };

  return /*#__PURE__*/React.createElement(ButtonBase, _extends({
    className: clsx(classes.root, className, disabled && classes.disabled, selected && classes.selected, size !== 'medium' && classes[`size${capitalize(size)}`]),
    disabled: disabled,
    focusRipple: !disableFocusRipple,
    ref: ref,
    onClick: handleChange,
    onChange: onChange,
    value: value,
    "aria-pressed": selected
  }, other), /*#__PURE__*/React.createElement("span", {
    className: classes.label
  }, children));
});
process.env.NODE_ENV !== "production" ? ToggleButton.propTypes = {
  /**
   * The content of the button.
   */
  children: PropTypes.node.isRequired,

  /**
   * Override or extend the styles applied to the component.
   * See [CSS API](#css) below for more details.
   */
  classes: PropTypes.object.isRequired,

  /**
   * @ignore
   */
  className: PropTypes.string,

  /**
   * If `true`, the button will be disabled.
   */
  disabled: PropTypes.bool,

  /**
   * If `true`, the  keyboard focus ripple will be disabled.
   */
  disableFocusRipple: PropTypes.bool,

  /**
   * If `true`, the ripple effect will be disabled.
   */
  disableRipple: PropTypes.bool,

  /**
   * @ignore
   */
  onChange: PropTypes.func,

  /**
   * @ignore
   */
  onClick: PropTypes.func,

  /**
   * If `true`, the button will be rendered in an active state.
   */
  selected: PropTypes.bool,

  /**
   * @ignore
   */
  size: PropTypes.oneOf(['small', 'medium', 'large']),

  /**
   * The value to associate with the button when selected in a
   * ToggleButtonGroup.
   */
  value: PropTypes.any.isRequired
} : void 0;
export default withStyles(styles, {
  name: 'MuiToggleButton'
})(ToggleButton);