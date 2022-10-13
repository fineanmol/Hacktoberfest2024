import _extends from "@babel/runtime/helpers/esm/extends";
import _objectWithoutPropertiesLoose from "@babel/runtime/helpers/esm/objectWithoutPropertiesLoose";
import * as React from 'react';
import PropTypes from 'prop-types';
import clsx from 'clsx';
import { withStyles } from '@material-ui/core/styles';
export const styles = theme => ({
  /* Styles applied to the root element. */
  root: {
    width: 2,
    backgroundColor: theme.palette.grey[400],
    flexGrow: 1
  }
});
const TimelineConnector = /*#__PURE__*/React.forwardRef(function TimelineConnector(props, ref) {
  const {
    classes,
    className
  } = props,
        other = _objectWithoutPropertiesLoose(props, ["classes", "className"]);

  return /*#__PURE__*/React.createElement("span", _extends({
    className: clsx(classes.root, className),
    ref: ref
  }, other));
});
process.env.NODE_ENV !== "production" ? TimelineConnector.propTypes = {
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
  className: PropTypes.string
} : void 0;
export default withStyles(styles, {
  name: 'MuiTimelineConnector'
})(TimelineConnector);