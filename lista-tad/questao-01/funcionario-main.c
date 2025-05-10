#include <stdio.h>
#include <stdlib.h>

#include "funcionario.c"

    int main(){
        Funcionario *funcionario;
        int quantidade, id1, id2, resultado;

        printf("Quantidade de funcionarios na empresa: "); scanf("%d", &quantidade);

        funcionario = criarFuncionario(quantidade);

        printf("ID 1: "); scanf("%d", &id1);
        printf("ID 2: "); scanf("%d", &id2);

        resultado = verificarSobreposicao(id1, id2, funcionario, quantidade);

        if(resultado){
            printf("Existe sobreposicao de horarios.\n");
        }else if(resultado == -1){
            printf("Nao foi/ram encontrado/s funcionairo/s com esse/s ID/s.\n");
        }else{
            printf("Nao existe sobreposicao de horarios.\n");
        }

        liberarVetor(funcionario);

        return 0;
    }