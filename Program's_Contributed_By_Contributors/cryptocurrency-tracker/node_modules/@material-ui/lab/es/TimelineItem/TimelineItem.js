import _extends from "@babel/runtime/helpers/esm/extends";
import _objectWithoutPropertiesLoose from "@babel/runtime/helpers/esm/objectWithoutPropertiesLoose";
import * as React from 'react';
import PropTypes from 'prop-types';
import clsx from 'clsx';
import { capitalize, isMuiElement } from '@material-ui/core/utils';
import { withStyles } from '@material-ui/core/styles';
import TimelineContext from '../Timeline/TimelineContext';
import TimelineItemContext from './TimelineItemContext';
export const styles = () => ({
  /* Styles applied to the root element. */
  root: {
    listStyle: 'none',
    display: 'flex',
    position: 'relative',
    minHeight: 70
  },

  /* Styles applied to the root element if `align="left"`. */
  alignLeft: {},

  /* Styles applied to the root element if `align="right"`. */
  alignRight: {
    flexDirection: 'row-reverse'
  },

  /* Styles applied to the root element if `align="alternate"`. */
  alignAlternate: {
    '&:nth-child(even)': {
      flexDirection: 'row-reverse',
      '& $content': {
        textAlign: 'right'
      },
      '& $oppositeContent': {
        textAlign: 'left'
      }
    }
  },

  /* Styles applied to the root element if no there isn't TimelineOppositeContent provided. */
  missingOppositeContent: {
    '&:before': {
      content: '""',
      flex: 1,
      padding: '6px 16px'
    }
  },

  /* Styles applied to the timeline content node. */
  content: {},

  /* Styles applied to the timeline opposite content node. */
  oppositeContent: {}
});
const TimelineItem = /*#__PURE__*/React.forwardRef(function TimelineItem(props, ref) {
  const {
    classes,
    className
  } = props,
        other = _objectWithoutPropertiesLoose(props, ["classes", "className"]);

  const {
    align = 'left'
  } = React.useContext(TimelineContext);
  let hasOppositeContent = false;
  React.Children.forEach(props.children, child => {
    if (isMuiElement(child, ['TimelineOppositeContent'])) {
      hasOppositeContent = true;
    }
  });
  return /*#__PURE__*/React.createElement(TimelineItemContext.Provider, {
    value: {
      classes: {
        content: classes.content,
        oppositeContent: classes.oppositeContent
      }
    }
  }, /*#__PURE__*/React.createElement("li", _extends({
    className: clsx(classes.root, classes[`align${capitalize(align)}`], className, !hasOppositeContent && classes.missingOppositeContent),
    ref: ref
  }, other)));
});
process.env.NODE_ENV !== "production" ? TimelineItem.propTypes = {
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
  name: 'MuiTimelineItem'
})(TimelineItem);