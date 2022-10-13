import _toConsumableArray from "@babel/runtime/helpers/esm/toConsumableArray";
import _extends from "@babel/runtime/helpers/esm/extends";
import PropTypes from 'prop-types';
import { chainPropTypes } from '@material-ui/utils';
import merge from './merge';

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
      return _extends({}, merge(output, styleFunction(_extends({
        theme: props.theme
      }, props.css))), omit(props.css, [styleFunction.filterProps]));
    }

    if (props.sx) {
      return _extends({}, merge(output, styleFunction(_extends({
        theme: props.theme
      }, props.sx))), omit(props.sx, [styleFunction.filterProps]));
    }

    return output;
  };

  newStyleFunction.propTypes = process.env.NODE_ENV !== 'production' ? _extends({}, styleFunction.propTypes, {
    css: chainPropTypes(PropTypes.object, function (props) {
      if (!warnedOnce && props.css !== undefined) {
        warnedOnce = true;
        return new Error('Material-UI: The `css` prop is deprecated, please use the `sx` prop instead.');
      }

      return null;
    }),
    sx: PropTypes.object
  }) : {};
  newStyleFunction.filterProps = ['css', 'sx'].concat(_toConsumableArray(styleFunction.filterProps));
  return newStyleFunction;
}
/**
 *
 * @deprecated
 * The css style function is deprecated. Use the `styleFunctionSx` instead.
 */


export function css(styleFunction) {
  if (process.env.NODE_ENV !== 'production') {
    console.warn('Material-UI: The `css` function is deprecated. Use the `styleFunctionSx` instead.');
  }

  return styleFunctionSx(styleFunction);
}
export default styleFunctionSx;