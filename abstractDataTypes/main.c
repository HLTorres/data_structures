#include <stdio.h>
#include "ponto_tad.h"

int main()
{
    float distancia, ponto_x, ponto_y;
    Ponto *p1, *p2, *p3;
    //Ponto p; //ERRO, nao e possivel declarar um ponto

    p1 = pto_cria(10,21);
    p2 = pto_cria(7,25);
    p3 = pto_cria(0, 0);
    //p->x = 2; //ERRO, nao e possivel alterar diretamente uma variavel do ponto

    distancia = pto_distancia(p1, p2);
    printf("Distancia entre pontos: %.2f\n",distancia);

    pto_acessa(p3, &ponto_x, &ponto_y);
    printf("\nAntes de atribuir\nCoordenada x: %.2f\nCoordenada y: %.2f\n\n",ponto_x,ponto_y);

    pto_atribui(p3, 9.3, 17.1);
    pto_acessa(p3, &ponto_x, &ponto_y);
    printf("Depois de atribuir\nCoordenada x: %.2f\nCoordenada y: %.2f\n\n",ponto_x,ponto_y);

    pto_libera(p1);
    pto_libera(p2);
    pto_libera(p3);

    system("pause");
    return 0;
}
