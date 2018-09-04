#include <stdio.h>
#include <time.h>
#include "escola.h"

int main()
{
    Escola * listaENEM;
    int nEscolas; // armazena a quantidade de escolas cadastradas
    int posicao, i;

    clock_t inicio, fim;
    unsigned long tempo;

    listaENEM = criaLista_arquivo("dadosENEM.txt", & nEscolas);

    //    //****************************
    //    // para busca pelo ID faltante
    //    for(i = 0; i < 30231; ++i)
    //    {
    //        posicao = buscaSequencialId(listaENEM, nEscolas, i);
    //        if(posicao < 0)
    //            printf("\nFaltando o ID: %d\n", i);
    //    }
    //    //****************************

    inicio = clock();
    //=======================================

    for(i = 0; i < 1000; ++i)
    {
        posicao = buscaSequencialId(listaENEM, nEscolas, 40000);
    }

    //=======================================
    fim = clock();
    tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
    printf("Tempo decorrido para busca sequencial: %lu milissegundos\n", tempo);


    inicio = clock();
    //=======================================

    //insertionSortId(listaENEM, nEscolas);
    mergeSortId(listaENEM, 0, nEscolas-1);
    for(i = 0; i < 1000; ++i)
    {
        posicao = buscaBinariaId(listaENEM, nEscolas, 40000);
    }

    //=======================================
    fim = clock();
    tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
    printf("Tempo decorrido para busca binaria: %lu milissegundos\n", tempo);


    nEscolas = inserirEscola(listaENEM, nEscolas, 10077, "MS", "BONITO", "Estadual");
    posicao = buscaSequencialId(listaENEM, nEscolas, 10077);
    imprime(listaENEM, posicao);

    liberaLista(listaENEM);

    return 0;
}
