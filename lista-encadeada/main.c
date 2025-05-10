#include <stdio.h>
#include <stdlib.h>
#include "ls-encadeada.c"

int main() {
    No *lista = criaLista();
    int opcao, valor;
    No *buscado;

    do{
        printf("\n--- MENU ---\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no fim\n");
        printf("3. Inserir ordenado\n");
        printf("4. Mostrar lista\n");
        printf("5. Buscar elemento\n");
        printf("6. Liberar lista e sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                lista = insereNoInicio(lista);
                break;
            case 2:
                lista = inseroNoFim(lista);
                break;
            case 3:
                lista = inserirElementoOrdenado(lista);
                break;
            case 4:
                mostraLista(lista);
                break;
            case 5:
                printf("Valor a buscar: ");
                scanf("%d", &valor);
                buscado = buscarElemento(lista, valor);
                if(buscado != NULL){
                    printf("Elemento encontrado: %d\n", buscado->info);
                    free(buscado);
                }else{
                    printf("Elemento nao encontrado.\n");
                }
                break;
            case 6:
                liberarLista(lista);
                printf("Lista liberada. Saindo...\n");
                break;
            default:
                printf("Opção invalida!\n");
        }
    }while(opcao != 6);

    return 0;
}
