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

#define N 3

#define TAILLE (N * N)

void saisir(int *saisie)
{
    char entree[20];  // buffer d'entrée
    int entreeEntier; // entier entré converti
    bool erreurDeSaisie = true;

    while (erreurDeSaisie) {
        // scanf lira au maximum 19 caractères, et non pas 20,
        // car il faut conserver une place pour le caractère de fin de chaîne '\0'.
        scanf("%19s", entree);
        if (sscanf(entree, "%d", &entreeEntier) == 0) {
            printf("Veuillez saisir un entier : ");
        } else if (entreeEntier < 1 || entreeEntier > TAILLE) {
            printf("Veuillez saisir un entier entre 1 et %d : ", TAILLE);
        } else {
            erreurDeSaisie = false;
        }
    }

    *saisie = entreeEntier;
}

void casTestSaisir(int attendu)
{
    int recu;
    saisir(&recu);
    printf("\n%6s : %d -> %d\n", attendu == recu ? "SUCCÈS" : "ÉCHEC",
        attendu, recu);
}

int main()
{
    casTestSaisir(1);
    casTestSaisir(2);
    casTestSaisir(3);
    casTestSaisir(4);
    casTestSaisir(5);
    casTestSaisir(6);
    casTestSaisir(7);

    return EXIT_SUCCESS;
}
