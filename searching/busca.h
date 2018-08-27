#ifndef BUSCA_H
#define BUSCA_H

int buscaSequencial(int *vetor, int nElementos, int chave);
int buscaSequencialSentinela(int *vetor, int nElementos, int chave);
int buscaSequencialOrdenada(int *vetor, int nElementos, int chave);
int buscaSequencialIndexada(int *auxChave, int *auxPosicao, int auxTamanho, int *vetor,  int nElementos,  int chave);
int buscaBinaria(int *vetor, int nElementos, int chave);

// exemplo de busca em vetor de estruturas
struct aluno{
    int matricula;
    char nome[30];
    float p1, p2, p3;
};
int buscaSequencialMatricula(struct aluno *vetor, int nElementos, int chave);
int buscaSequencialNome(struct aluno *vetor, int nElementos, char *chave);



#endif // BUSCA_H
