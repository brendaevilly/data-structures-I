#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Estrutura do Codigo (Lucas):
    --------------------
    1. CriarMatrizDinamica   -> Aloca dinamicamente uma matriz N x M e a preenche com valores aleatorios.
    2. CriarVetorDinamico    -> Aloca dinamicamente um vetor para contar ocorrências de numeros.
    3. Solve                 -> Solução para o problema, aplicação direta de hashing ("dp fraco").
    4. LiberarMemoriaMatriz  -> Libera a memória alocada para a matriz.
    5. LiberarMemoriaVetor   -> Libera a memória alocada para o vetor.

    Constantes pré-definidas:
    -------------------------
    - N = 256 elementos (limite superior dos valores aleatórios gerados).
*/

#define N 256

// #-------------------------------------------------------
int **CriarMatrizDinamica(int, int);
int *CriarVetorDinamico();
void solve(int **, int *, int, int);
void LiberarMemoriaMatriz(int **, int);
void LiberarMemoriaVetor(int *);
// #-------------------------------------------------------
int **CriarMatrizDinamica(int n, int m) {
    int **matriz = malloc(n * sizeof(int *));
    if (!matriz) return NULL;
    for (int i = 0;i < n;++i) {
        *(matriz + i) = malloc(m * sizeof(int));
        if (!(*(matriz + i))) {
            LiberarMemoriaMatriz(matriz, ((i > 0) ? i : 1));
            return NULL;
        }
        for (int j = 0;j < m;++j) *(*(matriz + i) + j) = rand() % 257;
    }
    return matriz;
}

int *CriarVetorDinamico() {
    int *vetor = calloc((N + 1), sizeof(int));
    if (!vetor) return NULL;
    return vetor;
}

void Solve(int **matriz, int *vetor, int n, int m) {
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) (*(vetor + *(*(matriz + i) + j)))++; 
    }
}

void LiberarMemoriaMatriz(int **matriz, int n) {
    for (int i = 0;i < n;++i) free(*(matriz + i));
    free(matriz);
    matriz = NULL;
}

void LiberarMemoriaVetor(int *vetor) {
    free(vetor);
    vetor = NULL;
}
// #-------------------------------------------------------
int main() {

    srand((unsigned) time(NULL));

    int n, m; scanf("%d %d", &n, &m);
    int **matriz = CriarMatrizDinamica(n, m);
    if (!matriz) {
        printf("Matriz vazia, ocorreu um erro na alocação de memoria!\n");
        exit(EXIT_FAILURE);
    }

    int *vetor = CriarVetorDinamico();
    if (!vetor) {
        printf("Vetor vazio, ocorreu um erro na alocação de memoria!\n");
        exit(EXIT_FAILURE);
    }

    Solve(matriz, vetor, n, m);

    for (int i = 0;i < N + 1;++i) {
        if (!(*(vetor + i))) continue;
        printf("Valor: %d Ocorrencia: %d\n", i, *(vetor + i));
    }

    LiberarMemoriaMatriz(matriz, n);
    LiberarMemoriaVetor(vetor);

    return 0;
}