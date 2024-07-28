# Implémentation

## Constantes

nom|type|valeur|description
-|-|-|-
N|entier|$3$                      | facteur de taille de la grille
NB_GRILLES|entier|$10$            | nombre de grilles prédéfinies disponibles
LONGUEUR_MAX_COMMANDE|entier|$64$ | longueur maximum d'une commande et de ses arguments
COTE_GRILLE|entier|$N^2$          | côté de la grille
SOMME_VALIDITÉ|entier|$\frac{N*(N+1)}{2}$ | somme de tout bloc/ligne/colonne complet et valide

## Alias

nom|type|description
-|-|-
t_grilleEntier|`tableau[COTE_GRILLE][COTE_GRILLE] de entier`| valeurs d'une grille de Sudoku. Une valeur négative indique qu'elle est initiale et ne devrait pas être modifiée.

## Déroulement du programme

1. Choisir une grille *.sud
2. Lire le fichier et construire la grille
3. Jusqu'à ce que la grille soit complète et valide ou que le joueur abandonne :
    1. Afficher la grille
    2. Demander à entrer une commande
    3. Exécuter la commande
    4. Afficher la sortie de la commande

## Stratégie

### Grille complète

La grille est complète si toutes les valeurs sont valides et elle ne comporte pas de 0.

Une valeur est valide si il n'est répété ni dans son bloc, ni dans sa ligne ou sa colonne.

Pour savoir, on peut calculer la somme de chaque ligne, chaque colonne et chaque bloc et vérifier que tout est égal à la somme de validité :

$V_N=\frac{N^2*(N^2+1)}{2}$

$V_3=\frac{3^2*(3^2+1)}{2}=45$

Nombre d'itérations :

$O(N) = 3N^3$

$O(3) = 81$

## Commandes

Erreurs de commande :

- commande invalide
- commande inconnue
- mauvais nombre d'arguments
- arguments invalides
- commande invalide pour l'état actuel de la partie.

Fonctions :

`fonction commande{désignation}([arguments][, paramètres]) délivre booléen`

où désignation est le nom en français de la commande

Retour : si la commande a réussi

### `help`

1. s'assurer qu'il n'y a aucun argument
2. appeler `afficherAide`

### `mv`

1. s'assurer qu'il y a deux arguments
2. les convertir en entiers (avec lettres)
3. s'assurer qu'ils respectent la contrainte COTÉ_GRILLE
4. assigner ligneCurseur
5. assigner colonneCurseur

### `set`

1. s'assurer qu'il y a un argument
2. le convertir en entier
3. s'assurer qu'il respecte la contrainte COTÉ_GRILLE
4. s'assurer que la valeur à la position actuelle n'est pas initial
5. assigner la valeur à la position actuelle dans grille

### `rm`

1. s'assurer qu'il n'y a aucun argument
2. s'assurer la valeur à la position actuelle n'est pas initial
3. supprimer la valeur à la position actuelle

### `reset`

1. supprimer toutes les valeurs non initiales

### `exit`

1. Afficher un message de fin
2. Sortir de la boucle principale (on peut utiliser un flag booléen)
