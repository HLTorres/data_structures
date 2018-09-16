#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

int main()
{
    int i, nElementos, nElementos2;
    int vetor[] = {23,4,67,-8,90,54,21};
    float vetor2[] = {45,-7,3.4,-7.7,84,0,30};
    int tamanho;
    char nome[] = "daniel";

    struct aluno cadastro[4] = {{2, "Hugo", 9.5, 7.8, 8.5},
    {4, "Ricardo", 7.5, 8.7, 6.8},
    {1, "Bianca", 9.7, 6.7, 8.4},
    {3, "Ana", 5.7, 6.1, 7.4}};

    // calculando o numero de elementos do vetor de inteiros
    nElementos = sizeof(vetor)/sizeof(int);
    // calculando o numero de elementos do vetor de float
    nElementos2 = sizeof(vetor2)/sizeof(float);
    // calculando o numero de elemtos no vetor de caracteres
    tamanho = sizeof(nome) - 1;

    printf("Vetor de inteiros ANTES da ordenacao\n");
    for(i = 0; i < nElementos; ++i)
        printf("%d  ", vetor[i]);

    //    //============================================
    //    printf("\n\nVetor APOS o Bubble Sort\n");
    //    bubbleSort(vetor, nElementos);
    //    for(i = 0; i < nElementos; ++i)
    //        printf("%d  ", vetor[i]);
    //    //============================================

    //    //============================================
    //    printf("\n\nVetor APOS o Selection Sort\n");
    //    selectionSort(vetor, nElementos);
    //    for(i = 0; i < nElementos; ++i)
    //        printf("%d  ", vetor[i]);
    //    //============================================

    //    //============================================
    //    printf("\n\nVetor APOS o Insertion Sort\n");
    //    insertionSort(vetor, nElementos);
    //    for(i = 0; i < nElementos; ++i)
    //        printf("%d  ", vetor[i]);
    //    //============================================

    //    //============================================
    //    printf("\n\nVetor APOS o Merge Sort\n");
    //    mergeSort(vetor, 0, nElementos-1);
    //    for(i = 0; i < nElementos; ++i)
    //        printf("%d  ", vetor[i]);
    //    //============================================

//    //============================================
//    printf("\n\nVetor APOS o Quick Sort\n");
//    quickSort(vetor, 0, nElementos-1);
//    for(i = 0; i < nElementos; ++i)
//        printf("%d  ", vetor[i]);
//    //============================================

    //============================================
    printf("\n\nVetor APOS o Heap Sort\n");
    heapSort(vetor, nElementos);
    for(i = 0; i < nElementos; ++i)
        printf("%d  ", vetor[i]);
    //============================================

    //============================================
    printf("\n\nVetor de float APOS o Bubble Sort\n");
    bubbleSort_float(vetor2, nElementos);
    for(i = 0; i < nElementos2; ++i)
        printf("%.1f  ", vetor2[i]);
    //============================================

    //============================================
    //ordena strings em um vetor
    printf("\n\nVetor de char com Selection Sort\n");
    selectionSort_char(nome, tamanho);
    for(i = 0; nome[i] != 0; ++i)
        printf("%c  ", nome[i]);
    //============================================

    //============================================
    //ordena structs em um vetor
    printf("\n\nCadastro de alunos com Insertion Sort\n");
    insertionSort_aluno(cadastro, 4);
    for(i = 0; i < 4; ++i)
        printf("%d) %s\n", cadastro[i].matricula, cadastro[i].nome);
    //============================================

    printf("\n\n");
    return 0;
}
