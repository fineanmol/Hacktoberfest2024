const Discord = require('discord.js');
const client = new Discord.Client();
const axios = require('axios');

client.on('ready', () => {
  console.log(`Logged in as ${client.user.tag}!`);
});

setInterval(function(){
  axios.get("https://us-central1-digitaleyes-prod.cloudfunctions.net/offers-retriever?collection=Solarians&price=asc")
  .then((response) => {
      var price = response.data.offers[0].price;
      var name = response.data.offers[0].metadata.name
    client.user.setPresence({
      activity: {
        name: `Price Floor: ${price / 1000000000} SOL for ${name} || By @Revan AR`,
        type: 'WATCHING'
      }
    })        
  })
  .catch((err) => {
    return "gagal";
  })
}, 3000);

// READ THIS LINE
client.login('change this text with your bot token from https://discord.com/developers');
