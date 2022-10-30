const express = require('express');  
const app = express();
app.use(express.json());

const connect = require('./configs/db.js');

/// Models Ends

const userController = require('./controllers/user.controller');

/////////////////

app.use('/user', userController);

////////////////////////////////

// Start Listening the Server

port = process.env.PORT || 3000;

app.listen(port,async()=>{
await connect();
console.log(`Listening on ${port}`);
});
