#ifndef GEOMETRIA_H
#define GEOMETRIA_H

    int **criaMatriz(int lin, int col);
    int ehQuadrado(int **mat, int lin, int col);
    int ehTriangulo(int **mat, int lin, int col);
    void freeMatriz(int **mat, int lin);

#endif