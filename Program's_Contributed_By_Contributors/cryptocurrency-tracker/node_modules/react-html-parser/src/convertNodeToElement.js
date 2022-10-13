import ElementTypes from './elementTypes';

/**
 * Converts a htmlparser2 node to a React element
 *
 * @param {Object} node The htmlparser2 node to convert
 * @param {Number} index The index of the current node
 * @param {Function} transform Transform function to apply to children of the node
 * @returns {React.Element}
 */
export default function convertNodeToElement(node, index, transform) {
  return ElementTypes[node.type](node, index, transform);
}
