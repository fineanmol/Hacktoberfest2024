const mongoose=require('mongoose');

  const email=new mongoose.Schema({
    email: {
      type: String,
    },
     password: {
      type:String,
    }
  });


const admin=mongoose.model('email',email);

console.log("schema is connected");

module.exports=admin;
