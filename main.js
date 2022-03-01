
//main
// node main.js -> to run
// ctrl + C -> to stop

// Require the necessary discord.js classes
const fs = require('node:fs'); //fs is Node's native file sustem module
const { Client, Collection ,Intents } = require('discord.js');
const { token } = require('./config.json');

// Create a new client instance
const client = new Client({ intents: [Intents.FLAGS.GUILDS] });
client.commands = new Collection(); //We recommend attaching a .commands property to your client instance so that you can access your commands in other files
const commandFiles = fs.readdirSync('./commands').filter(file => file.endsWith('.js')); // fs.readdirSync() method will return an array of all the file names in a directory

for (const file of commandFiles) {
	const command = require(`./commands/${file}`);
	// Set a new item in the Collection
	// With the key as the command name and the value as the exported module
	client.commands.set(command.data.name, command);
}

// When the client is ready, run this code (only once)
client.once('ready', () => {
	console.log('Ready!');
});

//replying to commands
client.on('interactionCreate', async interaction => {
	if (!interaction.isCommand()) return; //check if an interaction is a command

	const command = client.commands.get(interaction.commandName);

	if (!command) return;

	try {
		await command.execute(interaction);
	} catch (error) {
		console.error(error);
		await interaction.reply({ content: 'There was an error while executing this command!', ephemeral: true });
	}
  
});

// Login to Discord with your client's token
client.login(token);



