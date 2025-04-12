#include <stdlib.h>
#include <stdio.h>

#include "ponto.h"

int main(void){
    
    Ponto *p1;

    p1 = criarPonto(23, 87);

    printPonto(p1);

    return 0;
}