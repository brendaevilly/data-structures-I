#include <stdio.h>
#include <stdlib.h>

    typedef struct{
        int matricula, serie;
        char nome[50];
    }Aluno;

    void dadosCadastro(int num, Aluno *lista, int alunos);

    int main(){

        int alunos;
        scanf("%d", &alunos);
        Aluno *lista;

        lista = (Aluno *)calloc(alunos, sizeof(Aluno));

        for(int i=0; i<alunos; i++){
            printf("\nNome: ");
            setbuf(stdin, NULL);
            scanf("%[^\n]", lista[i].nome);
            printf("\nMatricula: ");
            scanf("%d", &lista[i].matricula);
            printf("\nSerie: ");
            scanf("%d", &lista[i].serie);
        }

        printf("\n");

        int num;
        printf("Digite a matricula do aluno procurado: \n");
        scanf("%d", &num);

        dadosCadastro(num, lista, alunos);

        free(lista);

        return 0;
    }

    void dadosCadastro(int num, Aluno *lista, int alunos){
        int existe = 0;
        for(int i=0; i<alunos; i++){
            if(num == lista[i].matricula){
                printf("Nome: %s\n", lista[i].nome);
                printf("Matricula: %d\n", lista[i].matricula);
                printf("Serie: %d\n", lista[i].serie);
                existe = 1;
            }
        }
        
        if(existe == 0){
            printf("Esse aluno nao foi registrado.\n");
        }
    }