
# Comment connecter le gentil ESP à l'internet

Suivre le gentil tuto suivant : https://www.circuitbasics.com/how-to-set-up-a-web-server-using-arduino-and-esp8266-01/


![Une jolie image](img_pour_readme.png)

<em><strong>Mais attention ! </strong></em>

On n'est pas bête comme moi et on ne fait pas des c/c des commandes dans le moniteur série de l'arduino ! En effet la mise en page du site fait que le moniteur de reconnaître pas les gentils caractères !

AT

AT+CWMODE?

AT+CWMODE=3

AT+CWLAP

AT+CWJAP="ssid","password"


Vérifier la connection

AT+CIFSR

Autoriser l'ESP à supporter plusieurs connections

AT+CIPMUX=1 (1 à remplacer par 0 si on peut le reset à une connection simple)

AT+CIPSERVER=1,80 (1 = ouvert, 80 = le port HTTP -> on peut maintenant envoyer des requêtes http du PC vers le module, mais c'est pas vraiment ce qu'on veut)
