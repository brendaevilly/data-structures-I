#include <stdio.h>
#include <stdlib.h>

#include "ls-circular.c"

int main(){
    No *lista = criarListaCircular();
    int opcao, valor;
    No *busca;

    do{
        printf("\n===== MENU LISTA CIRCULAR =====\n");
        printf("1. Inserir elemento\n");
        printf("2. Inserir elemento ordenado\n");
        printf("3. Mostrar lista\n");
        printf("4. Buscar elemento\n");
        printf("5. Remover elemento\n");
        printf("6. Mostrar primeiro elemento\n");
        printf("7. Mostrar último elemento\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                lista = inserirElemento(lista);
                break;
            case 2:
                lista = inserirElementoOrdenado(lista);
                break;
            case 3:
                mostrarLista(lista);
                break;
            case 4:
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);
                busca = buscarElemento(lista, valor);
                if (!busca)
                    printf("Elemento nao encontrado (NULL)\n");
                else
                    printf("Elemento encontrado: %d\n", busca->info);
                break;
            case 5:
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                lista = removerElemento(lista, valor);
                break;
            case 6:
                mostrarElementoInicio(lista);
                break;
            case 7:
                mostrarElementoFim(lista);
                break;
            case 0:
                liberarLista(lista);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}
