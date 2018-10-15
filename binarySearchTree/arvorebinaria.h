#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

typedef struct noh * ArvBin;

ArvBin * cria_arvoreBinaria();
void libera_arvoreBinaria(ArvBin * raiz);
int estaVazia_arvoreBinaria(ArvBin * raiz);
int altura_arvoreBinaria(ArvBin * raiz);
int totalNoh_arvoreBinaria(ArvBin * raiz);
void preOrdem_arvoreBinaria(ArvBin * raiz);
void emOrdem_arvoreBinaria(ArvBin * raiz);
void posOrdem_arvoreBinaria(ArvBin * raiz);

int insere_arvoreBinaria(ArvBin * raiz, int valor);
int remove_arvoreBinaria(ArvBin * raiz, int valor);
int consulta_arvoreBinaria(ArvBin * raiz, int valor);

#endif // ARVOREBINARIA_H
