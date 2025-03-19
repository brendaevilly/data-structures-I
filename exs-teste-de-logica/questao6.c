#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *subtrai(const char *s1, const char *s2) {
    int hash[256] = {0}; // Tabela de hash para marcar caracteres de s2
    
    // Marca os caracteres presentes em s2
    for (int i = 0; s2[i] != '\0'; i++) {
        hash[(unsigned char)s2[i]] = 1;
    }
    
    // Conta quantos caracteres de s1 não estão em s2
    int count = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (!hash[(unsigned char)s1[i]]) {
            count++;
        }
    }
    
    // Aloca espaço para a nova string
    char *result = (char *)malloc((count + 1) * sizeof(char));
    if (!result) return NULL; // Verifica se a alocação falhou
    
    // Preenche a nova string
    int j = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (!hash[(unsigned char)s1[i]]) {
            result[j++] = s1[i];
        }
    }
    result[j] = '\0'; // Termina a string corretamente
    
    return result;
}

int main() {
    char s1[] = "abacadef";
    char s2[] = "ae";
    
    char *result = subtrai(s1, s2);
    if (result) {
        printf("%s\n", result);
        free(result); // Libera a memória alocada
    }
    
    return 0;
}
