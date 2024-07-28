/** @file
 * @brief Ex. 5 S1.01 Impl.
 * @author rbardini
 * @date 20/10/2023
 *
 * On souhaite écrire un programme qui calcule la moyenne de n entiers positifs ou nuls et
qui affiche la moyenne de ces n valeurs. La saisie des valeurs se terminera par -1.
 */

#include <stdio.h>
#include <stdlib.h>

int const FIN = -1;

int main()
{
    int somme = 0;
    int nbValeurs = 0;
    int n;

    do {
        scanf("%d", &n);
        while (n < 0 && n != FIN) {
            printf("Entrée invalide\n");
            scanf("%d", &n);
        }
        if (n != FIN) {
            somme += n;
            ++nbValeurs;
        }
    } while (n != FIN);

    if (nbValeurs == 0) {
        printf("Aucune donnée !\n");
    } else {
        printf("Moyenne : %g\n", somme / (float)nbValeurs);
    }
}