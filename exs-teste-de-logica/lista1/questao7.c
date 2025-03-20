#include <stdio.h>
#include <string.h>

void contar_caracteres(const char *vetor) {
    int contagem[256] = {0}; // Array para contar a ocorrência de cada caractere
    
    for (int i = 0; vetor[i] != '\0'; i++) {
        contagem[(unsigned char)vetor[i]]++;
    }
    
    for (int i = 0; i < 256; i++) {
        if (contagem[i] > 0) {
            printf("'%c' = %d\n", i, contagem[i]);
        }
    }
}

int main() {
    char vetor[] = "O EXERCICIO E FACIL";
    contar_caracteres(vetor);
    return 0;
}
