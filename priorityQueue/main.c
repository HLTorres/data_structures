#include <stdio.h>
#include "filaprioridade.h"

int main()
{
    struct paciente itens[6] = {{"Andre", 1},
                                {"Joao", 2},
                                {"Carlos", 5},
                                {"Nilza", 8},
                                {"Inacio", 6},
                                {"Eduardo", 4}};
    FilaPrio * fp;
    int nElementos;
    int flag;
    char nome[30];
    int i;

    fp = cria_FilaPrio();

    for (i = 0; i < 6; ++i)
    {
        printf("%d) %d %s\n", i, itens[i].prio, itens[i].nome);
        insere_FilaPrio(fp, itens[i].nome, itens[i].prio);
    }
    printf("=================================\n");

    imprime_FilaPrio(fp);
    printf("=================================\n");

    flag = insere_FilaPrio(fp, "Bianca", 9);
    imprime_FilaPrio(fp);

    nElementos = tamanho_FilaPrio(fp);
    printf("Tamanho da fila: %d\n", nElementos);

    flag = consulta_FilaPrio(fp, nome);
    if(flag)
        printf("Proximo paciente: %s\n", nome);
    printf("=================================\n");

    for (i = 0; i < nElementos; ++i)
    {
        remove_FilaPrio(fp);
        imprime_FilaPrio(fp);
        flag = consulta_FilaPrio(fp, nome);
        if(flag)
        {
            printf("Proximo paciente: %s\n", nome);
            printf("=================================\n");
        }
    }

    libera_FilaPrio(fp);
    return 0;
}
