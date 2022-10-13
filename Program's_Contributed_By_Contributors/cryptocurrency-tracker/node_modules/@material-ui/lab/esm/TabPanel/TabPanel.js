import _extends from "@babel/runtime/helpers/esm/extends";
import _objectWithoutProperties from "@babel/runtime/helpers/esm/objectWithoutProperties";
import * as React from 'react';
import PropTypes from 'prop-types';
import clsx from 'clsx';
import { withStyles } from '@material-ui/core/styles';
import { getPanelId, getTabId, useTabContext } from '../TabContext';
export var styles = function styles(theme) {
  return {
    /* Styles applied to the root element. */
    root: {
      padding: theme.spacing(3)
    }
  };
};
var TabPanel = /*#__PURE__*/React.forwardRef(function TabPanel(props, ref) {
  var children = props.children,
      className = props.className,
      classes = props.classes,
      value = props.value,
      other = _objectWithoutProperties(props, ["children", "className", "classes", "value"]);

  var context = useTabContext();

  if (context === null) {
    throw new TypeError('No TabContext provided');
  }

  var id = getPanelId(context, value);
  var tabId = getTabId(context, value);
  return /*#__PURE__*/React.createElement("div", _extends({
    "aria-labelledby": tabId,
    className: clsx(classes.root, className),
    hidden: value !== context.value,
    id: id,
    ref: ref,
    role: "tabpanel"
  }, other), value === context.value && children);
});
process.env.NODE_ENV !== "production" ? TabPanel.propTypes = {
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
   * The `value` of the corresponding `Tab`. Must use the index of the `Tab` when
   * no `value` was passed to `Tab`.
   */
  value: PropTypes.string.isRequired
} : void 0;
export default withStyles(styles, {
  name: 'MuiTabPanel'
})(TabPanel);