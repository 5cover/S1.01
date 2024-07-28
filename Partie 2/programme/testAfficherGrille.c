/**
 * @brief Tests Sudoku
 * @version 0.0.1
 * @date 13/11/2023
 * @author Raphaël BARDINI 1C2
 *
 * Programme de test pour le Sudoku
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define N 3

#define TAILLE (N * N)

#define VALEUR_VIDE 0
#define AFFICHAGE_PADDING nombreDeChiffres(TAILLE)
#define AFFICHAGE_MARGE_NUMEROS_LIGNES 2
#define AFFICHAGE_ESPACE ' '
#define AFFICHAGE_VALEUR_VIDE '.'
#define AFFICHAGE_INTERSECTION '+'
#define AFFICHAGE_TRAIT_VERTICAL '|'
#define AFFICHAGE_TRAIT_HORIZONTAL '-'

typedef int tGrille[TAILLE][TAILLE];

int nombreDeChiffres(int n);
void afficherGrille(tGrille grille);
void afficherLigneNumerosDeColonne(void);
void afficherLigneSeparationBlocs(void);
void afficherLigneContenu(tGrille grille, int numLigne);
void afficherPlusieursFois(char caractere, int nbFois);
void afficherValeur(int valeur);

int main()
{
    srand(time(NULL));

    tGrille grilleVide = {0};
    tGrille grilleNonVide = {0};
    grilleNonVide[2][3] = 4;
    tGrille grillePleine;

    for (int i = 0 ; i < TAILLE; ++i) {
        for (int j = 0; j < TAILLE; ++j) {
            grillePleine[i][j] = rand() % TAILLE;
        }
    }

    afficherGrille(grilleVide);
    afficherGrille(grilleNonVide);
    afficherGrille(grillePleine);

    return EXIT_SUCCESS;
}

int nombreDeChiffres(int n)
{
    return n == 0 ? 1 : (int)log10(abs(n)) + 1;
}

void afficherGrille(tGrille grille)
{
    afficherLigneNumerosDeColonne();

    // Affichage du corps de la grille
    for (int numBloc = 0; numBloc < N; numBloc++) {
        afficherLigneSeparationBlocs();

        // Pour chaque ligne du bloc
        for (int numLigneBloc = 0; numLigneBloc < N; numLigneBloc++) {
            // Faire un calcul pour obtenir le véritable numéro de ligne, puis afficher la ligne.
            afficherLigneContenu(grille, numBloc * N + numLigneBloc);
        }
    }

    // Afficher la dernière ligne de séparation tout en bas
    afficherLigneSeparationBlocs();
}

void afficherLigneNumerosDeColonne(void)
{
    afficherPlusieursFois(AFFICHAGE_ESPACE, AFFICHAGE_PADDING + AFFICHAGE_MARGE_NUMEROS_LIGNES);

    for (int numBloc = 0; numBloc < N; numBloc++) {
        putchar(AFFICHAGE_ESPACE);
        for (int numColonneBloc = 0; numColonneBloc < N; numColonneBloc++) {
            // Ajouter 1 pour afficher les numéros de 1 à N et non pas de 0 à N - 1.
            printf("%c%*d%c", AFFICHAGE_ESPACE, AFFICHAGE_PADDING, numBloc * N + numColonneBloc + 1, AFFICHAGE_ESPACE);
        }
    }

    putchar('\n');
}

void afficherLigneSeparationBlocs(void)
{
    afficherPlusieursFois(AFFICHAGE_ESPACE, AFFICHAGE_PADDING + AFFICHAGE_MARGE_NUMEROS_LIGNES);
    putchar(AFFICHAGE_INTERSECTION);

    for (int numBloc = 0; numBloc < N; numBloc++) {
        // Ajouter 2 pour prendre en compte la marge horizontale des valeurs (1 espace à gauche et à droite).
        afficherPlusieursFois(AFFICHAGE_TRAIT_HORIZONTAL, N * (AFFICHAGE_PADDING + 2));
        putchar(AFFICHAGE_INTERSECTION);
    }

    putchar('\n');
}

void afficherLigneContenu(tGrille grille, int numLigne)
{
    // Affichage du numéro de ligne
    printf("%*d", AFFICHAGE_PADDING, numLigne + 1);
    afficherPlusieursFois(AFFICHAGE_ESPACE, AFFICHAGE_MARGE_NUMEROS_LIGNES);
    putchar(AFFICHAGE_TRAIT_VERTICAL);

    // Affichage du contenu de la ligne
    for (int numBloc = 0; numBloc < N; numBloc++) {
        for (int numColonneBloc = 0; numColonneBloc < N; numColonneBloc++) {
            afficherValeur(grille[numLigne][numBloc * N + numColonneBloc]);
        }
        putchar(AFFICHAGE_TRAIT_VERTICAL);
    }

    putchar('\n');
}

void afficherValeur(int valeur)
{
    putchar(AFFICHAGE_ESPACE);

    if (valeur == VALEUR_VIDE) {
        printf("%*c", AFFICHAGE_PADDING, AFFICHAGE_VALEUR_VIDE);
    } else {
        printf("%*d", AFFICHAGE_PADDING, valeur);
    }

    putchar(AFFICHAGE_ESPACE);
}

void afficherPlusieursFois(char caractere, int nbFois)
{
    for (int fois = 0; fois < nbFois; fois++) {
        putchar(caractere);
    }
}
