#include <stdio.h>
#include "headers/minMax.h"

int main(int argc, char *argv[])
{
    int board[16][3];

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = atoi(argv[i * 3 + j + 1]);
        }
    }

    decisionAlphaBeta(atoi(argv[49]), board, atoi(argv[50]));

    FILE *fptr;
    fptr = fopen("result.txt", "w");
    if (fptr == NULL) {
        printf("Erreur lors de l'ouverture du fichier.");
        return 1;
    }

    // Écriture des résultats dans le fichier
    fprintf(fptr, "Résultat de l'exécution du programme C.");

    fclose(fptr);

    return 0;
}