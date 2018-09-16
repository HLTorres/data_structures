#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    int matricula;
    char nome[30];
    float p1, p2, p3;
};

int comparaCrescente(const void * a, const void * b)
{
    //(_) acessa o conteudo apontado pelo ponteiro
    // |(_____) cast para ponteiro para inteiros (tipo do elemento do vetor a ordenar)
    if(*(int *)a == *(int *)b)
        return 0; // iguais
    else
        if(*(int *)a < *(int *)b)
            return -1; // vem antes
        else
            return 1; // vem depois
}

int comparaDecrescente(const void * a, const void * b)
{
    //(_) acessa o conteudo apontado pelo ponteiro
    // |(_____) cast para ponteiro para inteiros (tipo do elemento do vetor a ordenar)
    if(*(int *)a == *(int *)b)
        return 0; // iguais
    else
        if(*(int *)a < *(int *)b)
            return 1; // vem depois
        else
            return -1; // vem antes
}

int comparaMatricula(const void * a, const void * b)
{
    if((*(struct aluno *)a).matricula ==
            (*(struct aluno *)b).matricula)
        return 0; // iguais
    else
        if((*(struct aluno *)a).matricula <
                (*(struct aluno *)b).matricula)
            return -1; // vem antes
        else
            return 1; // vem depois
}

int comparaNome(const void * a, const void * b)
{
    int r = strcmp((*(struct aluno *)a).nome,
                   (*(struct aluno *)b).nome);
    if(r == 0)
        return 0; // iguais
    else
        if(r < 0)
            return -1; // vem antes
        else
            return 1; // vem depois
}

int main()
{
    int i, nElementos;
    int vetor[] = {23,4,67,-8,90,54,21};

    struct aluno cadastro[4] = {{2, "Hugo", 9.5, 7.8, 8.5},
                                {4, "Ricardo", 7.5, 8.7, 6.8},
                                {1, "Bianca", 9.7, 6.7, 8.4},
                                {3, "Ana", 5.7, 6.1, 7.4}};

    // calculando o numero de elementos do vetor de inteiros
    nElementos = sizeof(vetor)/sizeof(int);

    printf("Vetor de inteiros ANTES da ordenacao\n");
    for(i = 0; i < nElementos; ++i)
        printf("%d  ", vetor[i]);

    //============================================
    printf("\n\nVetor APOS o qsort() em ordem crescente\n");
    qsort(vetor, nElementos, sizeof(int), comparaCrescente);
    for(i = 0; i < nElementos; ++i)
        printf("%d  ", vetor[i]);
    //============================================

    //============================================
    printf("\n\nVetor APOS o qsort() em ordem decrescente\n");
    qsort(vetor, nElementos, sizeof(int), comparaDecrescente);
    for(i = 0; i < nElementos; ++i)
        printf("%d  ", vetor[i]);
    //============================================

    //============================================
    printf("\n\nCadastro de alunos com qsort() por matricula\n");
    qsort(cadastro, 4, sizeof(struct aluno), comparaMatricula);
    for(i = 0; i < 4; ++i)
        printf("%d) %s\n", cadastro[i].matricula, cadastro[i].nome);
    //============================================

    //============================================
    printf("\n\nCadastro de alunos com qsort() por nome\n");
    qsort(cadastro, 4, sizeof(struct aluno), comparaNome);
    for(i = 0; i < 4; ++i)
        printf("%d) %s\n", cadastro[i].matricula, cadastro[i].nome);
    //============================================

    printf("\n\n");
    return 0;
}
