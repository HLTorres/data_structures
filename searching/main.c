#include <stdio.h>
#include "busca.h"

int main()
{
    int vetor[15] = {-8,-5,1,4,14,21,23,54,67,90,101,103,184,300,447};
    int auxChave[3] = {4,67,184}; // chaves conhecidas dentro do vetor de busca
    int auxPosicao[3] = {3,8,12}; // posicoes das chaves conhecidas no vetor de busca

    struct aluno cadastro[4] = {{2, "Henrique", 9.5, 7.8, 8.5},
                                {4, "Ricardo", 7.5, 8.7, 6.8},
                                {1, "Bianca", 9.7, 6.7, 8.4},
                                {3, "Ana", 5.7, 6.1, 7.4}};


    if(buscaSequencial(vetor, 15, 67) != -1)
        printf("Busca Sequencial: Elemento encontrado!\n\n");
    else
        printf("Busca Sequencial: ERRO! Elemento NAO encontrado\n\n");


    if(buscaSequencialIndexada(auxChave, auxPosicao, 3, vetor,  15, -5) != -1)
        printf("Busca Sequencial Indexada: Elemento encontrado!\n\n");
    else
        printf("Busca Sequencial Indexada: ERRO! Elemento NAO encontrado\n\n");


    if(buscaBinaria(vetor, 15, 55) != -1)
        printf("Busca Binaria: Elemento encontrado!\n\n");
    else
        printf("Busca Binaria: ERRO! Elemento NAO encontrado\n\n");


    if(buscaSequencialNome(cadastro, 4, "Henrique") != -1)
        printf("Busca em estrutura: Nome encontrado!\n\n");
    else
        printf("Busca em estrutura: ERRO! Nome NAO encontrado\n\n");


    return 0;
}
