'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});

var _ElementType$Text$Ele;

var _htmlparser = require('htmlparser2');

var _TextElementType = require('./TextElementType');

var _TextElementType2 = _interopRequireDefault(_TextElementType);

var _TagElementType = require('./TagElementType');

var _TagElementType2 = _interopRequireDefault(_TagElementType);

var _StyleElementType = require('./StyleElementType');

var _StyleElementType2 = _interopRequireDefault(_StyleElementType);

var _UnsupportedElementType = require('./UnsupportedElementType');

var _UnsupportedElementType2 = _interopRequireDefault(_UnsupportedElementType);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

function _defineProperty(obj, key, value) { if (key in obj) { Object.defineProperty(obj, key, { value: value, enumerable: true, configurable: true, writable: true }); } else { obj[key] = value; } return obj; } /*
                                                                                                                                                                                                                   * Map each htmlparser2 element type to a function which will convert that element type to a React element
                                                                                                                                                                                                                   * Not all of the element types are supported so the UnsupportedElementType is used for them which will not return any
                                                                                                                                                                                                                   * value
                                                                                                                                                                                                                   */

exports.default = (_ElementType$Text$Ele = {}, _defineProperty(_ElementType$Text$Ele, _htmlparser.ElementType.Text, _TextElementType2.default), _defineProperty(_ElementType$Text$Ele, _htmlparser.ElementType.Tag, _TagElementType2.default), _defineProperty(_ElementType$Text$Ele, _htmlparser.ElementType.Style, _StyleElementType2.default), _defineProperty(_ElementType$Text$Ele, _htmlparser.ElementType.Directive, _UnsupportedElementType2.default), _defineProperty(_ElementType$Text$Ele, _htmlparser.ElementType.Comment, _UnsupportedElementType2.default), _defineProperty(_ElementType$Text$Ele, _htmlparser.ElementType.Script, _UnsupportedElementType2.default), _defineProperty(_ElementType$Text$Ele, _htmlparser.ElementType.CDATA, _UnsupportedElementType2.default), _defineProperty(_ElementType$Text$Ele, _htmlparser.ElementType.Doctype, _UnsupportedElementType2.default), _ElementType$Text$Ele);