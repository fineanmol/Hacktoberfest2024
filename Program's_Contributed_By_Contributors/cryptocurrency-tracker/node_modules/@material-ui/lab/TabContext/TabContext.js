"use strict";

var _interopRequireWildcard = require("@babel/runtime/helpers/interopRequireWildcard");

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = TabContext;
exports.useTabContext = useTabContext;
exports.getPanelId = getPanelId;
exports.getTabId = getTabId;

var React = _interopRequireWildcard(require("react"));

var PropTypes = _interopRequireWildcard(require("prop-types"));

/**
 * @type {React.Context<{ idPrefix: string; value: string } | null>}
 */
var Context = React.createContext(null);

if (process.env.NODE_ENV !== 'production') {
  Context.displayName = 'TabContext';
}

function useUniquePrefix() {
  var _React$useState = React.useState(null),
      id = _React$useState[0],
      setId = _React$useState[1];

  React.useEffect(function () {
    setId("mui-p-".concat(Math.round(Math.random() * 1e5)));
  }, []);
  return id;
}

function TabContext(props) {
  var children = props.children,
      value = props.value;
  var idPrefix = useUniquePrefix();
  var context = React.useMemo(function () {
    return {
      idPrefix: idPrefix,
      value: value
    };
  }, [idPrefix, value]);
  return /*#__PURE__*/React.createElement(Context.Provider, {
    value: context
  }, children);
}

process.env.NODE_ENV !== "production" ? TabContext.propTypes = {
  // ----------------------------- Warning --------------------------------
  // | These PropTypes are generated from the TypeScript type definitions |
  // |     To update them edit the d.ts file and run "yarn proptypes"     |
  // ----------------------------------------------------------------------

  /**
   * The content of the component.
   */
  children: PropTypes.node,

  /**
   * The value of the currently selected `Tab`.
   */
  value: PropTypes.string.isRequired
} : void 0;
/**
 * @returns {unknown}
 */

function useTabContext() {
  return React.useContext(Context);
}

function getPanelId(context, value) {
  var idPrefix = context.idPrefix;

  if (idPrefix === null) {
    return null;
  }

  return "".concat(context.idPrefix, "-P-").concat(value);
}

function getTabId(context, value) {
  var idPrefix = context.idPrefix;

  if (idPrefix === null) {
    return null;
  }

  return "".concat(context.idPrefix, "-T-").concat(value);
}