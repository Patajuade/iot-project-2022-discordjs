  
  
# Projet IOT B2Q2

Ce projet rassemble les différents fichiers constituant mon projet d'IOT B2Q2.

#

# Description du projet

J'ai créé un dé 20, qui fonctionne avec un bot discord.

## **Mise en scène ;**

Nous sommes 4 personnes et nous jouons à un jeu de rôles. 3 d'entre nous ont un dé, et le 4eme joueur n'en a pas (parce que c'est long à fabriquer...).

Lorsqu'un joueur "lance" son dé, il voit le résultat dessus, et ce résultat est aussi envoyé sur le channel discord où tous les joueurs sur le channel de la partie peuvent le voir.

Celui qui n'a pas encore son dé peut simplement écrire /rand dans le chat discord : cette commande simule un dé, permettant à ceux qui n'ont pas de dé, de jouer quand même !
  
#

# Fonctionnement

Lorsque l'on secoue le dé, il génère un nombre random. Ce résultat est affiché sur la matrice de leds lui servant d'écran. Ces deux opérations sont gérées par l'arduino. Ensuite, l'arduino envoie ce résultat à l'ESP. L'ESP va se comporter en tant que client du bot discord. Il envoie le numéro obtenu au bot discord via une requête GET.

Le bot discord est sur un serveur OVH et a une IP dédiée, c'est sur cette IP qu'on va faire la requête.

Le bot discord recoit le résultat, et en fait un joli message.