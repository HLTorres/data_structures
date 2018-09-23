#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "filaprioridade.h"

/* para compilacao condicional */
#define ARRAY_ORDENADO 0
#define HEAP_BINARIA 1
/* seleciona se a fila de prioridades sera implementada como
   array ordenado ou heap binaria */
#define IMPLEMENTACAO ARRAY_ORDENADO


/* define o tipo de dados filaPrioridade
   mesma estrutura de uma lista sequencial estatica */
struct filaPrioridade {
    int qtd;
    struct paciente dados[MAX];
};

// ===========================================================

/**
 * @brief cria_FilaPrio cria fila de prioridades baseada em uma lista estatica
 * @return ponteiro para fila de prioridades
 */
FilaPrio * cria_FilaPrio()
{
    FilaPrio * fp;
    fp = (FilaPrio *) malloc(sizeof(FilaPrio));
    if(fp != NULL)
        fp->qtd = 0;
    return fp;
}
// ===========================================================

// ===========================================================
/**
 * @brief libera_FilaPrio libera fila de prioridades
 * @param fp ponteiro para fila a ser liberada
 */
void libera_FilaPrio(FilaPrio * fp)
{
    free(fp);
}
// ===========================================================

// ===========================================================
/**
 * @brief tamanho_FilaPrio informa quantos elementos da fila foram preenchidos
 * @param fp ponteiro para fila de prioridades
 * @return quantidade de elementos existentes na lista / proxima posicao vaga
 */
int tamanho_FilaPrio(FilaPrio * fp)
{
    if(fp == NULL) // verifica se a lista e valida
        return -1;
    else
        return fp->qtd;
}
// ===========================================================

// ===========================================================
/**
 * @brief estaCheia_FilaPrio informa se a fila esta cheia
 * @param fp ponteiro para fila de prioridades
 * @return 1: fila cheia; 0: fila nao cheia
 */
int estaCheia_FilaPrio(FilaPrio * fp)
{
    if(fp == NULL)
        return -1;
    return (fp->qtd == MAX);
}
// ===========================================================

// ===========================================================
/**
 * @brief estaVazia_FilaPrio informa se a fila esta vazia
 * @param fp ponteiro para fila de prioridades
 * @return 1: fila vazia; 0: fila nao vazia
 */
int estaVazia_FilaPrio(FilaPrio * fp)
{
    if(fp == NULL)
        return -1;
    return (fp->qtd == 0);
}
// ===========================================================

// ===========================================================
#if IMPLEMENTACAO == HEAP_BINARIA
/**
 * @brief promoverElemento move o elemento para a posicao correta na fila de prioridade
 * @param fp ponteiro para fila de prioridades
 * @param filho posicao incial do elemento na fila
 */
void promoverElemento(FilaPrio * fp, int filho)
{
    int pai;
    struct paciente temp;
    pai = (filho - 1) / 2; // calcula a posicao do pai no array
    while((filho > 0) && (fp->dados[pai].prio <= fp->dados[filho].prio))
    {
        /* troca pai e filho de posicao */
        temp = fp->dados[filho];
        fp->dados[filho] = fp->dados[pai];
        fp->dados[pai] = temp;

        /* recalcula pai e filho */
        filho = pai;
        pai = (pai - 1) / 2;
    }
}
#endif
// ===========================================================

// ===========================================================
/**
 * @brief insere_FilaPrio insere um elemento na fila de prioridade
 * @param fp ponteiro para a fila a ser manipulada
 * @param nome nome do paciente a ser inserido
 * @param prioridade prioridade do paciente
 * @return 0: para falha na insercao; 1: para insercao bem sucedida
 */
int insere_FilaPrio(FilaPrio * fp, char * nome, int  prioridade)
{
#if IMPLEMENTACAO == ARRAY_ORDENADO // implementa fila de prioridade como array ordenado

    if(fp == NULL)
        return 0;
    if(fp->qtd == MAX) // fila cheia
        return 0;

    int i = fp->qtd - 1; // elemento de maior prioridade no final do array,
                         // logo verifica do fim para o inicio
    while(i >= 0 && fp->dados[i].prio >= prioridade)
    {
        fp->dados[i+1] = fp->dados[i]; // desloca o elemento mais prioritario para frente
        --i;
    }

    strcpy(fp->dados[i+1].nome, nome); // copia nome do paciente para o campo nome
    fp->dados[i+1].prio = prioridade; // define a prioridade desse paciente
    fp->qtd++; // atualiza a quantidade elementos na fila
    return 1;

#elif IMPLEMENTACAO == HEAP_BINARIA // implementa fila de prioridade como heap binaria

    if(fp == NULL)
        return 0;
    if(fp->qtd == MAX) // fila cheia
        return 0;
    /* insere na primeira posição livre (ultima posicao do array) */
    strcpy(fp->dados[fp->qtd].nome, nome);
    fp->dados[fp->qtd].prio = prioridade;
    /* desloca elemento para posição correta */
    promoverElemento(fp, fp->qtd);
    /* incrementa número de elementos no heap */
    fp->qtd++;
    return 1;

#endif
}
// ===========================================================

// ===========================================================

#if IMPLEMENTACAO == HEAP_BINARIA
/**
 * @brief rebaixarElemento reajusta a heap apos a remocao do elemento de maior prioridade
 * @param fp ponteiro para fila de prioridades
 * @param pai posicao inicial o pai na fila
 */
void rebaixarElemento(FilaPrio * fp, int pai)
{
    struct paciente temp;
    int filho = 2 * pai + 1;

    while(filho < fp->qtd)
    {
        if(filho < fp->qtd-1) // verifica se tem 2 filhos
            if(fp->dados[filho].prio < fp->dados[filho+1].prio)
                filho++; // filho aponta para filho maior

        if(fp->dados[pai].prio >= fp->dados[filho].prio)
            break; // encontrou lugar: termina o processo

        /* troca pai e filho de lugar */
        temp = fp->dados[pai];
        fp->dados[pai] = fp->dados[filho];
        fp->dados[filho] = temp;

        /* recalcula pai e filho */
        pai = filho;
        filho = 2 * pai + 1;
    }
}
#endif

// ===========================================================

// ===========================================================
/**
 * @brief remove_FilaPrio remove o primeiro elemento da fila
 * @param fp ponteiro para a fila a ser manipulada
 * @return 0: para falha na remocao; 1: para remocao bem sucedida
 */
int remove_FilaPrio(FilaPrio * fp)
{
#if IMPLEMENTACAO == ARRAY_ORDENADO // implementa fila de prioridade como array ordenado

    if(fp == NULL)
        return 0;
    if(fp->qtd == 0) // fila vazia
        return 0;
    fp->qtd--; // remove ultimo elemento da lista
    return 1;

#elif IMPLEMENTACAO == HEAP_BINARIA // implementa fila de prioridade como heap binaria

    if(fp == NULL)
        return 0;
    if(fp->qtd == 0)
        return 0;

    fp->qtd--;
    fp->dados[0] = fp->dados[fp->qtd];
    rebaixarElemento(fp, 0);
    return 1;

#endif
}
// ===========================================================

// ===========================================================
/**
 * @brief consulta_FilaPrio recupera o nome do primeiro elemento da fila
 * @param fp ponteiro para a fila a ser consultada
 * @param nome ponteiro para onde sera copiada a string do primeiro nome da fila
 * @return 0: para falha na consulta; 1: para consulta bem sucedida
 */
int consulta_FilaPrio(FilaPrio * fp, char * nome)
{
#if IMPLEMENTACAO == ARRAY_ORDENADO // implementa fila de prioridade como array ordenado

    if(fp == NULL || fp->qtd == 0)
        return 0;
    strcpy(nome, fp->dados[fp->qtd-1].nome); // primeiro da fila e o ultimo da lista
    return 1;

#elif IMPLEMENTACAO == HEAP_BINARIA // implementa fila de prioridade como heap binaria

    if(fp == NULL || fp->qtd == 0)
        return 0;
    strcpy(nome, fp->dados[0].nome); // primeiro da fila e o primeiro da heap
    return 1;

#endif
}
// ===========================================================
/**
 * @brief imprime_FilaPrio imprime o conteudo da fila
 * @param fp ponteiro para a fila a ser impressa
 */
void imprime_FilaPrio(FilaPrio * fp)
{
#if IMPLEMENTACAO == ARRAY_ORDENADO

    if(fp == NULL)
        return;
    int i;
    for(i = fp->qtd-1; i >= 0; --i)
    {
        printf("Prioridade: %d \tNome: %s\n",fp->dados[i].prio,fp->dados[i].nome);
    }

#elif IMPLEMENTACAO == HEAP_BINARIA

    if(fp == NULL)
        return;
    int i;
    for(i = 0; i < fp->qtd; ++i)
    {
        printf("%d) Prioridade: %d \tNome: %s\n", i, fp->dados[i].prio, fp->dados[i].nome);
    }

#endif
}
