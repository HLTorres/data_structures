#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

typedef struct noh * ArvBin;

ArvBin * cria_arvoreBinaria();
void libera_arvoreBinaria(ArvBin * raiz);
int insere_arvoreBinaria(ArvBin * raiz, int valor);
int impar_arvoreBinaria(ArvBin * raiz);
int folha_arvoreBinaria(ArvBin * raiz);
int naoFolha_arvoreBinaria(ArvBin * raiz);

#endif // ARVOREBINARIA_H
