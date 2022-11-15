// import mongoose 
const mongoose = require('mongoose');   


// create connect function to connect to database
const connect = () => {
    return mongoose.connect('mongodb://127.0.0.1:27017/databaseNameHere')
};

//exporting the connect function in index.js
module.exports = connect;
