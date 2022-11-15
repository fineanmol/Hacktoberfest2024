const mongoose = require('mongoose');


const UserSchema = mongoose.Schema({
        "id": {type:Number, unique:true,required:true},
        "first_name": {type:String,required:true},
        "last_name": {type:String,required:true},
        "email": {type:String,required:true},
        "gender": {type:String,required:true},
        "address": {type:String,required:true},
        "pic": {type:String}
})

module.exports = mongoose.model("user",UserSchema)
