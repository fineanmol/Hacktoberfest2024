function toSnakeCase(key) {
  return key && key
      .replace(/\W+/g, ' ') // change any non-word character into space
      .split(/\B(?=[A-Z])| /) // split by word boundary ('customFields' ---> ['custom', 'Fields']) or by space
      .map(e => e.toLowerCase()) // lowercase all fragments
      .join('_') // glue all elements using '_'
}
