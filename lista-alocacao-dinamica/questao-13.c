#include <stdio.h>
#include <stdlib.h>

    typedef struct{
        int *dados;
        int tamanho;
        int capacidade;
    }Vector;

    Vector* criarVector(int capacidadeInicial);
    int push_back(Vector* v, int elemento);
    int push(Vector *v, int elemento, int index);
    int pop(Vector *v, int index);
    int pop_Back(Vector* v);
    int size(Vector *v);
    void free_vector(Vector *v);
    void clear(Vector *v);

    int main(){
        int capacidadeInicial, op;
        Vector *v;
        printf("Capacidade inicial: "); scanf("%d", &capacidadeInicial);
        v = criarVector(capacidadeInicial);
        
        while(1){
            int elemento, index, verifica = 0;
            printf("1 - Push back\n2 - Push\n3 - Pop\n4 - Pop back\n5 - Size\n6 - Clear\n7 - Sair\nOpcao: "); scanf("%d", &op);
            while(op < 1 || op > 7){
                printf("[ERRO] Opcao invalida.\n");
                printf("1 - Push back\n2 - Push\n3 - Pop\n4 - Pop back\n5 - Size\n6 - Clear\n7 - Sair\nOpcao: "); scanf("%d", &op);
            }

            switch (op){
            case 1:
                printf("Elemento: "); scanf("%d", &elemento);
                verifica = push_back(v, elemento);
                if(!verifica){
                    printf("Ops... Algo deu errado.\n");
                    break;
                }
                for(int i=0; i<v->tamanho; i++){
                    printf("%d\n", v->dados[i]);
                }

                break;
            case 2:
                printf("Elemento: "); scanf("%d", &elemento);
                printf("Index: "); scanf("%d", &index);
                verifica = push(v, elemento, index);
                if(!verifica){
                    printf("Ops... Algo deu errado.\n");
                    break;
                }
                for(int i=0; i<v->tamanho; i++){
                    printf("%d\n", v->dados[i]);
                }

                break;
            case 3:
                printf("Index: "); scanf("%d", &index);
                verifica = pop(v, index);
                if(!verifica){
                    printf("Ops... Algo deu errado.\n");
                    break;
                }
                for(int i=0; i<v->tamanho; i++){
                    printf("%d\n", v->dados[i]);
                }

                break;
            case 4:
                verifica = pop_Back(v);
                if(!verifica){
                    printf("Ops... Algo deu errado.\n");
                    break;
                }
                for(int i=0; i<v->tamanho; i++){
                    printf("%d\n", v->dados[i]);
                }

                break;
            case 5:
                printf("Tamanho: %d\n", size(v));

                break;
            case 6:
                clear(v);
                printf("Vetor limpo.\n");

                break;
            default:
                printf("Saindo do programa...\n");
                break;
            }

            if(op == 7) break;
        }

        return 0;
    }

    Vector* criarVector(int capacidadeInicial){
        Vector *v;
        v = (Vector*)malloc(sizeof(Vector));

        v->dados = (int*)malloc(capacidadeInicial*sizeof(int));
        v->tamanho = 0;
        v->capacidade = capacidadeInicial;

        return v;
    }

    int push_back(Vector* v, int elemento){
        if(v->tamanho > v->capacidade){
            v->capacidade *= 2;
            v->dados = (int *)realloc(v->dados, v->capacidade*sizeof(int));
        }

        v->dados[v->tamanho] = elemento;
        v->tamanho++;

        return 1;
    }

    int push(Vector *v, int elemento, int index){
        if(index < 0 || index >= v->tamanho){
            return 0;
        }

        if(v->tamanho > v->capacidade){
            v->capacidade *= 2;
            v->dados = (int *)realloc(v->dados, v->capacidade*sizeof(int));
        }

        for(int i=v->tamanho; i>index; i--){
            v->dados[i] = v->dados[i-1];
        }

        v->dados[index] = elemento;
        v->tamanho++;

        return 1;
    }

    int pop(Vector *v, int index){
        if(index < 0 || index >= v->tamanho){
            return 0;
        }
        for(int i=index; i<v->tamanho-1; i++){
            v->dados[i] = v->dados[i+1];
        }

        v->tamanho--;

        return 1;
    }

    int pop_Back(Vector* v){
        if(v->tamanho == 0) return 0;

        v->tamanho--;

        return 1;
    }

    int size(Vector *v){
        return v->tamanho;
    }

    void free_vector(Vector *v){
        free(v->dados);
        free(v);
    }

    void clear(Vector *v){
        v->tamanho = 0;
    }