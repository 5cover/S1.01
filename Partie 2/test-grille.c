#include <stdio.h>
#include <stdlib.h>

#define TAILLE_FICHIER 324
#define N 3
#define COTE_GRILLE (N * N)
#define NB_CASES_GRILLE (COTE_GRILLE * COTE_GRILLE)
#define RIEN '.'

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("%s <numeroGrille>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int numGrille = atoi(argv[1]);
    if (numGrille < 1 || numGrille > 10) {
        printf("numéro de grille invalide\n");
        return EXIT_FAILURE;
    }

    char const fmt_chemin[] = "grilles/Grille%d.sud";
    char chemin[sizeof(fmt_chemin)];
    sprintf(chemin, fmt_chemin, numGrille);

    FILE *grille = fopen(chemin, "r");
    if (grille == NULL) {
        printf("%s : ", chemin);
        perror("impossible d'ouvrir le fichier");
        return EXIT_FAILURE;
    }

    for (int iGrille = 0; iGrille < TAILLE_FICHIER / NB_CASES_GRILLE; ++iGrille) {
        for (int iLigne = 0; iLigne < COTE_GRILLE; ++iLigne) {
            for (int iCol = 0; iCol < COTE_GRILLE; ++iCol) {
                int c = getc(grille);
                if (c == 0) {
                    printf(" %c", RIEN);
                } else {
                    printf(" %d", c);
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    fclose(grille);

    return EXIT_SUCCESS;
}