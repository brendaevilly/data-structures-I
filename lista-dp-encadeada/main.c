#include <stdio.h>
#include <stdlib.h>

#include "ls-dp-encadeada.c"

    int main(){
        No *lista = criarLista();
        int opcao, valor;
        No *busca;

        do{
            printf("\n===== MENU LISTA DUPLAMENTE ENCADEADA =====\n");
            printf("1. Inserir no início\n");
            printf("2. Inserir no final\n");
            printf("3. Inserir ordenado\n");
            printf("4. Remover elemento\n");
            printf("5. Buscar elemento\n");
            printf("6. Mostrar lista\n");
            printf("0. Sair\n");
            printf("Escolha: ");
            scanf("%d", &opcao);

            switch(opcao){
                case 1:
                    lista = inserirElementoInicio(lista);
                    break;
                case 2:
                    lista = inserirElementoFinal(lista);
                    break;
                case 3:
                    lista = inserirElementoOrdenado(lista);
                    break;
                case 4:
                    printf("Valor a remover: "); scanf("%d", &valor);
                    lista = removerElemento(lista, valor);
                    break;
                case 5:
                    printf("Valor a buscar: "); scanf("%d", &valor);
                    busca = buscarElemento(lista, valor);
                    if(busca) printf("Elemento encontrado: %d\n", busca->info);
                    else printf("Elemento não encontrado.\n");
                    break;
                case 6:
                    printf("Lista: ");
                    mostrarLista(lista); printf("\n");
                    break;
                case 0:
                    liberarLista(lista);
                    printf("Encerrando...\n");
                    break;
                default:
                    printf("Opção inválida!\n");
            }

        }while(opcao != 0);

        return 0;
    }
