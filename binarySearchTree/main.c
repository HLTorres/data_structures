#include <stdio.h>
#include "arvorebinaria.h"

int main()
{
    ArvBin * raiz; // ponteiro para ponteiro
    int flag;

    raiz = cria_arvoreBinaria();

    flag = insere_arvoreBinaria(raiz, 30);

    int h = altura_arvoreBinaria(raiz);

    int nNoh = totalNoh_arvoreBinaria(raiz);

    flag = consulta_arvoreBinaria(raiz, 30);

    // preOrdem_arvoreBinaria(raiz);
    // emOrdem_arvoreBinaria(raiz);
    // posOrdem_arvoreBinaria(raiz);

    if(estaVazia_arvoreBinaria(raiz))
    {

    }

    flag = remove_arvoreBinaria(raiz, 30);
    libera_arvoreBinaria(raiz);

    printf("Hello World!\n");
    return 0;
}
