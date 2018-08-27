#ifndef SORTING_H
#define SORTING_H

// Exercicio ordenacao de estruturas
struct aluno{
    int matricula;
    char nome[30];
    float p1, p2, p3;
};

void bubbleSort(int *vetor, int nElementos);
void bubbleSort_float(float *vetor, int nElementos);
void selectionSort(int *vetor, int nElementos);
void selectionSort_char(char *vetor, int nElementos);
void insertionSort(int *vetor, int nElementos);
void insertionSort_aluno(struct aluno *vetor, int nElementos);
void mergeSort(int *vetor, int inicio, int fim);

#endif // SORTING_H
