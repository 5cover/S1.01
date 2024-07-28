# Sudoku

## Génération de la grille

Lire les *.sud fournis.

## Questions

- Fin de partie / possibilité de perdre
  - Le jeu doit-il se terminer après un trop grand nombre d'erreurs ?
  - Ou alors perdre se fait par un abandon suite à la frustration du joueur ?
  - Possible compromis :
    - demander à confirmer pour terminer la partie
    - le joueur gagne si la grille est correcte, le nombre d'erreurs à corriger est afffiché sinon

> frustration (comme sur papier)
> la partie se termine immédiatement

- Offrir un degré de personnalisation ?
  - Taille de la grille
  - Difficulté (nombre de chiffres initiaux)

> non, mais utiliser constante

- Utiliser plusieurs couleurs pour créer un contraste entre les différents élements de la grille ?
  - Structure de la grille
  - Chiffres initiaux
  - Chiffres ajoutés

> oui puisqu'on sera sous unix

- Le programme est-il censé être multiplateforme ?
  - Utiliser des caractères Unicode pour dessiner la grille de jeu en console
  - Affichage en couleur dans la console

> pas de compilation sous Windows (uniquement linux)

faire très attention aux erreurs de compilation, de runtime et aux warnings!!! (sinon c'est 0)

## Tests

### Commande

Spécification de test : indiquer une description a coter du # de cas

- Commande inconnue
- Argument de commande invalide
- Argument de commande manquant
- Argument de commande

## Consignes maquette

Promesse au client

- présenter clairement l'ensemble des différents écrans ou affichages de l'interface utilisateur prévue,
- de bien distinguer le "dessin" de la maquette (à gauche) et les explications personnelles de l'étudiant (à droite),
- de prévoir les saisies possibles de l'utilisateur,
- d'envisager et de montrer des cas d'erreur.

## Exercices sur les test

### Exercice 1|

Cas nominaux

> la connexion doit réussir

1. un identifiant et un mot de passe valides

Cas particulier

Cas limite

Cas d'erreur

> un message d'erreur doit s'afficher

1. Champs "identifiant" ou "mot de passe" vides
2. Identifiant inconnu
3. Mot de passe invalide
4. Limite de caractères dépassée dans un des champs
5. Caractères interdits dans un des champs (retour à la ligne, etc...)

### Exercice 2

**Identification du test** : test de validité de la première valeur saisie
**Contexte d’exécution** : exécution complète du programme
**Étapes de test à effectuer** : saisir 1 entier

Numéro du cas | description | données de test | résultats attendus | résultats obtenus | succès?
-|-|-|-|-|-
1|erreur|`a`|message d'erreur
2|erreur|`abcd`|message d'erreur
3|erreur|`10.2`|message d'erreur
4|erreur|(rien)|message d'erreur
5|erreur (dépassement d'entier)|`99999999999999999999999999`|message d'erreur
6|nominal|`15`|`15`
7|nominal|`0`|`0`
8|nominal|`-1`|`-1`

**Identification du test** : test de validité de la deuxième valeur saisie
**Contexte d’exécution** : exécution complète du programme
**Étapes de test à effectuer** : saisir 1 entier

Numéro du cas | description | données de test | résultats attendus | résultats obtenus | succès?
-|-|-|-|-|-
1|erreur|`a`|message d'erreur
2|erreur|`abcd`|message d'erreur
3|erreur|`10.2`|message d'erreur
4|erreur|(rien)|message d'erreur
5|erreur (dépassement d'entier)|`99999999999999999999999999`|message d'erreur
6|nominal|`15`|`15`
7|nominal|`0`|`0`
8|nominal|`-1`|`-1`

**Identification du test** : maximum entre 2 entiers saisis - test du calcul du max
**Contexte d’exécution** : exécution complète du programme
**Étapes de test à effectuer** : saisir 2 valeurs entières valides

Numéro du cas | description | données de test | résultats attendus | résultats obtenus | succès?
-|-|-|-|-|-
1|nominal|`10` et `15`|`15`
2|nominal (commutatif)|`15` et `10`|`15`
3|nominal (négatif)|`12` et `-40`|`12`
4|nominal (négatif)|`-12` et `-40`|`-12`
5|particulier (même valeur)|`3` et `3`|`3`
6|particulier (zéro)|`813` et `0`|`813`
7|particulier (zéro)|`0` et `0`|`0`

### Ex 3

Conclusion moyenne.c -:le programme fonctionne pour le calcul de la moyenne mais il y a une erreur d'arrondi et pas de vérification d'intervalle de 0 à 20.

### Ex 4

Conclusion variation.c : le programme ne fonctionne clairement pas. Échoue avec les suites non monotones et quand il n'y a qu'une seule valeur.

### Ex 5

**Identification du test** : test de validité d'une valeur saisie
**Contexte d’exécution** : saisie d'une valeur
**Étapes de test à effectuer** : saisir 1 entier positif ou nul

Numéro du cas | description | données de test | résultats attendus | résultats obtenus | succès?
-|-|-|-|-|-
1|erreur|`a`|message d'erreur
2|erreur|`abcd`|message d'erreur
3|erreur|`10.2`|message d'erreur
4|erreur|`-4`|message d'erreur
5|nominal|`-1`|message d'erreur
6|erreur|`-4.7`|message d'erreur
7|erreur|(rien)|message d'erreur
8|erreur (dépassement d'entier)|`99999999999999999999999999`|message d'erreur
9|nominal|`15`|`15`
10|nominal|`0`|`0`
11|particulier|`-0`|`0`
12|particulier (sentinelle de fin de saisie)|`-1`|`-1`

**Identification du test** : test du calcul de la moyenne
**Contexte d’exécution** : exécution totale du programme
**Étapes de test à effectuer** : saisie d'une suite d'entiers positifs ou nuls

Numéro du cas | description | données de test | résultats attendus | résultats obtenus | succès?
-|-|-|-|-|-
1|erreur|`-1`|Message d'erreur : `Aucune donnée !`
2|nominal|`1 2 3 -1`|`2`
3|nominal|`5 6 -1`|`5.5`
4|nominal|`28 34 67 212 0 4 2 98 -1`|`55.625`
5|particulier (1 valeur)|`4 -1`|`4`
6|particulier (zéro)|`0 0 0 0 0 0 0 0 0 0 0 0 0 0 -1`|`0`
