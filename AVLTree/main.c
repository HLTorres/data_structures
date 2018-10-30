#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"

int main()
{
    ArvAVL * raiz;
    int chaves[] = {1,2,3,10,4,5,9,7,8,6};
    int nChaves = sizeof(chaves)/sizeof(int);
    int flag, i;

    raiz = cria_arvAVL();

    for(i = 0; i < nChaves; ++i) {
        flag = insere_arvAVL(raiz, chaves[i]);
        //preOrdem_arvAVL(raiz);
        //printf("=========\n");
    }

    printf("\nAVL tree:\n");
    emOrdem_arvAVL(raiz);
    printf("\n\n");


    flag = remove_arvAVL(raiz, 6);
    printf("\nAVL tree:\n");
    emOrdem_arvAVL(raiz);
    printf("\n\n");

    flag = remove_arvAVL(raiz, 7);
    printf("\nAVL tree:\n");
    emOrdem_arvAVL(raiz);
    printf("\n\n");

    flag = remove_arvAVL(raiz, 4);
    printf("\nAVL tree:\n");
    emOrdem_arvAVL(raiz);
    printf("\n\n");

    libera_arvAVL(raiz);

    return 0;
}
