
const { SlashCommandBuilder } = require('@discordjs/builders');

module.exports = {
	data: new SlashCommandBuilder()
		.setName('répondencué')
		.setDescription('Allows you to trigger the bots anger issues'),
	async execute(interaction) {
		await interaction.reply(`Nique ta mère ${interaction.user.tag} ! `);
	},
};