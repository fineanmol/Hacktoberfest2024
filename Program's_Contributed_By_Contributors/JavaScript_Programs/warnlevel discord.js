const fs = require('fs');
const { MessageEmbed } = require('discord.js')
 
module.exports = {
    name: 'warnlevel',
    aliases: ["warns", "warnings"],
    permission: 'MUTE_MEMBERS',
    description: 'Check warning level of user',
    args: true,
    usage: "<Mention or User ID {Reason}>",
    async execute(message, args) {
        let warns = JSON.parse(fs.readFileSync("./warnings.json"));
        let wUser = message.mentions.members.first() || message.guild.members.cache.get(args[0])
        if (!wUser) return message.channel.send(`${message.author}, you need to provide more arguments,\nproper usage would be:  \`!warnlevel <@mention>\` `)

        //if(!wUser) return message.reply("Couldn't find the User..");
                
        if (warns[wUser.id])  warnlevel = warns[wUser.id].warns.length;
        else warnlevel = 0
 
        const embed = new MessageEmbed()

        var warnCheck = 1;
        
        if (warnlevel !== 0) {
            for (var index = 0; index < warns[wUser.id].warns.length; index++) {
                embed.addField(
                    `Warn ${warnCheck}`,
                    `**Moderator:** ${warns[wUser.id].warns[index].warnedBy.tag} (${warns[wUser.id].warns[index].warnedBy.id})\n**Reason:** ${warns[wUser.id].warns[index].reason}\n**Detailed Embed:** [Click Here!](${warns[wUser.id].warns[index].directLink})`
                )
                warnCheck++;
            }
        }
    
        message.reply(`<@${wUser.id}> has ${warnlevel} warning(s)..`)
        if (warnlevel !== 0) message.channel.send(embed)
    }
}
