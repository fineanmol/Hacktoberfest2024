const Discord = require("discord.js");

module.exports = {
    name: 'report',
    aliases: [],
    description: 'Tag a member to report them.',
    permission: "SEND_MESSAGES",
    args: true,
    usage: "{@mention} or User ID <reason> [this is how you convert an ID to mention => <@ID>]",
    execute(message, args) {
        if (message.channel.id === '783981509421170698'){ 
            let rUser = message.mentions.members.first() || message.guild.members.cache.get(args[0]);
            if (!rUser) return message.channel.send(`${message.author}, you need to provide more arguments,\nproper usage would be:  \`!report <@mention> <reason>\` \n [this is how you convert an ID to mention => <@ID>] `)
            const reason = args.slice(2).join(" ");

            //let reportEmbed = new Discord.MessageEmbed()
            const reportEmbed = new Discord.MessageEmbed()
            .setDescription("Reports")
            .setColor("#15f153")
            .addField("Reported User: ", `${rUser} with ID: ${rUser.id}`)
            .addField("Reported By: ", `${message.author} with ID: ${message.author.id}`)
            .addField("Channel: ", message.channel)
            //.addField("Time: ", message.createdAt)
            .addField("Reason: ", reason)
            .setTimestamp();
            
            //let reportschannel = message.guild.channels.cache.find(`name`, "reports");
            //if(!reportschannel) return message.channel.send("Couldn't find reports channel.");

            let reportsChannel = message.guild.channels.cache.find(channel => channel.name === "aui-reports");
            if(!reportsChannel) return message.channel.send("Can't find aui-reports channel.");;

            message.delete().catch(O_o=>{});
            reportsChannel.send(reportEmbed);
            reportsChannel.send(`Reported <User ID>: ${rUser.id}`);
            reportsChannel.send(`Reported By <User ID> ${message.author.id}`);
            //message.channel.send(reportEmbed);
        }
    }
}
