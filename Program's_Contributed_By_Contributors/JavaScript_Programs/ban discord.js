const Discord = require("discord.js");

module.exports = {
    name: 'ban',
    aliases: [],
    description: 'Tag a member and ban them.',
    permission: "BAN_MEMBERS",
    args: true,
    usage: "<Mention or User ID {Reason}>",
    execute(message, args) {

        if(message.channel.id=== '753927263002820639'){
        let toBan = message.mentions.members.first() || message.guild.members.cache.get(args[1]) || message.guild.members.cache.find(x => x.user.username.toLowerCase() === args[1]);
        if (!toBan) return message.channel.send(`${message.author}, you need to provide more arguments,\nproper usage would be:  \`!ban <@mention> <reason>\` `);

        if (!message.member.hasPermission("BAN_MEMBERS")) return message.channel.send("You need permissions!");
        if (!message.guild.me.hasPermission("BAN_MEMBERS")) return message.channel.send("Bot need permissions!"); 

        if(toBan.hasPermission("MANAGE_MESSAGES")) return message.reply("That person is a Staff member and moreover they're cool! I dont feel like disturbing them..");        
        const reason = args.slice(2).join(" ");  "There was no reason!";
        const banDM = new Discord.MessageEmbed()
        .setTitle("Ban!")
        .setDescription("You've been banned from Among Us - India.")
        .setColor("#a60505")
        .addField("Reason: ", reason)
        //.addField("If you think the ban wasn't rightful, appeal here - ", `https://forms.gle/7XTZuAPvVuXL27Ce7`)
        //.setFooter("https://forms.gle/7XTZuAPvVuXL27Ce7");
        .addField("If you think the ban wasn't rightful, appeal here - ", "-->[Ban appeal form!](https://forms.gle/7XTZuAPvVuXL27Ce7)<--");
        //toBan.send(banDM);
        //[Click Here!](${warns[wUser.id].warns[index].directLink}
        
        
        const banEmbed = new Discord.MessageEmbed()
        .setDescription("Ban!")
        .setColor("#a60505")
        .addField("Banned User: ", `${toBan} with ID: ${toBan.id}`)
        .addField("Banned By: ", `${message.author} with ID: ${message.author.id}`)
        .addField("Channel: ", message.channel)
        //.addField("Time: ", message.createdAt)
        .addField("Reason: ", reason)
        .setTimestamp();
        
        let banChannel = message.guild.channels.cache.find(channel => channel.name === "aui-mod-logs");
        if(!banChannel) return message.channel.send("Can't find aui-mod-logs channel.");

        //message.delete().catch(O_o=>{});
        banChannel.send(banEmbed);
        
        const banack = new Discord.MessageEmbed()
        .setColor("#42f59e")
        .addField(`${toBan.user.tag} has been banned from the server!`, `Reason: ${reason}`)
        message.channel.send(banack)
        toBan.ban({
            reason: reason
        });
        //message.channel.send(`${toBan} has been banned from the server!\nReason: ${reason}`);
        // const banack = new Discord.MessageEmbed()
        // .setColor("#42f59e")
        // .addField(`${toBan} has been banned from the server!`, `Reason: ${reason}`)
        // message.channel.send(banack)
    }}
}
