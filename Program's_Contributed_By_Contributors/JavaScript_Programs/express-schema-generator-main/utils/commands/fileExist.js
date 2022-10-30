const fs = require('fs');
const shell = require('shelljs');
fileExistBoolean = (fileName) =>{

     fs.readdir(`src/${fileName}`,(err,data)=>{
        if(err) {
            console.log(`Error: Wrong Path not found **${fileName}** Directory
Please Go inside the Project that You created using

||| create-express-schema <YourProjectName>  |||
use >>> cd <YourProjectName> <<< to Go inside your Project Folder

use >>> ls <<< to check there is controllers and models Directories    
            `);
            console.log(err.message);
            shell.exit();
             }
        
        // console.log(true, "file Exist Move On")
        // return true;
        }
        )
    return true;
}



module.exports = fileExistBoolean;