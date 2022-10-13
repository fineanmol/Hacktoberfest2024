import _extends from "@babel/runtime/helpers/esm/extends";
import _objectWithoutPropertiesLoose from "@babel/runtime/helpers/esm/objectWithoutPropertiesLoose";
import * as React from 'react';
import PropTypes from 'prop-types';
import clsx from 'clsx';
import { capitalize } from '@material-ui/core/utils';
import { withStyles } from '@material-ui/core/styles';
import TimelineContext from './TimelineContext';
export const styles = () => ({
  /* Styles applied to the root element. */
  root: {
    display: 'flex',
    flexDirection: 'column',
    padding: '6px 16px',
    flexGrow: 1
  },

  /* Styles applied to the root element if `align="left"`. */
  alignLeft: {},

  /* Styles applied to the root element if `align="right"`. */
  alignRight: {},

  /* Styles applied to the root element if `align="alternate"`. */
  alignAlternate: {}
});
const Timeline = /*#__PURE__*/React.forwardRef(function Timeline(props, ref) {
  const {
    align = 'left',
    classes,
    className
  } = props,
        other = _objectWithoutPropertiesLoose(props, ["align", "classes", "className"]);

  return /*#__PURE__*/React.createElement(TimelineContext.Provider, {
    value: {
      align
    }
  }, /*#__PURE__*/React.createElement("ul", _extends({
    className: clsx(classes.root, classes[`align${capitalize(align)}`], className),
    ref: ref
  }, other)));
});
process.env.NODE_ENV !== "production" ? Timeline.propTypes = {
  // ----------------------------- Warning --------------------------------
  // | These PropTypes are generated from the TypeScript type definitions |
  // |     To update them edit the d.ts file and run "yarn proptypes"     |
  // ----------------------------------------------------------------------

  /**
   * The position where the timeline's content should appear.
   */
  align: PropTypes.oneOf(['alternate', 'left', 'right']),

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
  name: 'MuiTimeline'
})(Timeline);