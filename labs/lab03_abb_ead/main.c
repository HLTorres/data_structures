#include <stdio.h>
#include "arvorebinaria.h"

int main()
{
    ArvBin * raiz; // ponteiro para ponteiro
    int i, count;
    //int chaves[]={50,99,10,45,30,35,5,7};
    int chaves[]={15,10,7,13,14,20,17,25};
    int nChaves = sizeof(chaves)/sizeof(int);

    raiz = cria_arvoreBinaria();

    for(i = 0; i < nChaves; ++i)
        insere_arvoreBinaria(raiz, chaves[i]);

    count = totalNoh_arvoreBinaria(raiz);
    printf("Total de nos da arvore: %d\n",count);

    count = impar_arvoreBinaria(raiz);
    printf("Numero de nos impares: %d\n",count);

    count = folha_arvoreBinaria(raiz);
    printf("Numero de folhas: %d\n",count);

    count = naoFolha_arvoreBinaria(raiz);
    printf("Numero de nos nao folhas: %d\n",count);

    count = maiorNoh_arvBin(raiz);
    printf("MAIOR no na arvore binaria de busca: %d\n", count);

    count = menorNoh_arvBin(raiz);
    printf("MENOR no na arvore binaria de busca: %d\n", count);

    printf("Arvore antes de espelhar:\n");
    posOrdem_arvoreBinaria(raiz);
    if(ehABB_arvBin(raiz) == 1)
        printf("=== E uma arvore binaria de busca!!! ===\n");
    else
        printf("=== NAO e uma arvore binaria de busca!!! ===\n");

    espelho_arvBin(raiz);
    printf("Arvore depois de espelhar:\n");
    posOrdem_arvoreBinaria(raiz);
    if(ehABB_arvBin(raiz) == 1)
        printf("=== E uma arvore binaria de busca!!! ===\n");
    else
        printf("=== NAO e uma arvore binaria de busca!!! ===\n");


    libera_arvoreBinaria(raiz);

    return 0;
}
