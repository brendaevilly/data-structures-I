#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "ponto.h"

typedef struct ponto{
    int x, y;
};
Ponto* criarPonto(int x, int y){
    Ponto *p1 = (Ponto *) malloc(sizeof(Ponto));
    p1->x = x;
    p1->y = y;
    return p1;
}

void printPonto(Ponto *p){
    printf("X -> %d ", p->x);
    printf("Y -> %d ", p->y);
}

float distanciaEntrePonts(Ponto *p1, Ponto *p2){
    return pow(p1->x - p1->y, 2) + pow(p2->y - p2->x, 2);
}

void deslocarPonto(Ponto *p, int x, int y){
    p->x = x;
    p->y = y;
}

void liberarPonto(Ponto *p){
    free(p);
}

