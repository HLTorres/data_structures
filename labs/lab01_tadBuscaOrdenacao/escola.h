#ifndef ESCOLA_H
#define ESCOLA_H

//Apelido
typedef struct escola Escola;

Escola * criaLista_arquivo(char * nomeArquivo, int * nElementos);
int buscaSequencialId(Escola * lista, int nElementos, int chave);
int buscaBinariaId(Escola * lista, int nElementos, int chave);
void insertionSortId(Escola * lista, int nElementos);
void mergeSortId(Escola * lista, int inicio, int fim);
void imprime(Escola * lista, int posicao);
int inserirEscola(Escola * lista, int nElementos,
                   int id, char * estado, char * municipio, char * rede);
void liberaLista(Escola * lista);


#endif // ESCOLA_H
