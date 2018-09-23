#ifndef FILAPRIORIDADE_H
#define FILAPRIORIDADE_H

/* tamanho maximo da fila de prioridade (lista estatica) */
#define MAX 100

/* tipo de dados armazenado na fila de prioridade (lista estatica) */
struct paciente {
    char nome[30];
    int prio;
};

/* apelido da fila de prioridade definida no arquivo .c */
typedef struct filaPrioridade FilaPrio;

/* funcoes exatamente iguais a lista sequencial estatica */
FilaPrio * cria_FilaPrio();
void libera_FilaPrio(FilaPrio * fp);
int tamanho_FilaPrio(FilaPrio * fp);
int estaCheia_FilaPrio(FilaPrio * fp);
int estaVazia_FilaPrio(FilaPrio * fp);

/* funcoes baseadas na lista estatica mas, agora,
 * considerando tambem a prioridade dos elementos. */
int consulta_FilaPrio(FilaPrio * fp, char * nome);
int insere_FilaPrio(FilaPrio * fp, char * nome, int  prioridade);
int remove_FilaPrio(FilaPrio * fp);

/* funcao adicional para impressao da fila de prioridade */
void imprime_FilaPrio(FilaPrio * fp);

#endif // FILAPRIORIDADE_H
