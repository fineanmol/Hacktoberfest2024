"use strict";

var _interopRequireDefault = require("@babel/runtime/helpers/interopRequireDefault");

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.css = css;
exports.default = void 0;

var _toConsumableArray2 = _interopRequireDefault(require("@babel/runtime/helpers/toConsumableArray"));

var _extends2 = _interopRequireDefault(require("@babel/runtime/helpers/extends"));

var _propTypes = _interopRequireDefault(require("prop-types"));

var _utils = require("@material-ui/utils");

var _merge = _interopRequireDefault(require("./merge"));

function omit(input, fields) {
  var output = {};
  Object.keys(input).forEach(function (prop) {
    if (fields.indexOf(prop) === -1) {
      output[prop] = input[prop];
    }
  });
  return output;
}

var warnedOnce = false;

function styleFunctionSx(styleFunction) {
  var newStyleFunction = function newStyleFunction(props) {
    var output = styleFunction(props);

    if (props.css) {
      return (0, _extends2.default)({}, (0, _merge.default)(output, styleFunction((0, _extends2.default)({
        theme: props.theme
      }, props.css))), omit(props.css, [styleFunction.filterProps]));
    }

    if (props.sx) {
      return (0, _extends2.default)({}, (0, _merge.default)(output, styleFunction((0, _extends2.default)({
        theme: props.theme
      }, props.sx))), omit(props.sx, [styleFunction.filterProps]));
    }

    return output;
  };

  newStyleFunction.propTypes = process.env.NODE_ENV !== 'production' ? (0, _extends2.default)({}, styleFunction.propTypes, {
    css: (0, _utils.chainPropTypes)(_propTypes.default.object, function (props) {
      if (!warnedOnce && props.css !== undefined) {
        warnedOnce = true;
        return new Error('Material-UI: The `css` prop is deprecated, please use the `sx` prop instead.');
      }

      return null;
    }),
    sx: _propTypes.default.object
  }) : {};
  newStyleFunction.filterProps = ['css', 'sx'].concat((0, _toConsumableArray2.default)(styleFunction.filterProps));
  return newStyleFunction;
}
/**
 *
 * @deprecated
 * The css style function is deprecated. Use the `styleFunctionSx` instead.
 */


function css(styleFunction) {
  if (process.env.NODE_ENV !== 'production') {
    console.warn('Material-UI: The `css` function is deprecated. Use the `styleFunctionSx` instead.');
  }

  return styleFunctionSx(styleFunction);
}

var _default = styleFunctionSx;
exports.default = _default;