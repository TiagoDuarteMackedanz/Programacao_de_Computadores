#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto {
    int x;
    int y;
    struct ponto *proximo
} t_ponto;

int main() {
    int resp;
    t_ponto * ini_ponto;
    t_ponto * proximo_ponto;

    ini_ponto = (t_ponto *)malloc(sizeof(t_ponto));
    if(ini_ponto == NULL)
        exit(1);
    proximo_ponto = ini_ponto;

    while (1) {
        printf("Digite X: ");
        scanf("%d", &proximo_ponto->x);
        printf("Digie Y: ");
        scanf("%d", &proximo_ponto->y);
        printf("Deseja continuar? <1> SIM <Outro valor> NAO: ");
        scanf("%d",&resp);
        if (resp == 1) {
            proximo_ponto->proximo = (t_ponto *)malloc(sizeof(t_ponto));
            proximo_ponto = proximo_ponto->proximo;
        }
        else
        break;
    }
    proximo_ponto->proximo=NULL;
    proximo_ponto = ini_ponto;
    while (proximo_ponto != NULL){
        printf ("X: %d Y: %d\n", proximo_ponto->x, proximo_ponto->y);
        proximo_ponto = proximo_ponto->proximo;
    }
    return 0;
}