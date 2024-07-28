# Cahier de test

## 1 : chargement du fichier

test de la procédure *chargerGrille*

**Contexte d'exécution** : aucun

**À effectuer** : saisir un nom de fichier

N°|type|données entrées|résultat attendu
-|-|-|-
1|d'erreur|ouverture du fichier impossible (le fichier n'existe pas...)|grille inchangée
2|d'erreur|le nom du fichier fait plus de 30 caractères|possible erreur de segmentation, grille inchangée
3|nominal|le fichier s'ouvre correctement|grille remplie

## 2 : affichage de la grille

test de la procédure *afficherGrille*

**Contexte d'exécution** : aucun

**À effectuer** : rien

N°|type|données entrées|résultat attendu
-|-|-|-
1|particulier|grille vide (tout 0)|affichage correct
2|nominal|grille non vide|affichage correct
3|particulier|grille pleine (aucun 0)|affichage correct

## 3 : saisie coordonnées d’une case

test de la fonction *saisir*

**Contexte d'exécution** : aucun

**À effectuer** : saisir un entier

N°|type|données entrées|résultat attendu
-|-|-|-
1|erreur|pas un entier|message d'erreur et 0 retourné
2|erreur|entier hors limites|message d'erreur et 0 retourné
3|nominal|entier correct|valeur de l'entier retourné

## 4 : saisie d’une valeur à insérer

test de la boucle principale

**Contexte d'exécution** : boucle principale, ligne et colonne saisies

**À effectuer** : saisir une valeur à ajouter

N°|type|données entrées|résultat attendu
-|-|-|-
1|erreur|la valeur est déjà présente sur la même ligne que la case|message d'erreur
2|erreur|la valeur est déjà présente sur la même colonne que la case|message d'erreur
3|erreur|la valeur est déjà présente dans le même bloc que la case|message d'erreur
4|erreur|valeur invalide|message d'erreur
5|erreur|valeur hors limites|message d'erreur
6|nominal|valeur correcte|grille modifiée

## 5 : fin de partie

test de la fonction *estGrillePleine*

**Contexte d'exécution** : aucun

**À effectuer** : rien

N°|type|données entrées|résultat attendu
-|-|-|-
1|nominal|grille vide|faux
2|nominal|grille non vide|faux
3|nominal|grille pleine|vrai
