#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"

struct noh {
    int info;
    int altura; // altura da sub-arvore
    struct noh * esq;
    struct noh * dir;
};

/* ======================== Funcoes auxiliares ========================= */

/* Calcula a altura do no */
int alturaNoh(struct noh * noh)
{
    if(noh == NULL)
        return -1; // -1, caso o no nao exista
    else
        return noh->altura;
}

/* Calcula o modulo do fator de balanceamento de um no */
int fatorBalanceamentoNoh(struct noh * noh)
{
    return labs(alturaNoh(noh->esq) - alturaNoh(noh->dir));
}

/* Calcula o maior valor */
int maior(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

/* ===================================================================== */

/* =============== Funcoes identicas a da arvore binaria =============== */

ArvAVL * cria_arvAVL()
{
    ArvAVL * raiz = (ArvAVL *) malloc(sizeof(ArvAVL));
    if(raiz != NULL)
        *raiz = NULL;
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

void libera_arvAVL(ArvAVL * raiz)
{
    if(raiz == NULL)
        return;
    libera_noh(*raiz); // percorre a arvore e libera cada no
    free(raiz); // libera a "raiz" (primeiro ponteiro alocado na criacao)
}


int estaVazia_arvAVL(ArvAVL * raiz)
{
    if(raiz == NULL) // testa se houve problema na criacao da arvore
        return 1;
    if(*raiz == NULL) // testa se ainda nao ha nenhum no na arvore
        return 1;
    return 0; // arvore nao esta vazia
}

int altura_arvAVL(ArvAVL * raiz)
{
    if(raiz == NULL) // testa se houve problema na criacao da arvore
        return -1;
    if(*raiz == NULL) // testa se ainda nao ha nenhum no na arvore
        return -1;
    /* Chama recursivamente a funcao "altura"
     * para as sub-arvores da esquerda e da direita */
    int alt_esq = altura_arvAVL(&((*raiz)->esq));
    int alt_dir = altura_arvAVL(&((*raiz)->dir));
    if (alt_esq > alt_dir) // verifica qual das alturas e maior
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}

int totalNoh_arvAVL(ArvAVL * raiz)
{
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int total_esq = totalNoh_arvAVL(&((*raiz)->esq));
    int total_dir = totalNoh_arvAVL(&((*raiz)->dir));
    /* Retorna o numero de nos a esquerda, mais
     * o numero de nos a direita, mais o noh pai */
    return (total_esq + total_dir + 1);
}

void preOrdem_arvAVL(ArvAVL * raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {
        //printf("%d\n",(*raiz)->info);
        //printf("No %d: %d\n",(*raiz)->info,fatorBalanceamento_NO(*raiz));
        printf("No %d: %d\n",(*raiz)->info, alturaNoh(*raiz));
        preOrdem_arvAVL(&((*raiz)->esq)); // passa o endereco do filho da esquerda
        preOrdem_arvAVL(&((*raiz)->dir)); // passa o endereco do filho da direita
    }
}

void emOrdem_arvAVL(ArvAVL * raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {
        emOrdem_arvAVL(&((*raiz)->esq));
        //printf("%d\n",(*raiz)->info);
        printf("No %d: H(%d) fb(%d)\n",(*raiz)->info, alturaNoh(*raiz), fatorBalanceamentoNoh(*raiz));
        emOrdem_arvAVL(&((*raiz)->dir));
    }
}

void posOrdem_arvAVL(ArvAVL * raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {
        posOrdem_arvAVL(&((*raiz)->esq));
        posOrdem_arvAVL(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);
    }
}

int consulta_arvAVL(ArvAVL * raiz, int valor)
{
    if(raiz == NULL)
        return 0;
    struct noh * atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info) {
            return 1; // valor encontrado
        }
        if(valor > atual->info)
            atual = atual->dir; // caminha a direita
        else
            atual = atual->esq; // caminha a esquerda
    }
    return 0; // valor nao encontrado
}

/* ===================================================================== */


/* ======================== Funcoes de rotacao ========================= */

/* Rotacao simples a direita */
void rotacaoLL(ArvAVL * raiz)
{
    printf("RotacaoLL\n");
    struct noh * no; // criacao de um no auxiliar
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->altura = maior(alturaNoh((*raiz)->esq),
                            alturaNoh((*raiz)->dir)) + 1;
    no->altura = maior(alturaNoh(no->esq),
                       (*raiz)->altura) + 1;
    *raiz = no;
}

/* Rotacao simples a esquerda */
void rotacaoRR(ArvAVL * raiz)
{
    printf("RotacaoRR\n");
    struct noh * no; // criacao de um no auxiliar
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = *raiz;
    (*raiz)->altura = maior(alturaNoh((*raiz)->esq),
                            alturaNoh((*raiz)->dir)) + 1;
    no->altura = maior(alturaNoh(no->dir),
                       (*raiz)->altura) + 1;
    *raiz = no;
}

/* Rotacao dupla a direita */
void rotacaoLR(ArvAVL * raiz)
{
    rotacaoRR(&(*raiz)->esq);
    rotacaoLL(raiz);
}

/* Rotacao dupla a esquerda */
void rotacaoRL(ArvAVL * raiz)
{
    rotacaoLL(&(*raiz)->dir);
    rotacaoRR(raiz);
}

/* ===================================================================== */


/* ======================== Insercao e remocao ========================= */

int insere_arvAVL(ArvAVL * raiz, int valor)
{
    int res; // resposta da insercao ao longo das chamadas da funcao

    /* Arvore vazia ou no folha */
    if(*raiz == NULL) {
        struct noh * novo;
        novo = (struct noh *)malloc(sizeof(struct noh));
        if(novo == NULL) // verifica se a alocacao falhou
            return 0;

        novo->info = valor;
        novo->altura = 0; // no folha ou, no caso de arvore vazia, no raiz
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }

    struct noh * atual = *raiz;
    if(valor < atual->info) { // valor menor que A
        if((res = insere_arvAVL(&(atual->esq), valor)) == 1) {
            /* para insercao feita com sucesso */
            if(fatorBalanceamentoNoh(atual) >= 2) {
                if(valor < (*raiz)->esq->info ) { // valor menor que B
                    rotacaoLL(raiz);
                } else { // valor maior que B
                    rotacaoLR(raiz);
                }
            }
        }
    } else {
        if(valor > atual->info ) { // valor maior que A
            if((res = insere_arvAVL(&(atual->dir), valor)) == 1) {
                /* para insercao feita com sucesso */
                if(fatorBalanceamentoNoh(atual) >= 2) {
                    if((*raiz)->dir->info < valor) { // valor maior que B
                        rotacaoRR(raiz);
                    } else { // valor menor que B
                        rotacaoRL(raiz);
                    }
                }
            }
        } else {
            printf("Valor duplicado!!\n");
            return 0; // valor duplicada nao sera inserido
        }
    }

    atual->altura = maior(alturaNoh(atual->esq), alturaNoh(atual->dir)) + 1;

    return res;
}


struct noh * procuraMenor(struct noh * atual)
{
    /* Procura pelo no mais a esquerda */
    struct noh * no1 = atual;
    struct noh * no2 = atual->esq;
    while(no2 != NULL) {
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

int remove_arvAVL(ArvAVL * raiz, int valor)
{
    /* Valor nao existe */
    if(*raiz == NULL) {
        printf("valor não existe!!\n");
        return 0;
    }

    int res; // resposta da remocao ao longo das chamadas da funcao

    /* Procura na sub-arvore esquerda */
    if(valor < (*raiz)->info) {
        if((res = remove_arvAVL(&(*raiz)->esq, valor)) == 1) {
            /* Remocao na sub-arvore esquerda */
            if(fatorBalanceamentoNoh(*raiz) >= 2) {
                /* Rebalanceamento da sub-arvore direita */
                if(alturaNoh((*raiz)->dir->esq) <= alturaNoh((*raiz)->dir->dir))
                    rotacaoRR(raiz);
                else
                    rotacaoRL(raiz);
            }
        }
    }

    /* Procura na sub-arvore direita */
    if((*raiz)->info < valor) {
        if((res = remove_arvAVL(&(*raiz)->dir, valor)) == 1) {
            /* Remocao na sub-arvore direita */
            if(fatorBalanceamentoNoh(*raiz) >= 2) {
                /* Rebalanceamento da sub-arvore esquerda */
                if(alturaNoh((*raiz)->esq->dir) <= alturaNoh((*raiz)->esq->esq))
                    rotacaoLL(raiz);
                else
                    rotacaoLR(raiz);
            }
        }
    }

    /* Caso o valor seja encontrado, trata a remocao */
    if((*raiz)->info == valor) {
        if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)) {

            /* Pai tem 1 filho ou nenhum */
            struct noh * oldNode = (*raiz);
            if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
            free(oldNode);

        } else {

            /* Pai tem 2 filhos
             * Substituir pelo no mais a esquerda da
             * sub-arvore da direita */
            struct noh * temp = procuraMenor((*raiz)->dir);
            (*raiz)->info = temp->info;
            remove_arvAVL(&(*raiz)->dir, (*raiz)->info);
            if(fatorBalanceamentoNoh(*raiz) >= 2) {
                if(alturaNoh((*raiz)->esq->dir) <= alturaNoh((*raiz)->esq->esq))
                    rotacaoLL(raiz);
                else
                    rotacaoLR(raiz);
            }

        }
        /* Corrige a altura */
        if (*raiz != NULL)
            (*raiz)->altura = maior(alturaNoh((*raiz)->esq),
                                    alturaNoh((*raiz)->dir)) + 1;
        return 1;
    }
    (*raiz)->altura = maior(alturaNoh((*raiz)->esq),
                            alturaNoh((*raiz)->dir)) + 1;

    return res;
}

/* ===================================================================== */
