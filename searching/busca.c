#include <string.h>
#include "busca.h"


// busca em dados desordenados (busca linear)
int buscaSequencial(int *vetor, int nElementos, int chave)
{
    int i; // indice auxiliar

    for(i = 0; i < nElementos; ++i)
    {
        if(vetor[i] == chave)
            return i; // elemento encontrado
    }

    return -1; // elemento nao encontrado
}

// busca em dados desordenados
// mais eficiente que a busca sequencial
int buscaSequencialSentinela(int *vetor, int nElementos, int chave)
{
    vetor[nElementos] = chave;
    int i; // indice auxiliar

    for(i = 0; vetor[i] != chave; ++i);

    if(i < nElementos)
        return i; // elemento encontrado
    else
        return -1; // elemento nao encontrado
}

// busca em dados ordenados
int buscaSequencialOrdenada(int *vetor, int nElementos, int chave)
{
    int i; // indice auxiliar

    for(i = 0; i < nElementos; ++i)
    {
        if(chave == vetor[i])
            return i; // elemento encontrado
        else
            if(chave < vetor[i])
                return -1; // para a busca
    }

    return -1; // elemento nao encontrado
}

// busca em dados ordenados
// necessaria tabela de indices auxiliar contendo chaves e posicoes conhecidas
int buscaSequencialIndexada(int *auxChave, int *auxPosicao, int auxTamanho,
                            int *vetor, int nElementos, int chave)
{
    int i, j; // indices auxiliares
    int limiteInferior, limiteSuperior; // limites da busca dentro do vetor

    // busca dentro da tabela de indices
    for(i = 0; i < auxTamanho && auxChave[i] <= chave; ++i);

    limiteInferior = (i == 0)? 0 : auxPosicao[i-1];
    limiteSuperior = (i == auxTamanho)? nElementos-1 : auxPosicao[i]-1;

    // busca dentro de uma parte do vetor
    for(j = limiteInferior; j <= limiteSuperior && vetor[j] != chave; ++j);

    return ((j > limiteSuperior)? -1 : j);

}

// busca em dados ordenados
// e a busca mais eficiente em dados ordenados
int buscaBinaria(int *vetor, int nElementos, int chave)
{
    int inicio, meio, final;

    inicio = 0;
    final = nElementos -1;

    while (inicio <= final) {
        meio = (inicio + final)/2;
        if(chave < vetor[meio])
            final = meio-1; // busca na metade da esquerda
        else
            if(chave > vetor[meio])
                inicio = meio+1; // busca na metade da direita
            else
                return meio; // elemento encontrado
    }

    return -1; // elemento nao encontrado
}

int buscaSequencialMatricula(struct aluno *vetor, int nElementos, int chave)
{
    int i; // indice auxiliar

    for(i = 0; i < nElementos; ++i)
    {
        if(vetor[i].matricula == chave)
            return i; // elemento encontrado
    }

    return -1; // elemento nao encontrado
}

int buscaSequencialNome(struct aluno *vetor, int nElementos, char *chave)
{
    int i; // indice auxiliar

    for(i = 0; i < nElementos; ++i)
    {
        if(strcmp(chave,vetor[i].nome) == 0)
            return i; // elemento encontrado
    }

    return -1; // elemento nao encontrado
}

