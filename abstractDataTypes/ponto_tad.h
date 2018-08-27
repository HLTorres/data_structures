#ifndef PONTO_TAD_H
#define PONTO_TAD_H

//Apelido
typedef struct ponto Ponto;

//Cria novo ponto
Ponto* pto_cria(float x, float y);
//Libera ponto
void pto_libera(Ponto* p);
//Acessa os valores "x" e "y" de um ponto
void pto_acessa(Ponto* p, float* x, float* y);
//Atribui os valores "x" e "y" de um ponto
void pto_atribui(Ponto* p, float x, float y);
//Calcula a distancia entre dois pontos
float pto_distancia(Ponto* p1, Ponto* p2);

#endif // PONTO_TAD_H
