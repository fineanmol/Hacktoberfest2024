const path = require("path");
const multer = require("multer");

const storage = multer.diskStorage({
  destination: function (req, file, cb) {
    // console.log("first in file uploads")
    cb(null, path.join(__dirname, "../uploads"));
  },
  filename: function (req, file, cb) {
    const uniquePrefix = Date.now() + "-" + Math.round(Math.random() * 1e9);
    cb(null, uniquePrefix + "-" + file.originalname);
  },
});

function fileFilter(req, file, cb) {
    console.log(file)
    //   if (file.mimetype == "image/jpeg") {
        cb(null, true);
    //   }
    
    //   if (file.mimetype == "image/png") {
    //     cb(null, true);
    //   }  
    //   else {
    //     cb(null, false);
    //   }
    //   cb(new Error("I don't have a clue!"));
}

// module.exports = multer({ storage, fileFilter })
module.exports = multer({ storage, fileFilter });
