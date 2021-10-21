const express = require("express");
const route = require("./routes/indexRouter");
const db = require("./config/mongoose");
const app = express();
const port = 3000;

//setting view engine
app.set("view engine", "ejs");
app.set("views", "./views");

//allowing assests folder
app.use(express.static("./assets"));
app.use(express.urlencoded());

//routes
app.use("/", route);

//conecting to server
app.listen(port, function (err) {
  if (err) {
    return console.log("Error in starting server ", err);
  }
  return console.log("Server running in port : ", port);
});
