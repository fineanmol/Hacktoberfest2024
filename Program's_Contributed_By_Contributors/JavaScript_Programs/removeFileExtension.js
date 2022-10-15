function removeFileExtension(fileName) {
  if (fileName) {
    const splitName = fileName.split('.')
    if (splitName.length > 1) {
      splitName.pop()
    }
    return splitName.join('.')
  }
  return ''
}
