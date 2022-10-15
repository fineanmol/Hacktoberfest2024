// Convert the characters &, <, >, " (double quote), and ' (apostrophe), in a string to their corresponding HTML entities.

function convertHTML(str) {
  const htmlCharacters = {
    '&': '&​amp;',
    '<': '&​lt;',
    '>': '&​gt;',
    '"': '&​quot;',
    '\'': '&​apos;'
  };
  const replacer = (match) => htmlCharacters[match];

  return str.replace(/[&<>"']/g, replacer);
}

convertHTML("Dolce & Gabbana"); //=> "Dolce &​amp; Gabbana"
convertHTML("Hamburgers < Pizza < Tacos"); //=> "Hamburgers &​lt; Pizza &​lt; Tacos"
convertHTML("<>"); //=> "&​lt;&​gt;"
