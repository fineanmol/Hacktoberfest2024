"use strict";

var _interopRequireDefault = require("@babel/runtime/helpers/interopRequireDefault");

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = styled;

var _extends2 = _interopRequireDefault(require("@babel/runtime/helpers/extends"));

var _objectWithoutProperties2 = _interopRequireDefault(require("@babel/runtime/helpers/objectWithoutProperties"));

var _react = _interopRequireDefault(require("react"));

var _clsx = _interopRequireDefault(require("clsx"));

var _propTypes = _interopRequireDefault(require("prop-types"));

var _utils = require("@material-ui/utils");

var _hoistNonReactStatics = _interopRequireDefault(require("hoist-non-react-statics"));

var _makeStyles = _interopRequireDefault(require("../makeStyles"));

function omit(input, fields) {
  var output = {};
  Object.keys(input).forEach(function (prop) {
    if (fields.indexOf(prop) === -1) {
      output[prop] = input[prop];
    }
  });
  return output;
} // styled-components's API removes the mapping between components and styles.
// Using components as a low-level styling construct can be simpler.


function styled(Component) {
  var componentCreator = function componentCreator(style) {
    var options = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : {};
    var name = options.name,
        stylesOptions = (0, _objectWithoutProperties2.default)(options, ["name"]);

    if (process.env.NODE_ENV !== 'production' && Component === undefined) {
      throw new Error(['You are calling styled(Component)(style) with an undefined component.', 'You may have forgotten to import it.'].join('\n'));
    }

    var classNamePrefix = name;

    if (process.env.NODE_ENV !== 'production') {
      if (!name) {
        // Provide a better DX outside production.
        var displayName = (0, _utils.getDisplayName)(Component);

        if (displayName !== undefined) {
          classNamePrefix = displayName;
        }
      }
    }

    var stylesOrCreator = typeof style === 'function' ? function (theme) {
      return {
        root: function root(props) {
          return style((0, _extends2.default)({
            theme: theme
          }, props));
        }
      };
    } : {
      root: style
    };
    var useStyles = (0, _makeStyles.default)(stylesOrCreator, (0, _extends2.default)({
      Component: Component,
      name: name || Component.displayName,
      classNamePrefix: classNamePrefix
    }, stylesOptions));
    var filterProps;
    var propTypes = {};

    if (style.filterProps) {
      filterProps = style.filterProps;
      delete style.filterProps;
    }
    /* eslint-disable react/forbid-foreign-prop-types */


    if (style.propTypes) {
      propTypes = style.propTypes;
      delete style.propTypes;
    }
    /* eslint-enable react/forbid-foreign-prop-types */


    var StyledComponent = /*#__PURE__*/_react.default.forwardRef(function StyledComponent(props, ref) {
      var children = props.children,
          classNameProp = props.className,
          clone = props.clone,
          ComponentProp = props.component,
          other = (0, _objectWithoutProperties2.default)(props, ["children", "className", "clone", "component"]);
      var classes = useStyles(props);
      var className = (0, _clsx.default)(classes.root, classNameProp);
      var spread = other;

      if (filterProps) {
        spread = omit(spread, filterProps);
      }

      if (clone) {
        return /*#__PURE__*/_react.default.cloneElement(children, (0, _extends2.default)({
          className: (0, _clsx.default)(children.props.className, className)
        }, spread));
      }

      if (typeof children === 'function') {
        return children((0, _extends2.default)({
          className: className
        }, spread));
      }

      var FinalComponent = ComponentProp || Component;
      return /*#__PURE__*/_react.default.createElement(FinalComponent, (0, _extends2.default)({
        ref: ref,
        className: className
      }, spread), children);
    });

    process.env.NODE_ENV !== "production" ? StyledComponent.propTypes = (0, _extends2.default)({
      /**
       * A render function or node.
       */
      children: _propTypes.default.oneOfType([_propTypes.default.node, _propTypes.default.func]),

      /**
       * @ignore
       */
      className: _propTypes.default.string,

      /**
       * If `true`, the component will recycle it's children HTML element.
       * It's using `React.cloneElement` internally.
       *
       * This prop will be deprecated and removed in v5
       */
      clone: (0, _utils.chainPropTypes)(_propTypes.default.bool, function (props) {
        if (props.clone && props.component) {
          return new Error('You can not use the clone and component prop at the same time.');
        }

        return null;
      }),

      /**
       * The component used for the root node.
       * Either a string to use a HTML element or a component.
       */
      component: _propTypes.default
      /* @typescript-to-proptypes-ignore */
      .elementType
    }, propTypes) : void 0;

    if (process.env.NODE_ENV !== 'production') {
      StyledComponent.displayName = "Styled(".concat(classNamePrefix, ")");
    }

    (0, _hoistNonReactStatics.default)(StyledComponent, Component);
    return StyledComponent;
  };

  return componentCreator;
}