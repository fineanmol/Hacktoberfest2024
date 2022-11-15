const express = require("express");

const Product = require("../models/product.model");
const authenticate = require('../middlewares/authenticate');
const router = express.Router();

router.post("", authenticate ,async (req, res) => {
  try {

    //   req
    const user = await Product.create(req.body);
    res.send(user);
  } catch (err) {
    // console.log(err.message);
    res.send(err.message);
  }
});

module.exports = router;
