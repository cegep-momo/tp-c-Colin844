# Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de les copiers dans le repertoire `build` avec l'application `bibliotheque`

# Veille technologique
## Question 1: C++
### Une notion que j'ai utilisée, mais que nous n'avons pas/peu vu dans le cours est la gestion des dates et des heures avec 'C++'. Pour utiliser les logs de la question bonus, il fallait d'abord importer la librairie <ctime>. J'ai ensuite pu utiliser les fonctions 'C' comme time ou localtime pour les logs. J'ai appris qu'il existait des outils plus modernes comme 'std::chrono' pour représenter des instants, mais l'utilisation de ctime était suffisante pour moi. Le fonctionnement est assez classique et ressemble un peu au fonctionnement de Java avec Java.time. Pour '<ctime>' il existe plusieurs types de données comme 'tm_sec' ou 'tm_min' pour avoir le nombre de secondes en une minute/le nombre de minutes en une heure, mais celle que j'ai utilisée est 'localtime()' qui permet de gérer et d'afficher l'horodatage (timestamps).

## Question 2: Options de développement possible
### Une solution plus adaptés pour gérer la bibliothèque (dans l'éventualité où elle contient des millions de livres) est d'externaliser le stockage en utilisant une base de donnée relationnelle (PostgreSQL, MySQL, etc.). Une base de donnée permetrait de stocker les enregistrements (principalement les utilisateurs et les livres) de façon plus structurée, plutôt que de tout mettre dans un fichier ".txt". Cela faciliterait aussi les recherches par titre/auteur, car nous n'aurions qu'à chercher les colonnes correspondantes aux informations recherchées. Cependant, il faudrait utiliser une bibliothèque (appelée “connecteur”) qui sert d’intermédiaire car C++ ne peut pas directement parler à une base de données. Les étapes d'accès sont assez similaires aux autres langages: Connexion à la base de donnée, exécution des commandes SQL (SELECT, INSERT, etc.), lecture des résultats et fermeture de la connexion.
