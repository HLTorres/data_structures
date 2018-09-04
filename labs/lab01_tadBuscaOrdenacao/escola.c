#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "escola.h"

//definicao do tipo de dados
struct escola
{
    int id;
    char estado[5];
    char municipio[30];
    char rede[10];
    float mediaCienciasNaturais;
    float mediaCienciasHumanas;
    float mediaPortugues;
    float mediaMatematica;
    float mediaRedacao;
};
// ==============================================================


// ==============================================================
// Cria uma lista de escolas a partir de um arquivo
// de escolas cadastradas
// Entrada: nome do arquivo, ponteiro para o numero de elementos.
// Saida: ponteiro para a lista criada.
Escola * criaLista_arquivo(char * nomeArquivo, int * nElementos)
{
    FILE * pFile;
    Escola * lista;
    char buffer[255], * info;
    int nLinhas, i = 0;

    pFile = fopen(nomeArquivo, "r"); // abre o arquivo como somente para leitura

    // define a quantidade de linhas que o arquivo tem
    if(pFile == NULL)
        perror ("Erro de abertura do arquivo");
    else{
        for(nLinhas = 0; fgets(buffer, 255, pFile) != NULL; ++nLinhas);
        fclose(pFile);
    }

    pFile = fopen(nomeArquivo, "r"); // abre o arquivo novamente

    // aloca memoria para todas as linhas do arquivo
    lista = (Escola *) malloc(nLinhas*sizeof(Escola));
    * nElementos = nLinhas; // passa para main() quantas linhas o arquivo possui

    if(lista != NULL) // verifica se a memoria foi alocada
    {
        // le cada linha do arquivo e armazena no campo correto
        while(fgets(buffer, 255, pFile) != NULL)
        {
            lista[i].id = atoi(strtok(buffer, ";"));
            info = strtok(NULL, ";");
            strcpy(lista[i].estado, info);
            info = strtok(NULL, ";");
            strcpy(lista[i].municipio, info);
            info = strtok(NULL, ";");
            strcpy(lista[i].rede, info);
            lista[i].mediaCienciasNaturais = atof(strtok(NULL, ";"));
            lista[i].mediaCienciasHumanas = atof(strtok(NULL, ";"));
            lista[i].mediaPortugues = atof(strtok(NULL, ";"));
            lista[i].mediaMatematica = atof(strtok(NULL, ";"));
            lista[i].mediaRedacao = atof(strtok(NULL, ";"));
            ++i;
        }
        fclose (pFile);
    }
    else {
        printf("\nNAO FOI POSSIVEL ALOCAR A MEMORIA\n");
    }

    return lista;
}
// ==============================================================


//==============================================================
// Insere uma escola em um array ordenado
// Entrada: ponteiro para a lista de escolas, quantidade de elementos
//          na lista, dados da nova escola: id, estado, municipio e rede
// Saida: nova quantidade de elementos
int inserirEscola(Escola * lista, int nElementos,
                       int id, char * estado, char * municipio, char * rede)
{
    int j; // indice auxiliar

    // Realoca memoria
    lista = (Escola *) realloc(lista, (nElementos+1)*sizeof(Escola));

    if(lista != NULL)
    {
        for(j = nElementos; (j > 0) && (id < lista[j - 1].id); --j) // analise da parte ja ordenada
            lista[j] = lista[j - 1]; // movimenta o elemento para a direita
        lista[j].id = id;
        strcpy(lista[j].estado, estado);
        strcpy(lista[j].municipio, municipio);
        strcpy(lista[j].rede, rede);
        nElementos += 1; // aumenta o tamanho de escolas
    }
    else {
        printf("\nNAO FOI POSSIVEL REALOCAR A MEMORIA\n");
    }

    return nElementos;
}
// ==============================================================


// ==============================================================
// Libera memoria alocada a lista
// Entrada: ponteiro para a lista de escolas
// Saida: void.
void liberaLista(Escola * lista)
{
    free(lista);
}
// ==============================================================


// ==============================================================
// Busca dentro do vetor de dados por um id especifico
// Entrada: ponteiro para a lista de escolas, numero de elementos
//          da lista, id de busca.
// Saida: posicao da lista na qual o id foi encontrado.
int buscaSequencialId(Escola * lista, int nElementos, int chave)
{
    int i; // indice auxiliar

    for(i = 0; i < nElementos; ++i)
    {
        if(lista[i].id == chave)
            return i; // elemento encontrado
    }

    return -1; // elemento nao encontrado
}
// ==============================================================

// ==============================================================
// Busca dentro de um vetor de dados ordenados por um id especifico
// Entrada: ponteiro para a lista de escolas, numero de elementos
//          da lista, id de busca.
// Saida: posicao da lista na qual o id foi encontrado.
int buscaBinariaId(Escola * lista, int nElementos, int chave)
{
    int inicio, meio, final;

    inicio = 0;
    final = nElementos -1;

    while (inicio <= final) {
        meio = (inicio + final)/2;
        if(chave < lista[meio].id)
            final = meio-1; // busca na metade da esquerda
        else
            if(chave > lista[meio].id)
                inicio = meio+1; // busca na metade da direita
            else
                return meio; // elemento encontrado
    }

    return -1; // elemento nao encontrado
}
// ==============================================================


// =====================================================================
// Ordenacao de uma lista de escolas pelo ID utilizando insertion sort
// Entrada: ponteiro para a lista de escolas, numero de elementos
//          da lista.
// Saida: void.
void insertionSortId(Escola * lista, int nElementos)
{
    Escola aux;
    int i, j; // variaveis auxiliares

    for(i = 1; i < nElementos; ++i)
    {
        aux = lista[i]; // definicao da chave
        for(j = i; (j > 0) && (aux.id < lista[j - 1].id); --j) // analise da parte ja ordenada
            lista[j] = lista[j - 1]; // movimenta o elemento para a direita
        lista[j] = aux; // coloca a chave na posicao certa
    }
}
// =====================================================================



// ==============================================================
// Ordenacao de uma lista de escolas pelo ID utilizando merge sort
// Entrada: ponteiro para a lista de escolas, indice da primeira
//          posicao da lista, indice da ultima posicao da lista
// Saida: void.
void mergeId(Escola * lista, int inicio, int meio, int fim)
{
    Escola * temp;
    int p1, p2, tamanho, i, j, k;
    char fim1 = 0, fim2 = 0;

    tamanho = fim-inicio+1; // tamanho do vetor
    p1 = inicio; // indice do primeiro elemento da parte 1
    p2 = meio+1; // indice do primeiro elemento da parte 2

    // alocacao do vetor temporario
    temp = (Escola *) malloc(tamanho*sizeof(Escola));

    if(temp != NULL)
    {
        for(i = 0; i < tamanho; ++i)
        {
            if(!fim1 && !fim2)
            {
                if(lista[p1].id < lista[p2].id) // combina ordenando
                    temp[i] = lista[p1++];
                else
                    temp[i] = lista[p2++];

                if(p1 > meio) // sinaliza se um dos vetores acabou
                    fim1 = 1;
                if(p2 > fim)
                    fim2 = 1;
            }else{
                if(!fim1) // copia os demais valores restantes
                    temp[i] = lista[p1++];
                else
                    temp[i] = lista[p2++];
            }
        }
        for(j = 0, k = inicio; j < tamanho; ++j, ++k) // copia de temp para o original
            lista[k] = temp[j];
    }
    free(temp); // liberacao da memoria alocada a temp
}

void mergeSortId(Escola * lista, int inicio, int fim)
{
    int meio;

    if(inicio < fim)
    {
        meio = floor((inicio+fim)/2); // arredondado para baixo
        mergeSortId(lista, inicio, meio); // fraciona a parte esquerda do vetor
        mergeSortId(lista, meio+1, fim); // fraciona a parte direita do vetor
        mergeId(lista, inicio, meio, fim); // combina as partes de forma ordenada
    }
}
// ==============================================================


// ==============================================================
// Imprime na saida padrao informacoes de determinada escola
// Entrada: ponteiro para lista de escolas, posicao a imprimir
// Saida: void.
void imprime(Escola * lista, int posicao)
{
    if(posicao < 0)
        printf("ESCOLA NAO ENCONTRADA\n");
    else {
        printf("ID da escola: %d\n", lista[posicao].id);
        printf("UF: ");
        puts(lista[posicao].estado);
        printf("Municipio: ");
        puts(lista[posicao].municipio);
        printf("Rede: ");
        puts(lista[posicao].rede);
        printf("Posicao no array: %d\n", posicao);
        printf("\n");
    }

}
// ==============================================================
