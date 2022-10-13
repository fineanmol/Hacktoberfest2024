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

var _reactIs = require("react-is");

var _propTypes = _interopRequireDefault(require("prop-types"));

var _clsx = _interopRequireDefault(require("clsx"));

var _styles = require("@material-ui/core/styles");

var _Zoom = _interopRequireDefault(require("@material-ui/core/Zoom"));

var _Fab = _interopRequireDefault(require("@material-ui/core/Fab"));

var _utils = require("@material-ui/core/utils");

function getOrientation(direction) {
  if (direction === 'up' || direction === 'down') {
    return 'vertical';
  }

  if (direction === 'right' || direction === 'left') {
    return 'horizontal';
  }

  return undefined;
}

function clamp(value, min, max) {
  if (value < min) {
    return min;
  }

  if (value > max) {
    return max;
  }

  return value;
}

var dialRadius = 32;
var spacingActions = 16;

var styles = function styles(theme) {
  return {
    /* Styles applied to the root element. */
    root: {
      zIndex: theme.zIndex.speedDial,
      display: 'flex',
      alignItems: 'center',
      pointerEvents: 'none'
    },

    /* Styles applied to the Fab component. */
    fab: {
      pointerEvents: 'auto'
    },

    /* Styles applied to the root if direction="up" */
    directionUp: {
      flexDirection: 'column-reverse',
      '& $actions': {
        flexDirection: 'column-reverse',
        marginBottom: -dialRadius,
        paddingBottom: spacingActions + dialRadius
      }
    },

    /* Styles applied to the root if direction="down" */
    directionDown: {
      flexDirection: 'column',
      '& $actions': {
        flexDirection: 'column',
        marginTop: -dialRadius,
        paddingTop: spacingActions + dialRadius
      }
    },

    /* Styles applied to the root if direction="left" */
    directionLeft: {
      flexDirection: 'row-reverse',
      '& $actions': {
        flexDirection: 'row-reverse',
        marginRight: -dialRadius,
        paddingRight: spacingActions + dialRadius
      }
    },

    /* Styles applied to the root if direction="right" */
    directionRight: {
      flexDirection: 'row',
      '& $actions': {
        flexDirection: 'row',
        marginLeft: -dialRadius,
        paddingLeft: spacingActions + dialRadius
      }
    },

    /* Styles applied to the actions (`children` wrapper) element. */
    actions: {
      display: 'flex',
      pointerEvents: 'auto'
    },

    /* Styles applied to the actions (`children` wrapper) element if `open={false}`. */
    actionsClosed: {
      transition: 'top 0s linear 0.2s',
      pointerEvents: 'none'
    }
  };
};

exports.styles = styles;
var SpeedDial = /*#__PURE__*/React.forwardRef(function SpeedDial(props, ref) {
  var ariaLabel = props.ariaLabel,
      _props$FabProps = props.FabProps;
  _props$FabProps = _props$FabProps === void 0 ? {} : _props$FabProps;
  var origDialButtonRef = _props$FabProps.ref,
      FabProps = (0, _objectWithoutProperties2.default)(_props$FabProps, ["ref"]),
      childrenProp = props.children,
      classes = props.classes,
      className = props.className,
      _props$direction = props.direction,
      direction = _props$direction === void 0 ? 'up' : _props$direction,
      _props$hidden = props.hidden,
      hidden = _props$hidden === void 0 ? false : _props$hidden,
      icon = props.icon,
      onBlur = props.onBlur,
      onClose = props.onClose,
      onFocus = props.onFocus,
      onKeyDown = props.onKeyDown,
      onMouseEnter = props.onMouseEnter,
      onMouseLeave = props.onMouseLeave,
      onOpen = props.onOpen,
      open = props.open,
      openIcon = props.openIcon,
      _props$TransitionComp = props.TransitionComponent,
      TransitionComponent = _props$TransitionComp === void 0 ? _Zoom.default : _props$TransitionComp,
      _props$transitionDura = props.transitionDuration,
      transitionDuration = _props$transitionDura === void 0 ? {
    enter: _styles.duration.enteringScreen,
    exit: _styles.duration.leavingScreen
  } : _props$transitionDura,
      TransitionProps = props.TransitionProps,
      other = (0, _objectWithoutProperties2.default)(props, ["ariaLabel", "FabProps", "children", "classes", "className", "direction", "hidden", "icon", "onBlur", "onClose", "onFocus", "onKeyDown", "onMouseEnter", "onMouseLeave", "onOpen", "open", "openIcon", "TransitionComponent", "transitionDuration", "TransitionProps"]);
  var eventTimer = React.useRef();
  React.useEffect(function () {
    return function () {
      clearTimeout(eventTimer.current);
    };
  }, []);
  /**
   * an index in actions.current
   */

  var focusedAction = React.useRef(0);
  /**
   * pressing this key while the focus is on a child SpeedDialAction focuses
   * the next SpeedDialAction.
   * It is equal to the first arrow key pressed while focus is on the SpeedDial
   * that is not orthogonal to the direction.
   * @type {utils.ArrowKey?}
   */

  var nextItemArrowKey = React.useRef();
  /**
   * refs to the Button that have an action associated to them in this SpeedDial
   * [Fab, ...(SpeedDialActions > Button)]
   * @type {HTMLButtonElement[]}
   */

  var actions = React.useRef([]);
  actions.current = [actions.current[0]];
  var handleOwnFabRef = React.useCallback(function (fabFef) {
    actions.current[0] = fabFef;
  }, []);
  var handleFabRef = (0, _utils.useForkRef)(origDialButtonRef, handleOwnFabRef);
  /**
   * creates a ref callback for the Button in a SpeedDialAction
   * Is called before the original ref callback for Button that was set in buttonProps
   *
   * @param dialActionIndex {number}
   * @param origButtonRef {React.RefObject?}
   */

  var createHandleSpeedDialActionButtonRef = function createHandleSpeedDialActionButtonRef(dialActionIndex, origButtonRef) {
    return function (buttonRef) {
      actions.current[dialActionIndex + 1] = buttonRef;

      if (origButtonRef) {
        origButtonRef(buttonRef);
      }
    };
  };

  var handleKeyDown = function handleKeyDown(event) {
    if (onKeyDown) {
      onKeyDown(event);
    }

    var key = event.key.replace('Arrow', '').toLowerCase();
    var _nextItemArrowKey$cur = nextItemArrowKey.current,
        nextItemArrowKeyCurrent = _nextItemArrowKey$cur === void 0 ? key : _nextItemArrowKey$cur;

    if (event.key === 'Escape') {
      if (onClose) {
        actions.current[0].focus();
        onClose(event, 'escapeKeyDown');
      }

      return;
    }

    if (getOrientation(key) === getOrientation(nextItemArrowKeyCurrent) && getOrientation(key) !== undefined) {
      event.preventDefault();
      var actionStep = key === nextItemArrowKeyCurrent ? 1 : -1; // stay within array indices

      var nextAction = clamp(focusedAction.current + actionStep, 0, actions.current.length - 1);
      actions.current[nextAction].focus();
      focusedAction.current = nextAction;
      nextItemArrowKey.current = nextItemArrowKeyCurrent;
    }
  };

  React.useEffect(function () {
    // actions were closed while navigation state was not reset
    if (!open) {
      focusedAction.current = 0;
      nextItemArrowKey.current = undefined;
    }
  }, [open]);

  var handleClose = function handleClose(event) {
    if (event.type === 'mouseleave' && onMouseLeave) {
      onMouseLeave(event);
    }

    if (event.type === 'blur' && onBlur) {
      onBlur(event);
    }

    clearTimeout(eventTimer.current);

    if (onClose) {
      if (event.type === 'blur') {
        event.persist();
        eventTimer.current = setTimeout(function () {
          onClose(event, 'blur');
        });
      } else {
        onClose(event, 'mouseLeave');
      }
    }
  };

  var handleClick = function handleClick(event) {
    if (FabProps.onClick) {
      FabProps.onClick(event);
    }

    clearTimeout(eventTimer.current);

    if (open) {
      if (onClose) {
        onClose(event, 'toggle');
      }
    } else if (onOpen) {
      onOpen(event, 'toggle');
    }
  };

  var handleOpen = function handleOpen(event) {
    if (event.type === 'mouseenter' && onMouseEnter) {
      onMouseEnter(event);
    }

    if (event.type === 'focus' && onFocus) {
      onFocus(event);
    } // When moving the focus between two items,
    // a chain if blur and focus event is triggered.
    // We only handle the last event.


    clearTimeout(eventTimer.current);

    if (onOpen && !open) {
      event.persist(); // Wait for a future focus or click event

      eventTimer.current = setTimeout(function () {
        var eventMap = {
          focus: 'focus',
          mouseenter: 'mouseEnter'
        };
        onOpen(event, eventMap[event.type]);
      });
    }
  }; // Filter the label for valid id characters.


  var id = ariaLabel.replace(/^[^a-z]+|[^\w:.-]+/gi, '');
  var allItems = React.Children.toArray(childrenProp).filter(function (child) {
    if (process.env.NODE_ENV !== 'production') {
      if ((0, _reactIs.isFragment)(child)) {
        console.error(["Material-UI: The SpeedDial component doesn't accept a Fragment as a child.", 'Consider providing an array instead.'].join('\n'));
      }
    }

    return /*#__PURE__*/React.isValidElement(child);
  });
  var children = allItems.map(function (child, index) {
    var _child$props$FabProps = child.props.FabProps;
    _child$props$FabProps = _child$props$FabProps === void 0 ? {} : _child$props$FabProps;
    var origButtonRef = _child$props$FabProps.ref,
        ChildFabProps = (0, _objectWithoutProperties2.default)(_child$props$FabProps, ["ref"]);
    return /*#__PURE__*/React.cloneElement(child, {
      FabProps: (0, _extends2.default)({}, ChildFabProps, {
        ref: createHandleSpeedDialActionButtonRef(index, origButtonRef)
      }),
      delay: 30 * (open ? index : allItems.length - index),
      open: open,
      id: "".concat(id, "-action-").concat(index)
    });
  });
  return /*#__PURE__*/React.createElement("div", (0, _extends2.default)({
    className: (0, _clsx.default)(classes.root, classes["direction".concat((0, _utils.capitalize)(direction))], className),
    ref: ref,
    role: "presentation",
    onKeyDown: handleKeyDown,
    onBlur: handleClose,
    onFocus: handleOpen,
    onMouseEnter: handleOpen,
    onMouseLeave: handleClose
  }, other), /*#__PURE__*/React.createElement(TransitionComponent, (0, _extends2.default)({
    in: !hidden,
    timeout: transitionDuration,
    unmountOnExit: true
  }, TransitionProps), /*#__PURE__*/React.createElement(_Fab.default, (0, _extends2.default)({
    color: "primary",
    "aria-label": ariaLabel,
    "aria-haspopup": "true",
    "aria-expanded": open,
    "aria-controls": "".concat(id, "-actions")
  }, FabProps, {
    onClick: handleClick,
    className: (0, _clsx.default)(classes.fab, FabProps.className),
    ref: handleFabRef
  }), /*#__PURE__*/React.isValidElement(icon) && (0, _utils.isMuiElement)(icon, ['SpeedDialIcon']) ? /*#__PURE__*/React.cloneElement(icon, {
    open: open
  }) : icon)), /*#__PURE__*/React.createElement("div", {
    id: "".concat(id, "-actions"),
    role: "menu",
    "aria-orientation": getOrientation(direction),
    className: (0, _clsx.default)(classes.actions, !open && classes.actionsClosed)
  }, children));
});
process.env.NODE_ENV !== "production" ? SpeedDial.propTypes = {
  // ----------------------------- Warning --------------------------------
  // | These PropTypes are generated from the TypeScript type definitions |
  // |     To update them edit the d.ts file and run "yarn proptypes"     |
  // ----------------------------------------------------------------------

  /**
   * The aria-label of the button element.
   * Also used to provide the `id` for the `SpeedDial` element and its children.
   */
  ariaLabel: _propTypes.default.string.isRequired,

  /**
   * SpeedDialActions to display when the SpeedDial is `open`.
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
   * The direction the actions open relative to the floating action button.
   */
  direction: _propTypes.default.oneOf(['down', 'left', 'right', 'up']),

  /**
   * Props applied to the [`Fab`](/api/fab/) element.
   */
  FabProps: _propTypes.default.object,

  /**
   * If `true`, the SpeedDial will be hidden.
   */
  hidden: _propTypes.default.bool,

  /**
   * The icon to display in the SpeedDial Fab. The `SpeedDialIcon` component
   * provides a default Icon with animation.
   */
  icon: _propTypes.default.node,

  /**
   * @ignore
   */
  onBlur: _propTypes.default.func,

  /**
   * Callback fired when the component requests to be closed.
   *
   * @param {object} event The event source of the callback.
   * @param {string} reason Can be: `"toggle"`, `"blur"`, `"mouseLeave"`, `"escapeKeyDown"`.
   */
  onClose: _propTypes.default.func,

  /**
   * @ignore
   */
  onFocus: _propTypes.default.func,

  /**
   * @ignore
   */
  onKeyDown: _propTypes.default.func,

  /**
   * @ignore
   */
  onMouseEnter: _propTypes.default.func,

  /**
   * @ignore
   */
  onMouseLeave: _propTypes.default.func,

  /**
   * Callback fired when the component requests to be open.
   *
   * @param {object} event The event source of the callback.
   * @param {string} reason Can be: `"toggle"`, `"focus"`, `"mouseEnter"`.
   */
  onOpen: _propTypes.default.func,

  /**
   * If `true`, the SpeedDial is open.
   */
  open: _propTypes.default.bool.isRequired,

  /**
   * The icon to display in the SpeedDial Fab when the SpeedDial is open.
   */
  openIcon: _propTypes.default.node,

  /**
   * The component used for the transition.
   * [Follow this guide](/components/transitions/#transitioncomponent-prop) to learn more about the requirements for this component.
   */
  TransitionComponent: _propTypes.default.elementType,

  /**
   * The duration for the transition, in milliseconds.
   * You may specify a single timeout for all transitions, or individually with an object.
   */
  transitionDuration: _propTypes.default.oneOfType([_propTypes.default.number, _propTypes.default.shape({
    appear: _propTypes.default.number,
    enter: _propTypes.default.number,
    exit: _propTypes.default.number
  })]),

  /**
   * Props applied to the [`Transition`](http://reactcommunity.org/react-transition-group/transition#Transition-props) element.
   */
  TransitionProps: _propTypes.default.object
} : void 0;

var _default = (0, _styles.withStyles)(styles, {
  name: 'MuiSpeedDial'
})(SpeedDial);

exports.default = _default;