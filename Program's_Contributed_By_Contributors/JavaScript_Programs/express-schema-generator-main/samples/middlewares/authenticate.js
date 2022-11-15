require("dotenv").config;
const jwt = require("jsonwebtoken");

const verifyToken = (token) => {
  return new Promise((resolve, reject) => {
    
    console.log(process.env.JWT_SECRET_KEY)

    jwt.verify(token, process.env.JWT_SECRET_KEY, (err, user) => {
      if (err) return console.log(err);

      resolve(user);
    });
  });
};

module.exports = async (req, res, next) => {
  if (!req.headers.authorization) return res.status(403).send("Token not found");

  if (!req.headers.authorization.startsWith("Bearer "))
    return res.status(403).send("Token not found");

  const token = req.headers.authorization.split(" ")[1];

  const user = await verifyToken(token);

    req.body.user_id = user.user._id

  console.log(req.user, "authorization");
  return next();
};
