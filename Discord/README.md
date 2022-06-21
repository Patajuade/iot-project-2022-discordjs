# Bot Discord

Les fichiers principaux sont `main.js` où on retrouve la partie principale du code, comme par exemple la gestion de l'API REST du bot (qui lui permet de communiquer avec l'ESP)  et  `deploy-command.js` qui est le gestionnaire des commandes "slash", commandes que l'on retrouve dans le dossier "commands". Dans le dossier "local-ressources" on retrouve les images utilisées pour faire des jolis messages embed.

J'ai utilisé express.js, qui permet de faire une API, avec une route `/roll` sur laquelle je peux faire des GET.
Grâce à Discord.js on peut manipuler l'API de discord, et c'est comme ça qu'on crée un bot Discord. EN ajoutant les commandes de Discord.js au sein du GET de express.js, on déclenche des actions dans le bot discord via un trigger WEB.


## Notes à moi-même

Démarrer le bot : 
Dans le terminal ..\Discord, taper "npm run go", qui est le script permettant le lancement des deux commandes suivantes : "node deploy-commands.js" et "node main.js"

OVH : 

Démarer le bot via cmd

ssh ubuntu@ip_add

pwd vps

Aller dans le dossier du projet

npm run go