#!/usr/bin/env node

var shell = require('shelljs');
const path = require('path');
const fs = require('fs');

const { Command } = require('commander');
const program = new Command();

const welcome = require('./commands/welcome');


program.command('create')
        .argument('<string>', 'project name')
        .description('Create Folder Schema except models and Controllers')
        .action(function() {
            if(this.args.length!==0) {
                const createFolderSchema = require('./commands/create.command');
                createFolderSchema(this.args)
                }
            else{console.log("Please Provide the Project Name");shell.exit();}
        });


program.command('add')
        .argument('<string>', 'model names with space')
        .description(`After cd in <projectName> run this command
this create model and controller and add in respected folder 
for more https://github.com/shaantanu9/expressSchema
        `)
        .action(function() {

            const fileExist = require('./commands/fileExist');

            let controllerExist =  fileExist('controllers').fileExistBoolean
            let modelExist =  fileExist('models').fileExistBoolean

            const addMnCCommand = require('./commands/addMnC.command');

            if(this.args.length!==0) {addMnCCommand(this.args)}
            else{console.log("Please Provide the Model Name to clone")}
        });


program.command('delete')
        .argument('<string>', 'project name to delete')
        .description(` delete the project in Seconds`)
        .action(function() {
            shell.exec(`rm -rf ${this.args}`)
        })

program.parse();
