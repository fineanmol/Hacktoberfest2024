const axios = require('axios');


const createRespectiveMnC = (fileName,modelData, controllerData) => { 
    
    const fs = require('fs');
    const shell = require('shelljs');
    // console.log(shell.exec('pwd')) // see where we are at the current working time
    shell.touch([`src/models/${fileName}.model.js`,`src/controllers/${fileName}.controller.js`])
    fs.writeFile(`src/models/${fileName}.model.js`,modelData,(err, data) => {catchErr(err, 'writingModelFile')})
    fs.writeFile(`src/controllers/${fileName}.controller.js`,constollerData,(err, data) => {catchErr(err, 'writeControllerFile')})
      
 }

async function getUser(modelArr) {
  try {
    //   console.log(modelArr,"modelArr")
    
    for (var i in modelArr) {
        url = `https://express-schema.netlify.app/samples/models/${modelArr[i]}.model.js`
        const modelResponse = await axios.get(url);
        modelData = modelResponse.data;

        url = `https://express-schema.netlify.app/samples/controllers/${modelArr[i]}.controller.js`
        const contollerResponse = await axios.get(url);
        controllerData = contollerResponse.data;
        createRespectiveMnC(modelArr[i],modelData, controllerData)
    }
  } catch (error) {catchErr(error)}
}



function catchErr(err='noError',funcName) {
if(err!==null) console.log(`error from ${funcName}`,err);    
}

module.exports=(modelArr)=>{ getUser(modelArr) }