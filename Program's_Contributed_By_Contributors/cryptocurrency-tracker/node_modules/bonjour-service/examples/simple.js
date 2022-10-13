const { Bonjour } = require('../dist')

const service = new Bonjour()

service.publish({ name: 'My Web Server', type: 'http', port: 3000 })

let browser = service.find({ type: 'http' })

browser.on('up', (service) => {
  console.log('up', service)
})

browser.on('down', (service) => {
  console.log('down', service)
})
