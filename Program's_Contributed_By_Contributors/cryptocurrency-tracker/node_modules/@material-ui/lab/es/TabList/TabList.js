import _extends from "@babel/runtime/helpers/esm/extends";
import _objectWithoutPropertiesLoose from "@babel/runtime/helpers/esm/objectWithoutPropertiesLoose";
import * as React from 'react';
import * as PropTypes from 'prop-types';
import Tabs from '@material-ui/core/Tabs';
import { useTabContext, getTabId, getPanelId } from '../TabContext';
const TabList = /*#__PURE__*/React.forwardRef(function TabList(props, ref) {
  const {
    children: childrenProp
  } = props,
        other = _objectWithoutPropertiesLoose(props, ["children"]);

  const context = useTabContext();

  if (context === null) {
    throw new TypeError('No TabContext provided');
  }

  const children = React.Children.map(childrenProp, child => {
    return /*#__PURE__*/React.cloneElement(child, {
      // SOMEDAY: `Tabs` will set those themselves
      'aria-controls': getPanelId(context, child.props.value),
      id: getTabId(context, child.props.value)
    });
  });
  return /*#__PURE__*/React.createElement(Tabs, _extends({}, other, {
    ref: ref,
    value: context.value
  }), children);
});
process.env.NODE_ENV !== "production" ? TabList.propTypes = {
  children: PropTypes.arrayOf(PropTypes.element)
} : void 0;
export default TabList;