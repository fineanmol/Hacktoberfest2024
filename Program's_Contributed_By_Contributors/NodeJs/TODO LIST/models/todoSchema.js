const mongoose = require("mongoose");
const todoSchema = new mongoose.Schema({
  description: {
    type: String,
  },
  catogery: {
    type: String,
  },
  date: {
    type: String,
  },
});

const Task = mongoose.model("user", todoSchema);
module.exports = Task;
