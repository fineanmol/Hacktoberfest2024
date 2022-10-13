'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = TagElementType;

var _react = require('react');

var _react2 = _interopRequireDefault(_react);

var _processNodes = require('../processNodes');

var _processNodes2 = _interopRequireDefault(_processNodes);

var _generatePropsFromAttributes = require('../utils/generatePropsFromAttributes');

var _generatePropsFromAttributes2 = _interopRequireDefault(_generatePropsFromAttributes);

var _VoidElements = require('../dom/elements/VoidElements');

var _VoidElements2 = _interopRequireDefault(_VoidElements);

var _isValidTagOrAttributeName = require('../utils/isValidTagOrAttributeName');

var _isValidTagOrAttributeName2 = _interopRequireDefault(_isValidTagOrAttributeName);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

/**
 * Converts any element (excluding style - see StyleElementType - and script) to a react element.
 *
 * @param {Object} node The tag node
 * @param {String} index The index of the React element relative to it's parent
 * @param {Function} transform The transform function to apply to all children
 * @returns {React.Element} The React tag element
 */
function TagElementType(node, index, transform) {

  var tagName = node.name;

  // validate tag name
  if (!(0, _isValidTagOrAttributeName2.default)(tagName)) {
    return null;
  }

  // generate props
  var props = (0, _generatePropsFromAttributes2.default)(node.attribs, index);

  // If the node is not a void element and has children then process them
  var children = null;
  if (_VoidElements2.default.indexOf(tagName) === -1) {
    children = (0, _processNodes2.default)(node.children, transform);
  }

  // create and return the element
  return _react2.default.createElement(tagName, props, children);
}