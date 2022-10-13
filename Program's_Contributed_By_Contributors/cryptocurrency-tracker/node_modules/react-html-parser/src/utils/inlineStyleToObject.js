/**
 * Converts an inline style string into an object of React style properties
 *
 * @param {String} inlineStyle='' The inline style to convert
 * @returns {Object} The converted style
 */
export default function InlineStyleToObject(inlineStyle = '') {

  // just return empty object if the inlineStyle is empty
  if (inlineStyle === '') {
    return {};
  }

  return inlineStyle
    .split(';')
    .reduce(
      (styleObject, stylePropertyValue) => {

        // extract the style property name and value
        let [property, value] = stylePropertyValue
          .split(/^([^:]+):/)
          .filter((val, i) => i > 0)
          .map(item => item.trim().toLowerCase());

        // if there is no value (i.e. no : in the style) then ignore it
        if (value === undefined) {
          return styleObject;
        }

        // convert the property name into the correct React format
        // remove all hyphens and convert the letter immediately after each hyphen to upper case
        // additionally don't uppercase any -ms- prefix
        // e.g. -ms-style-property = msStyleProperty
        //      -webkit-style-property = WebkitStyleProperty
        property = property
          .replace(/^-ms-/, 'ms-')
          .replace(/-(.)/g, (_, character) => character.toUpperCase());

        // add the new style property and value to the style object
        styleObject[property] = value;

        return styleObject;

      },
      {}
    );

}
