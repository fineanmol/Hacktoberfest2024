const mongoose = require('mongoose');   

tagSchema = new mongoose.Schema({ 
    "title":{type:String, required:true, unique:true},
    "post_id": {type:String, default:"61fe637239f98fe2c994c10f",required:false}
    },{
    "versionKey":false, timestamps:true
})

module.exports =  mongoose.model('tag',tagSchema)


