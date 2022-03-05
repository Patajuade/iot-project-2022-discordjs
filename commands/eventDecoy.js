
//trying to make an embed message
const { MessageEmbed } = require('discord.js');
const { MessageAttachment } = require('discord.js');
const { SlashCommandBuilder } = require('@discordjs/builders');
const { Guild } = require("discord.js");

//random generator to simulate the future dice
function getRandomArbitrary(min, max) {
    result = Math.random() * (max - min) + min;
    return Math.ceil(result);
  }
  //const attachment = new MessageAttachment();
  function getAnImageOfTheNumberObtained(randomNumber){
      if (randomNumber == 1) {
        attachment = new MessageAttachment('C:/Users/MVP PatateChaude/Desktop/numbersImages/1.png', '1.png');
              return attachment;
      }
      if (randomNumber == 2) {
        attachment = new MessageAttachment('C:/Users/MVP PatateChaude/Desktop/numbersImages/2.png', '2.png');
              return attachment;
      }
      if (randomNumber == 3) {
        attachment = new MessageAttachment('C:/Users/MVP PatateChaude/Desktop/numbersImages/3.png', '3.png');
              return attachment;
      }
      
  }

const message = (userInteractingName, userInteractingAvatar, randomNumber)=>new MessageEmbed()
    .setColor('#3c020c')
    .setTitle(userInteractingName + ' a secoué le dé !')
    .setURL('https://www.youtube.com/watch?v=dQw4w9WgXcQ&ab_channel=RickAstley')
    .setAuthor({ name: userInteractingName, iconURL: userInteractingAvatar, url: 'https://www.youtube.com/watch?v=dQw4w9WgXcQ&ab_channel=RickAstley' })
    .setDescription('Hé bah jespère que vous secouez pas votre queue comme ça...')
    .setThumbnail('https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcS2YP6ghYK9gBo1F4p7-bpNaiHafo77dVppZA&usqp=CAU')
    .addField('___________________', 'Resultat du rand : '+ randomNumber, true)
    .setImage('https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcS2YP6ghYK9gBo1F4p7-bpNaiHafo77dVppZA&usqp=CAU')
    .setTimestamp()

module.exports = {

    data: new SlashCommandBuilder()
        .setName('rand')
        .setDescription('Does its job for once'),

    async execute(interaction) {

        //channel.send({ embeds: [exampleEmbed] });
        await interaction.reply({ embeds: [message(interaction.user.tag, interaction.user.displayAvatarURL(),getRandomArbitrary(1,20))] });
        //const guild = new Guild(interaction.guild.id).channels;
        //console.log(guild);
    }
}