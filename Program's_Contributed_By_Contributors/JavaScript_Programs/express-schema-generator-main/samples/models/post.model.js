const mongoose = require('mongoose');

postSchema = new mongoose.Schema({ 
    "title":{type:String, required:true, unique:true},
    "body":{type:String, required:true, unique:true},
    "user_id": {type:mongoose.Schema.Types.ObjectId, required:true, ref:'user'},
    "tag_id": [{type:mongoose.Schema.Types.ObjectId, required:true, ref:'tag'}]
},{
    "versionKey": false, timestamps:true
    })

module.exports =  mongoose.model('post',postSchema)

