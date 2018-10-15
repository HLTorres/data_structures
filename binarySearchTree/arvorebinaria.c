#include <stdlib.h>
#include <stdio.h>
#include "arvorebinaria.h"

struct noh {
    int info;
    struct noh * esq;
    struct noh * dir;
};

ArvBin * cria_arvoreBinaria()
{
    ArvBin * raiz;
    raiz = (ArvBin *) malloc(sizeof(ArvBin)); // aloca memoria para a TAD
    if(raiz != NULL) // testa se a alocacao deu certo
        * raiz = NULL; // conteudo do ponteiro "raiz" igual a NULL
    return raiz;
}

void libera_noh(struct noh * noh)
{
    if(noh == NULL)
        return;
    libera_noh(noh->esq); // percorre recursivamente os nos da esquerda
    libera_noh(noh->dir); // percorre recursivamente os nos da direita
    free(noh);
    noh = NULL; // para evitar erro de verificacao posterior
}

void libera_arvoreBinaria(ArvBin * raiz)
{
    if(raiz == NULL)
        return;
    libera_noh(* raiz); // percorre a arvore e libera cada no
    free(raiz); // libera a "raiz" (primeiro no alocado na criacao)
}

int estaVazia_arvoreBinaria(ArvBin * raiz)
{
    if(raiz == NULL) // testa se houve problema na criacao da arvore
        return 1;
    if(* raiz == NULL) // testa se ainda nao ha nenhum no na arvore
        return 1;
    return 0; // arvore nao esta vazia
}

int altura_arvoreBinaria(ArvBin * raiz)
{
    if (raiz == NULL) // testa se houve problema na criacao da arvore
        return -1;
    if (* raiz == NULL) // testa se ainda nao ha nenhum no na arvore
        return -1;
    /* Chama recursivamente a funcao "altura"
     * para as sub-arvores da esquerda e da direita */
    int alt_esq = altura_arvoreBinaria(&((* raiz)->esq));
    int alt_dir = altura_arvoreBinaria(&((* raiz)->dir));
    if (alt_esq > alt_dir) // verifica qual das alturas e maior
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}

int totalNoh_arvoreBinaria(ArvBin * raiz)
{
    if (raiz == NULL)
        return 0;
    if (* raiz == NULL)
        return 0;
    int total_esq = totalNoh_arvoreBinaria(&((* raiz)->esq));
    int total_dir = totalNoh_arvoreBinaria(&((* raiz)->dir));
    /* Retorna o numero de nos a esquerda, mais
     * o numero de nos a direita, mais o noh pai */
    return (total_esq + total_dir + 1);
}

void preOrdem_arvoreBinaria(ArvBin * raiz)
{
    if(raiz == NULL)
        return;
    if(* raiz != NULL)
    {
        printf("%d\n",(* raiz)->info);
        preOrdem_arvoreBinaria(&((* raiz)->esq)); // passa o endereco do filho da esquerda
        preOrdem_arvoreBinaria(&((* raiz)->dir)); // passa o endereco do filho da direita
    }
}

void emOrdem_arvoreBinaria(ArvBin * raiz)
{
    if(raiz == NULL)
        return;
    if(* raiz != NULL)
    {
        emOrdem_arvoreBinaria(&((* raiz)->esq));
        printf("%d\n",(* raiz)->info);
        emOrdem_arvoreBinaria(&((* raiz)->dir));
    }
}

void posOrdem_arvoreBinaria(ArvBin * raiz)
{
    if(raiz == NULL)
        return;
    if(* raiz != NULL)
    {
        posOrdem_arvoreBinaria(&((* raiz)->esq));
        posOrdem_arvoreBinaria(&((* raiz)->dir));
        printf("%d\n",(* raiz)->info);
    }
}

int insere_arvoreBinaria(ArvBin * raiz, int valor)
{
    if(raiz == NULL) // testa se a arvore e valida
        return 0;
    struct noh * novo;
    novo = (struct noh *) malloc(sizeof(struct noh)); // aloca um novo no
    if(novo == NULL) // testa se houve erro na alocacao
        return 0;
    novo->info = valor;
    novo->dir = NULL; // pois o elemento e inserido como uma folha
    novo->esq = NULL; // pois o elemento e inserido como uma folha
    /* Procurar onde inserir */
    if(* raiz == NULL)
        * raiz = novo;
    else{
        struct noh * atual = * raiz;
        struct noh * anterior = NULL;
        while(atual != NULL){
            anterior = atual;
            if(valor == atual->info){
                free(novo);
                return 0; // elemento já existe
            }
            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > anterior->info)
            anterior->dir = novo;
        else
            anterior->esq = novo;
    }
    return 1; // insercao feita com sucesso
}

struct noh * removeAtual(struct noh * atual)
{
    struct noh * noh1, * noh2;

    if(atual->esq == NULL){ // Sem filho da esquerda
        /* Apontar para o filho da direita
         * (trata no folha e no com 1 filho) */
        noh2 = atual->dir;
        free(atual);
        return noh2;
    }

    /* Procura filho mais a direita da sub-arvore da esquerda */
    noh1 = atual;
    noh2 = atual->esq;
    while(noh2->dir != NULL){
        noh1 = noh2;
        noh2 = noh2->dir;
    }

    /* Copia o filho mais a direita da sub-arvore da esquerda
     * para o lugar do no a ser removido */
    if(noh1 != atual){
        noh1->dir = noh2->esq;
        noh2->esq = atual->esq;
    }
    noh2->dir = atual->dir;

    free(atual);
    return noh2;
}

int remove_arvoreBinaria(ArvBin * raiz, int valor)
{
    if(raiz == NULL) // verifica se a arvore e valida
        return 0;
    struct noh * anterior = NULL;
    struct noh * atual = * raiz;
    while(atual != NULL){
        /* Achou o no a ser removido. Tratar o lado da remocao */
        if(valor == atual->info){                            /**/
            if(atual == * raiz)                              /**/
                * raiz = removeAtual(atual);                 /**/
            else{                                            /**/
                if(anterior->dir == atual)                   /**/
                    anterior->dir = removeAtual(atual);      /**/
                else                                         /**/
                    anterior->esq = removeAtual(atual);      /**/
            }                                                /**/
            return 1;                                        /**/
        }                                                    /**/
        /*******************************************************/
        /* Continua andando na arvore procurando o no a ser removido */
        anterior = atual;                                          /**/
        if(valor > atual->info)                                    /**/
            atual = atual->dir;                                    /**/
        else                                                       /**/
            atual = atual->esq;                                    /**/
        /*************************************************************/
    }
    return 0;
}

int consulta_arvoreBinaria(ArvBin * raiz, int valor)
{
    if(raiz == NULL)
        return 0;
    struct noh * atual = * raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1; // valor encontrado
        }
        if(valor > atual->info)
            atual = atual->dir; // caminha a direita
        else
            atual = atual->esq; // caminha a esquerda
    }
    return 0; // valor nao encontrado
}

// Arvore binaria de busca usando funcoes recursivas
// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
