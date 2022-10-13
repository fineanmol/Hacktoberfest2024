/**
 * Handles an unsupported element type by returning null so nothing is rendered
 * @returns {null}
 */
export default function UnsupportedElementType() {

  // do nothing because the element type is unsupported
  // comment, directive, script, cdata, doctype are all currently unsupported
  return null;

}
