
function convertImageToBase64Url(img) {
  function toDataURL(url, callback) {
    const xhr = new XMLHttpRequest()
    xhr.onload = () => {
      const reader = new FileReader()
      reader.onloadend = () => {
        callback(reader.result)
      }
      reader.readAsDataURL(xhr.response)
    }
    xhr.open('GET', url)
    xhr.responseType = 'blob'
    xhr.send()
  }
  return new Promise((resolve) => {
    toDataURL(img, (dataUrl) => {
      resolve(dataUrl)
    })
  })
}
