#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_CLIENTES 1000
#define TAM_LINHA 256

typedef struct {
    int id;
    char nome[100];
    char email[100];
    int idade;
} Cliente;

void carregarClientes(const char *nomeArquivo, Cliente clientes[], int *quantidade) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        *quantidade = 0;
        return;
    }

    char linha[TAM_LINHA];
    *quantidade = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (*quantidade >= MAX_CLIENTES) {
            printf("Limite máximo de clientes atingido.\n");
            break;
        }

        linha[strcspn(linha, "\n")] = '\0';

        // Separar os dados por ";"
        char *token = strtok(linha, ";");
        if (token == NULL) continue;
        clientes[*quantidade].id = atoi(token);

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        strncpy(clientes[*quantidade].nome, token, sizeof(clientes[*quantidade].nome));
        clientes[*quantidade].nome[sizeof(clientes[*quantidade].nome) - 1] = '\0';

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        strncpy(clientes[*quantidade].email, token, sizeof(clientes[*quantidade].email));
        clientes[*quantidade].email[sizeof(clientes[*quantidade].email) - 1] = '\0';

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        clientes[*quantidade].idade = atoi(token);

        (*quantidade)++;
    }

    fclose(arquivo);
}


// funcoes que deverao ser implementadas. Usem os parametros que acharem necessário

// 1 - buscarClientePorId() 
// 2 - imprimirCliente()
// 3 - removerCliente()
// 4 - alterarDadosCliente()
// 5 - salvar dados dos clientes() - salvar no mesmo formato que o de leitura

void menu() {
    printf("1 - Buscar cliente por ID\n");
    printf("2 - Remover cliente\n");
    printf("3 - Alterar dados do cliente\n");
    printf("4 - Sair\n");

}

void salvarDadosDosClientes(const char *nomeArquivo, Cliente clientes[], int quantidade) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s para escrita.\n", nomeArquivo);
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%d;%s;%s;%d\n", clientes[i].id, clientes[i].nome, clientes[i].email, clientes[i].idade);
    }

    fclose(arquivo);
    printf("Dados dos clientes salvos com sucesso.\n");
}


int buscarClientePorId(int idBusca, int *quantidade, Cliente *clientes) {
    for (int i = 0; i < *quantidade; i++) {
        if (idBusca == clientes[i].id) {
            return i; 
        }
    }

    return -1; 
}


void imprimirCliente(int id, Cliente clientes[], int quantidade) {
    if (id >= 0 && id < quantidade) {
        printf("Id: %d\nNome: %s\nEmail: %s\nIdade: %d\n", clientes[id].id, clientes[id].nome, clientes[id].email, clientes[id].idade);
    }else{
        printf("Cliente não encontrado.\n");
    }

}

void removerCliente(int idRemover, int *quantidade, Cliente *clientes) {
    int index = -1;

    for (int i = 0; i < *quantidade; i++) {
        if (clientes[i].id == idRemover) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Cliente não encontrado.\n");
        return;
    }

    for (int i = index; i < *quantidade - 1; i++) {
        clientes[i] = clientes[i + 1];
    }

    (*quantidade)--;

    salvarDadosDosClientes("clientes.txt", clientes, *quantidade);

    printf("Cliente removido com sucesso.\n");

}

void alterarDadosCliente(int idAlterar, Cliente *clientes, int quantidade) {
    int index = buscarClientePorId(idAlterar, &quantidade, clientes);

    if (index == -1) {
        printf("Cliente nao encontrado.\n");
        return;
    }
    printf("Alterando dados do cliente:\n");

    printf("Nome atual: %s\n", clientes[index].nome);
    printf("Email atual: %s\n", clientes[index].email);
    printf("Idade atual: %d\n", clientes[index].idade);

    printf("Digite o novo nome: ");
    scanf(" %[^\n]", clientes[index].nome); 
    printf("Digite o novo email: ");
    scanf(" %[^\n]", clientes[index].email);
    printf("Digite a nova idade: ");
    scanf("%d", &clientes[index].idade);

    salvarDadosDosClientes("clientes.txt", clientes, quantidade);

    printf("Dados do cliente alterados com sucesso.\n");
}


int main() {
    Cliente clientes[MAX_CLIENTES];
    int quantidade;

    carregarClientes("clientes.txt", clientes, &quantidade);

    while (1) {
        menu();
        int op;
        scanf("%d", &op);

        if(op == 1) {
            int idBusca;
            printf("\nId de busca: ");
            scanf("%d", &idBusca);
            int id = buscarClientePorId(idBusca, &quantidade, clientes);
            if (id == -1) {
                printf("\nCliente inexistente no arquivo.\n");
            } else {
                printf("\nCliente Buscado:\n");
                imprimirCliente(id, clientes, quantidade);
            }
        }else if(op == 2) {
            int idRemover;
            printf("\nId para remover: ");
            scanf("%d", &idRemover);
            removerCliente(idRemover, &quantidade, clientes);
        }else if(op == 3){
            int idAlt;
            printf("\nId para alterar dados: ");
            scanf("%d", &idAlt);
            alterarDadosCliente(idAlt, clientes, quantidade);
        }else if(op == 4) {
            break; // Sair do loop
        }else{
            printf("Opcao invalida. Tente novamente.\n");
        }

    }

    return 0;

}


