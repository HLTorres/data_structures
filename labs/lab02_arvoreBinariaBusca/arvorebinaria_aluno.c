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

/* Calcula a quantidade de nos com chave impar em uma arvore binaria */
int impar_arvoreBinaria(ArvBin * raiz)
{

 /* Implementar uma funcao que calcule a quantidade de 
  * nos com chave impar em uma arvore binaria.
  */

}

/* Calcula a quantidade de nos folha em uma arvore binaria */
int folha_arvoreBinaria(ArvBin * raiz)
{

 /* Implementar uma funcao que calcule a quantidade de 
  * nos folha em uma arvore binaria.
  */

}

/* Calcula a quantidade de nos nao folha em uma arvore binaria */
int naoFolha_arvoreBinaria(ArvBin * raiz)
{

 /* Implementar uma funcao que calcule a quantidade de 
  * nos nao folha em uma arvore binaria.
  */

}
