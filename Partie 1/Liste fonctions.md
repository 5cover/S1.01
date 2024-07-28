# Liste des fonctions du Sudoku

## Grille

Fonctions et procédures de manipulation de grilles de Sudoku.

### Fonction `estGrilleComplète`

Détermine si une grille est complète.

**Paramètres** :
nom|mode|type|description
-|-|-|-
grille|entrée|`t_grilleEntier`| grille à tester

**Retour** : `booléen` : `vrai` si la grille est complète, c'est-à-dire que toutes les valeurs sont renseignées et placées correctement, `faux` sinon.

### Fonction `estValeurInitiale`

Détermine si la valeur spécifée correspond à une valeur initiale.

**Paramètres** :
nom|mode|type|description
-|-|-|-
valeur|entrée|`entier`| valeur d'une grille de Sudoku

**Retour** : `booléen` : `vrai` si *valeur* correspond à une valeur déjà placée sur une grille de Sudoku au départ de la partie, `faux` sinon.

### Procédure `chargerGrille`

Initialise une grille à partir de la grille prédéfinie au numéro spécifié.

**Paramètres** :

nom|mode|type|description
-|-|-|-
numeroGrille|entrée|`entier`   | numéro de la grille prédéfinie à lire
grille|sortie|`t_grilleEntier` | grille à initialiser

### Procédure `écrireGrille`

Affiche une grille à l'écran.

**Paramètres** :
nom|mode|type|description
-|-|-|-
grille|entrée|`t_grilleEntier` | grille à afficher

## Commandes

Fonctions et procédures d'entrée, de traitement et d'exécution de commandes.

### Fonction `entréeCommande`

Permet à l'utilisateur de saisir une commande.

**Paramètres** : aucun.

**Retour** : `chaîne` : commande entrée.

### Fonction `décomposerCommande`

Décompose une commande en ses différentes parties : nom et potentiels arguments.

**Paramètres** :
nom|mode|type|description
-|-|-|-
commande|entrée|`chaîne`    | commande à décomposer
nomCommande|sortie|`chaîne` | assigné au nom de la commande si présent
argument1|sortie|`chaîne`   | assigné au premier argument si présent
argument2|sortie|`chaîne`   | assigné au second argument si présent

**Retour** : `entier` : le nombre d'éléments extraits de la commande spécifiée :

- 0 si aucun élement n'a pu être extrait
- 1 si la commande n'a aucun argument
- 2 si la commande a un argument
- 3 si la commande a deux arguments.

**Remarque** : cette fonction prend des paramètres en sortie mais ne les assigne pas forcément.

### Fonction `exécuterCommande`

Exécute une commande en modifiant si nécessaire l'état de la partie passé en paramètre. Affiche un message approprié en cas d'erreur.

**Paramètres** :
nom|mode|type|description
-|-|-|-
commande|entrée|`chaîne`                | commande à exécuter
grilleJeu|entrée/sortie|`t_grilleEntier`| grille de jeu
ligneCurseur|entrée/sortie|`entier`     | ligne de la case actuellement sélectionnée
colonneCurseur|entrée/sortie|`entier`   | colonne de la case actuellement sélectionnée
quitter|sortie|`booléen`                | assigné au booléen indiquant si l'utilisateur a choisi d'abandonner la partie

**Retour** : `booléen` : `vrai` si la commande a réussi, ou `faux` si la commande a échoué ou est invalide. Une commande peut échouer si ses arguments sont invalides ou si elle désigne une opération impossible en l'état actuel de la partie.

### Fonction `vérifierNombreArguments`

Vérifie qu'une commande a le nombre d'arguments attendu et affiche un message d'erreur si ce n'est pas le cas.

**Paramètres** :
nom|mode|type|description
-|-|-|-
reçu|entrée|`entier`   | nombre d'arguments reçu
attendu|entrée|`entier`| nombre d'arguments attendu

**Retour** : `booléen` : `vrai` si *reçu* est égal à *attendu*, `faux` sinon.

### Fonction `convertirIndiceAxe`

Convertit une chaîne contenant un indice d'axe en entier. Un indice d'axe est un numéro de ligne ou de colonne. Il est représenté par un nombre ou une lettre. Dans ce dernier cas, c'est son ordre dans l'alphabet qui est considéré comme sa valeur. Un indice d'axe commence à 1.

**Paramètres** :
nom|mode|type|description
-|-|-|-
chn|entrée|`chaîne`| chaîne à convertir

**Retour** : `entier` : l'entier converti si *chn* contient un indice d'axe valide, 0 sinon.

### Fonction `commandeAide`

Affiche la liste des commandes. Correspond à la commande `help`.

**Paramètres** : aucun.

**Retour** : `booléen` : `vrai` si la commande a réussi. Toujours `vrai`.

### Fonction `commandeDéplacerCurseur`

Déplace le curseur à l'emplacement sur la grille indiqué. Correspond à la commande `mv`. Affiche un message approprié en cas d'erreur.

**Paramètres** :
nom|mode|type|description
-|-|-|-
argumentLigne|entrée|`chaîne`    | argument 1 de la commande : ligne où déplacer le curseur
argumentColonne|entrée|`chaîne` | argument 2 de la commande : colonne où déplacer le cursuer
ligneCurseur|sortie|`entier`     | assigné à nouvelle ligne du curseur
colonneCurseur|sortie|`entier`   | assigne à la nouvelle colonne du curseur

**Retour** : `booléen` : `vrai` si la commande a réussi, `faux` si *argumentLigne* ou *argumentColonne* ne sont pas des indices d'axe valides ou se situent en dehors de la grille.

### Fonction `commandeEffacerValeur`

Efface la valeur à l'emplacement sur la grille spécifié. Correspond à la commande `rm`. Affiche un message approprié en cas d'erreur.

**Paramètres** :
nom|mode|type|description
-|-|-|-
ligne|entrée|`entier`                | ligne de la valeur à effacer
colonne|entrée|`entier`              | colonne de la valeur à effacer
grille|entrée/sortie|`t_grilleEntier`| grille à modifier

**Retour** : `booléen` : `vrai` si la commande a réussi, `faux` si la valeur à l'emplacement spécifié est initiale et donc non modifiable.

### Fonction `commandeModifierValeur`

Modifie la valeur à l'emplacement sur la grille spécifié. Correspond à la commande `set`. Affiche un message approprié en cas d'erreur.

**Paramètres** :
nom|mode|type|description
-|-|-|-
argumentValeur|entrée|`chaîne`       | argument 1 de la commande : la nouvelle valeur
ligne|entrée|`entier`                | ligne de la valeur à assigner
colonne|entrée|`entier`              | colonne de la valeur à assigner
grille|entrée/sortie|`t_grilleEntier`| grille à modifier

**Retour** : `booléen` : `vrai` si la commande a réussi, `faux` si *argumentValeur* n'est pas une valeur valide ou si la valeur à l'emplacement spécifié est initiale et donc non modifiable.

### Fonction `commandeRecommencer`

Réinitialise une grille à son état de départ. Correspond à la commande `reset`.

**Paramètres** :
nom|mode|type|description
-|-|-|-
grille|entrée/sortie|`t_grilleEntier`| grille à réinitialiser

**Retour** : `booléen` : `vrai` si la commande a réussi. Toujours `vrai`.

### Fonction `commandeQuitter`

Affiche un message d'abandon de la partie. Correspond à la commande `exit`.

**Paramètres** :
nom|mode|type|description
-|-|-|-
quitter|sortie|`booléen`| assigné à `vrai`

**Retour** : `booléen` : `vrai` si la commande a réussi. Toujours `vrai`.

## Utilitaires

Fonctions et procédures génériques non spécifiques au Sudoku.

### Procédure `écrireErreur`

Affiche un message d'erreur à l'écran.

**Paramètres** :
nom|mode|type|description
-|-|-|-
message|entrée|`chaîne`| message d'erreur

### Fonction `convertirEnEntier`

Convertit une chaîne contenant un nombre entier en entier.

**Paramètres** :
nom|mode|type|description
-|-|-|-
chn|entrée|`chaîne`| chaîne à convertir

**Retour** : `entier` : l'entier converti si *chn* contient un nombre entier valide, 0 sinon.

### Fonction `entierAléatoire`

Retourne un entier aléatoire entre deux bornes.

**Paramètres** :
nom|mode|type|description
-|-|-|-
min|entrée|entier| le minimum (inclus)
max|entrée|entier| le maximum (inclus)

**Retour** : `entier` : un entier aléatoire $n$ tel que $n \in [min ; max]$.

### Fonction `longueurChaîne`

Retourne la longueur d'une chaîne de caractères.

**Paramètres** :
nom|mode|type|description
-|-|-|-
chn|entrée|`chaîne`| chaîne à mesurer

**Retour** : `entier` : la longueur de *chn*.

### Fonction `ordreAlphabet`

Retourne l'ordre dans l'alphabet d'une lettre.

**Paramètres** :
nom|mode|type|description
-|-|-|-
lettre|entrée|`caractère`| caractère à tester

**Retour** : `entier` : si le caractère est une lettre minuscule ou majuscule, son ordre dans l'alphabet (entre 1 et 26), sinon 0.
