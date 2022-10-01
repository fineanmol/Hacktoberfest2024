//basic sessions concept in js
const express = require("express");
const app = express();
//requitring the session
const flash = require("connect-flash");
const session = require("express-session");

app.use(
  session({
    secret: "thisisasecret",
    resave: false,
    saveUninitialized: false,
  })
);

app.use(flash());
//checking the flash operation
app.get("/a", (req, res) => {
  res.send(req.flash("message"));
});
app.get("/flash", (req, res) => {
  req.flash("message", "HEy I am a flash");
  res.redirect("/a");
});

app.get("/viewcount", (req, res) => {
  if (req.session.count) {
    req.session.count++;
  } else {
    req.session.count = 1;
  }
  res.send(`you have viewed it ${req.session.count} times`);
});
app.get("/register", (req, res) => {
  const { username, animal } = req.query;
  req.session.username = username;
  req.session.animal = animal;
  res.redirect("/hello");
});
app.get("/hello", (req, res) => {
  const { username, animal } = req.session;

  res.send(`Hey there ${username} and your fav person is ${animal}`);
});
const port=process.env.PORT || 3000
app.listen(port, () => {
  console.log("server is listening");
});
