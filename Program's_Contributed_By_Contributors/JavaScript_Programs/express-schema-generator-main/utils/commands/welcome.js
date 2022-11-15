const welcome = require('@tos_/cli-welcome');

const packageJson = require('../package.json');

// OR with all the options set like this:
 module.exports =  welcome({
	title: `${packageJson.name}`,
	tagLine: `by ${packageJson.author.name} ${packageJson.author.url}`,
	bgColor: `#FADC00`,
	color: `#FFFFFF`,
	bold: true,
	clear: true,
	version: `${packageJson.version}`,
});