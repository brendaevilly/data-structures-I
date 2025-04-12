#ifndef PONTO_H
#define PONTO_H

typedef struct ponto Ponto;
Ponto* criarPonto(int x, int y);
void printPonto(Ponto *p);

float distanciaEntrePonts(Ponto *p1, Ponto *p2);
void deslocarPonto(Ponto *p, int x, int y);
void liberarPonto(Ponto *p);

#endif