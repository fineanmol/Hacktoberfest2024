var shell = require('shelljs');
const path = require('path');
const fs = require('fs');

const editPackageJson = async(folderName) =>{

    const packageJsonPath = await path.join(""+shell.exec('pwd'),"..",""+folderName,'./package.json')
    // const packageJsonPath = await path.join(__dirname,"..",""+folderName,'./package.json')
    let editPackageJson = require(packageJsonPath);
    editPackageJson.scripts.server = 'nodemon src/index'

    editPackageJson = JSON.stringify(editPackageJson, undefined, '\t')
    fs.writeFile(packageJsonPath,editPackageJson,(err, data) => {catchErr(err, 'writingModelFile')})
    

}

const installPackages = async (folderName) => { 
    
    shell.cd(folderName)
    // createGitIgnoreNEnv(folderName);
    shell.exec('npm init -y')
    editPackageJson(folderName);
    shell.exec('npm i express mongoose')
    
}



const createFolderSchema = (folderName) => { 

    const projectExist = require('./projectExist');
    projectExist(folderName);
    // shell.exit();
    // try{
    //     shell.find('node_modules')
    // }catch(e) {catchErr(e,"Folder / Project With Same name already exists")} 



    shell.exec(`mkdir ${folderName}`);
    installPackages(folderName);

    shell.exec(`mkdir src`)
    shell.cd(`src`)
    shell.mkdir('-p',['models', 'controllers','configs','middlewares','uploads'])

    shell.touch(['index.js','models/user.model.js','controllers/user.controller.js','controllers/crud.controller.js','configs/db.js','middlewares/file-uploads.js','middlewares/authenticate.js'])
    createExpressServer()
    createExpressServer('.env')
    createExpressServer('.gitignore')
    createExpressServer('configs/db.js')
    createExpressServer('controllers/crud.controller.js')

}



async function createExpressServer(fileName='index.js') {
  try {
        const axios = require('axios');

        url = `https://express-schema.netlify.app/samples/${fileName}`
    
        // for .env and .gitignore
        if(fileName.includes('.') && !fileName.includes('.js')) {  
            url = `https://express-schema.netlify.app/samples/${fileName.split('.')[1]}`
            
            }
    
        const indexResponse = await axios.get(url);
        indexData = indexResponse.data;
        const fs = require('fs');
        fs.writeFile(`${fileName}`,indexData,(err, data) => {catchErr(err, `Writing in ${fileName} CreatingExpressServer`)})
    }catch(err) {catchErr(err, 'CreatingExpressServer Whole')}

        if(fileName.includes('.') && !fileName.includes('.js')) {  
            try{shell.mv(fileName,'../')}catch(e){catchErr(e,"while Moving file ENV and gitignore")}
        }
}



function catchErr(err='noError',funcName) {
if(err!==null) {console.log(`error from ${funcName}`,err);}    
}


module.exports = createFolderSchema