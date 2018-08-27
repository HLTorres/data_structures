#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "sorting.h"

// =====================================================================
// ordenacao de um vetor de inteiros por bolha
void bubbleSort(int *vetor, int nElementos)
{
    int i, aux, fim = nElementos; // variaveis auxiliares
    char continua; // sinaliza uma troca efetuada

    do{
        continua = 0;
        for(i = 0; i < fim-1; ++i) // compara 2 a 2 os elementos do vetor
        {
            if(vetor[i] > vetor[i+1]) // carrega o maior elemento para o final
            {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                continua = 1; // continua a busca (houve uma troca)
            }
        }
        --fim; // vetor reduzido pois o maior elemento ja esta no final
    }while(continua != 0); // executa enquanto trocas forem feitas
}
// =====================================================================

// =====================================================================
// ordenacao de um vetor de float em ordem decrescente por bolha
void bubbleSort_float(float *vetor, int nElementos)
{
    int i, fim = nElementos; // variaveis auxiliares
    float aux;
    char continua; // sinaliza uma troca efetuada

    do{
        continua = 0;
        for(i = 0; i < fim-1; ++i) // compara 2 a 2 os elementos do vetor
        {
            if(vetor[i] < vetor[i+1]) // carrega o menor elemento para o final
            {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                continua = 1; // continua a busca (houve uma troca)
            }
        }
        --fim; // vetor reduzido pois o maior elemento ja esta no final
    }while(continua != 0); // executa enquanto trocas forem feitas
}
// =====================================================================

// =====================================================================
// ordenacao de um vetor de inteiros por selecao
void selectionSort(int *vetor, int nElementos)
{
    int i, j, aux, menor; // variaveis auxiliares

    for(i = 0; i < nElementos-1; ++i)
    {
        menor = i; // considera inicialmente que o menor valor esteja em i
        for(j = i+1; j < nElementos; ++j) // procura na parte nao ordenada
        {
            if(vetor[j] < vetor[menor])
                menor = j; // atualiza o indice que contem o menor valor
        }
        if(i != menor) // troca os valores entre as posicoes atual e menor
        {
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
}
// =====================================================================

// =====================================================================
// ordenacao de um vetor de caracteres por selecao
void selectionSort_char(char *vetor, int nElementos)
{
    int i, j, menor; // variaveis auxiliares
    char aux;

    for(i = 0; i < nElementos-1; ++i)
    {
        menor = i; // considera inicialmente que o menor valor esteja em i
        for(j = i+1; j < nElementos; ++j) // procura na parte nao ordenada
        {
            if(vetor[j] < vetor[menor])
                menor = j; // atualiza o indice que contem o menor valor
        }
        if(i != menor) // troca os valores entre as posicoes atual e menor
        {
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
}
// =====================================================================

// =====================================================================
// ordenacao de um vetor de inteiros por insercao
void insertionSort(int *vetor, int nElementos)
{
    int i, j, aux; // variaveis auxiliares

    for(i = 1; i < nElementos; ++i)
    {
        aux = vetor[i]; // definicao da chave
        for(j = i; (j > 0) && (aux < vetor[j - 1]); --j) // analise da parte ja ordenada
            vetor[j] = vetor[j - 1]; // movimenta o elemento para a direita
        vetor[j] = aux; // coloca a chave na posicao certa
    }
}
// =====================================================================

// =====================================================================
// ordenacao de um vetor de struct por insercao
void insertionSort_aluno(struct aluno *vetor, int nElementos)
{
    int i, j; // variaveis auxiliares
    struct aluno aux;

    for(i = 1; i < nElementos; ++i)
    {
        aux = vetor[i]; // definicao da chave
        for(j = i; (j > 0) && (strcmp(aux.nome,vetor[j-1].nome) < 0); --j)
            vetor[j] = vetor[j - 1]; // movimenta o elemento para a direita
        vetor[j] = aux; // coloca a chave na posicao certa
    }

    /*saída strcmp(str1,str2)
        == 0: str1 é igual a str2
         > 0: str1 vem depois de str2
         < 0: str1 vem antes de str2
    */
}
// =====================================================================

// =====================================================================
// ordenacao de um vetor de inteiros por intercalacao
void merge(int *vetor, int inicio, int meio, int fim)
{
    int *temp, p1, p2, tamanho, i, j, k;
    char fim1 = 0, fim2 = 0;

    tamanho = fim-inicio+1; // tamanho do vetor
    p1 = inicio; // indice do primeiro elemento da parte 1
    p2 = meio+1; // indice do primeiro elemento da parte 2

    // alocacao do vetor temporario
    temp = (int *) malloc(tamanho*sizeof(int));

    if(temp != NULL)
    {
        for(i = 0; i < tamanho; ++i)
        {
            if(!fim1 && !fim2)
            {
                if(vetor[p1] < vetor[p2]) // combina ordenando
                    temp[i] = vetor[p1++];
                else
                    temp[i] = vetor[p2++];

                if(p1 > meio) // sinaliza se um dos vetores acabou
                    fim1 = 1;
                if(p2 > fim)
                    fim2 = 1;
            }else{
                if(!fim1) // copia os demais valores restantes
                    temp[i] = vetor[p1++];
                else
                    temp[i] = vetor[p2++];
            }
        }
        for(j = 0, k = inicio; j < tamanho; ++j, ++k) // copia de temp para o original
            vetor[k] = temp[j];
    }
    free(temp); // liberacao da memoria alocada a temp
}

void mergeSort(int *vetor, int inicio, int fim)
{
    int meio;

    if(inicio < fim)
    {
        meio = floor((inicio+fim)/2); // arredondado para baixo
        mergeSort(vetor, inicio, meio); // fraciona a parte esquerda do vetor
        mergeSort(vetor, meio+1, fim); // fraciona a parte direita do vetor
        merge(vetor, inicio, meio, fim); // combina as partes de forma ordenada
    }
}
// =====================================================================
