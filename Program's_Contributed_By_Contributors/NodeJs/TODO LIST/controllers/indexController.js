const Task = require("../models/todoSchema");

//controller for rendering home page
module.exports.home = function (req, res) {
  Task.find({}, (err, tasklist) => {
    if (err) {
      console.log("error in home render");
    }
    return res.render("home", {
      tasklist: tasklist,
    });
  });
};

//controller for creating the task
module.exports.create = function (req, res) {
  //console.log(req.body);
  console.log(req.body);
  Task.findOne(req.body, function (err, task) {
    if (err) {
      console.log("error in find");
      return;
    }
    if (task) {
      console.log("task exists");
      return res.redirect("back");
    } else {
      Task.create(req.body, function (err, task) {
        if (err) {
          console.log("error in creating", err);
          return;
        }
        console.log("task added");
        return res.redirect("back");
      });
    }
  });
  return;
};

//controller for deleting the task
module.exports.delete = function (req, res) {
  let ids = new Array();
  for (let id in req.query) {
    ids.push(req.query[id]);
  }
  Task.deleteMany({ _id: { $in: ids } }, function (error) {
    if (error) {
      /* on error */
      console.log("Unable to delete from the database.");
      return;
    }
    /* if no error */
    return res.redirect("back");
  });
  return;
};
