import React from 'react';
import generateElementProps from '../utils/generatePropsFromAttributes';

/**
 * Converts a <style> element to a React element
 *
 * @param {Object} node The style node
 * @param {String} index The index of the React element relative to it's parent
 * @returns {React.Element} The React style element
 */
export default function StyleElementType(node, index) {

  // The style element only ever has a single child which is the styles so try and find this to add as
  // a child to the style element that will be created
  let styles;
  if (node.children.length > 0) {
    styles = node.children[0].data;
  }

  // generate props
  const props = generateElementProps(node.attribs, index);

  // create and return the element
  return React.createElement('style', props, styles);

}
