/*
 * Map each htmlparser2 element type to a function which will convert that element type to a React element
 * Not all of the element types are supported so the UnsupportedElementType is used for them which will not return any
 * value
 */

import { ElementType } from 'htmlparser2';

import TextElementType from './TextElementType';
import TagElementType from './TagElementType';
import StyleElementType from './StyleElementType';
import UnsupportedElementType from './UnsupportedElementType';

export default {
  [ElementType.Text]: TextElementType,
  [ElementType.Tag]: TagElementType,
  [ElementType.Style]: StyleElementType,
  [ElementType.Directive]: UnsupportedElementType,
  [ElementType.Comment]: UnsupportedElementType,
  [ElementType.Script]: UnsupportedElementType,
  [ElementType.CDATA]: UnsupportedElementType,
  [ElementType.Doctype]: UnsupportedElementType
};
