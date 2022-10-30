const User = require("../models/user.model");
require("dotenv").config();
// const jwt = require("jsonwebtoken");

var jwt = require("jsonwebtoken");

const newToken = (user) => {
  return (token = jwt.sign({ user }, process.env.JWT_SECRET_KEY));
};

const register = async (req, res) => {
  try {
    // Find User Exists
    let user = await User.findOne({ email: req.body.email }).lean();

    if (user)
      return res.status(400).send({ message: "User Exist Try another Email" });

    console.log(req.body.password, "pass");

    // Create User if not found
    user = await User.create(req.body);

    // Token for the user
    var token = newToken(user);

    console.log(token, "token");

    res.send({ user, token });
  } catch (e) {
    res.status(400).send(e.message);
  }
};

const login = async (req, res) => {
  try {
    console.log("Login login");
    let user = await User.findOne({ email: req.body.email });

    if (!user) return res.status(404).send({ message: "User not found" });

    const match = user.checkpassword(req.body.password);

    if (!match) return res.status(404).send({ message: "User not found" });

    var token = newToken(user);

    // console.log(token, "token");

    res.send({ user, token });
  } catch (error) {
    res.status(404).send(error.message);
  }
};

module.exports = {
  register,
  login,
};
