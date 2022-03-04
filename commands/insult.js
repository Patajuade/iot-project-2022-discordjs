
const { SlashCommandBuilder } = require('@discordjs/builders');
const { Guild } = require("discord.js");
module.exports = {
	data: new SlashCommandBuilder()
		.setName('répondenculé')
		.setDescription('Allows you to trigger the bots anger issues'),
	async execute(interaction) {
		interaction.member.guild.channels.fetch().then(channels => {
			//channels.map(channel => channel.members.map(member => console.log(member)));
			const voiceChannels = channels.filter(channel=>channel.type==='GUILD_VOICE');
			//console.log(voiceChannels);
			const currentVoiceChannel = voiceChannels.filter(vc=>vc.members.filter(member=>member.user.username===interaction.user.username));
			const members = currentVoiceChannel.map(cvc=>cvc.members);
			members.map(m=>console.log(m.username));
			//console.log(currentVoiceChannel);
		})
		await interaction.reply(`Nique ta mère ${interaction.user.tag} ! `);
	},
};