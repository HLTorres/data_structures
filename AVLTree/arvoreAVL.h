#ifndef ARVOREAVL_H
#define ARVOREAVL_H

typedef struct noh * ArvAVL;

/* Funcoes identicas as da arvore binaria */
ArvAVL * cria_arvAVL();
void libera_arvAVL(ArvAVL * raiz);
int estaVazia_arvAVL(ArvAVL * raiz);
int altura_arvAVL(ArvAVL * raiz);
int totalNoh_arvAVL(ArvAVL * raiz);
void preOrdem_arvAVL(ArvAVL * raiz);
void emOrdem_arvAVL(ArvAVL * raiz);
void posOrdem_arvAVL(ArvAVL * raiz);
int consulta_arvAVL(ArvAVL * raiz, int valor);

/* Funcoes exclusivas da arvore AVL */
int insere_arvAVL(ArvAVL * raiz, int valor);
int remove_arvAVL(ArvAVL * raiz, int valor);


#endif // ARVOREAVL_H
