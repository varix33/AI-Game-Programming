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

    // int numero = 0;
    // int numero2 = 0;
    // char init[1] = "t";
    // char message[15] = "t";

    // while (numero < 10)
    // {
    //     printf("numero : %d\n", numero);

    //     scanf("%d", &numero2);

    //     // do
    //     // {
    //     //     printf("Entrez un nouveau message : ");
    //     //     fgets(message, sizeof(message), stdin);
    //     // } while (strstr(message, "New move : ") == NULL);

    //     // numero++;

    //     // printf("Send : %c%c%c%c\n", message[11], message[12], message[13], message[14]);
    //     // message[0] = init[0];
    // }

    return 0;
}