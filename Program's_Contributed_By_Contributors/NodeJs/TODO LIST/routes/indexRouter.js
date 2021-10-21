const express = require("express");
const homeController = require("../controllers/indexController");

const router = express.Router();

router.get("/", homeController.home);
router.get("/delete-task", homeController.delete);
router.post("/create-task", homeController.create);

module.exports = router;
