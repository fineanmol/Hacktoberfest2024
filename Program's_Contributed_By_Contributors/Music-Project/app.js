const http = require('http')
const fs = require('fs')
const port = 8080
const express= require('express')
const app = express()
const bodyParser =require('body-parser')

const server = http.createServer(function(req, res) {
    res.writeHead(200, {'Content-Type' : 'text/html'})
   /* fs.readFile('index.html', function(error, data) {
        if(error) {
            res.writeHead(404)
            res.write('Error: file Not Found')
        } else {
            res.write(data)
        }
        res.end()
    })*/
    // res.write('Hello Node') 
    fs.readFile('signin.html', function(error, data) {
        if(error) {
            res.writeHead(404)
            res.write('Error: file Not Found')
        } else {
            res.write(data)
        }
        res.end()
    })
})

server.listen(port, function(error){
    if (error) {
        console.log('Something went wrong', error)
    } else {
        console.log('Server is listening on port' + port)
    }
})
app.use(bodyParser.json())
app.post('/registration', async(reg,res)=>{
    console.log(reg.body)
})
