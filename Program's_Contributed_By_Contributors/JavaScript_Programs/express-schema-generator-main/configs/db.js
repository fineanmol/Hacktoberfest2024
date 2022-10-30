const mongoose = require('mongoose');    // import mongoose


// Created a Function connect to Connect the database

const connect = () => {
    return mongoose.connect('mongodb+srv://')
};

// exporting the connect function

module.exports = connect;
