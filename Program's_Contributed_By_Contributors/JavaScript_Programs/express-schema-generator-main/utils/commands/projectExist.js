const fs = require('fs');

projectExist = (path) => {
try {
  if (fs.existsSync(`./${path}`)) {
    //file exists
    console.log(" Sorry Same Name File Already Exist, Try Another Name")
    shell.exit()
  }
} catch(err) {
  console.error("err")
}
}

module.exports = projectExist;                