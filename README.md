#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 70
#define MAX_NOME 50
#define MAX_DATA 20

typedef struct {
    char nome[MAX_NOME];
    int presente;
} Aluno;

void adicionarAluno(Aluno *alunos, int *totalAlunos) {
    if (*totalAlunos < MAX_ALUNOS) {
        printf("Informe o nome do novo aluno: ");
        scanf("%s", alunos[*totalAlunos].nome);
        alunos[*totalAlunos].presente = 0; // Inicialmente, o aluno está ausente
        (*totalAlunos)++;
        printf("Aluno adicionado com sucesso.\n");
    } else {
        printf("Erro: Limite de alunos atingido.\n");
    }
}

int buscarAluno(Aluno *alunos, int totalAlunos, char *nome) {
    for (int i = 0; i < totalAlunos; i++) {
        if (strcmp(alunos[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1; // Retorna -1 se o aluno não for encontrado
}

void editarAluno(Aluno *alunos, int totalAlunos) {
    char nome[MAX_NOME];
    printf("Informe o nome do aluno que deseja editar: ");
    scanf("%s", nome);

    int indice = buscarAluno(alunos, totalAlunos, nome);

    if (indice != -1) {
        printf("Informe o novo nome do aluno: ");
        scanf("%s", alunos[indice].nome);
        printf("Edição concluída com sucesso.\n");
    } else {
        printf("Erro: Aluno não encontrado.\n");
    }
}

void removerAluno(Aluno *alunos, int *totalAlunos) {
    char nome[MAX_NOME];
    printf("Informe o nome do aluno que deseja remover: ");
    scanf("%s", nome);

    int indice = buscarAluno(alunos, *totalAlunos, nome);

    if (indice != -1) {
        // Substitui o aluno a ser removido pelo último aluno na lista
        alunos[indice] = alunos[(*totalAlunos) - 1];
        (*totalAlunos)--;
        printf("Aluno removido com sucesso.\n");
    } else {
        printf("Erro: Aluno não encontrado.\n");
    }
}

void fazerChamada(Aluno *alunos, int totalAlunos) {
    for (int i = 0; i < totalAlunos; i++) {
        printf("O aluno %s está presente? (1 para sim, 0 para não): ", alunos[i].nome);
        scanf("%d", &alunos[i].presente);
    }
}

void exibirChamada(Aluno *alunos, int totalAlunos) {
    printf("\nChamada:\n");
    for (int i = 0; i < totalAlunos; i++) {
        printf("Aluno %s: %s\n", alunos[i].nome, alunos[i].presente ? "Presente" : "Ausente");
    }
}

void salvarChamada(Aluno *alunos, int totalAlunos, char *data) {
    char nomeArquivo[MAX_DATA + 4]; // MAX_DATA (data) + 4 (.txt e caractere nulo)
    sprintf(nomeArquivo, "%s.txt", data);

    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo != NULL) {
        for (int i = 0; i < totalAlunos; i++) {
            printf(arquivo, "%s: %s\n", alunos[i].nome, alunos[i].presente ? "Presente" : "Ausente");
        }
        fclose(arquivo);
        printf("Chamada salva em %s\n", nomeArquivo);
    } else {
        printf("Erro: Não foi possível abrir o arquivo para escrita.\n");
    }
}

int main() {
    Aluno alunos[MAX_ALUNOS];
    int totalAlunos = 0;
    char data[MAX_DATA];

    printf("Informe a data (DD-MM-AAAA): ");
    scanf("%s", data);

    int opcao;

    do {
        printf("\n1 - Adicionar Aluno\n");
        printf("2 - Buscar Aluno\n");
        printf("3 - Editar Aluno\n");
        printf("4 - Remover Aluno\n");
        printf("5 - Fazer Chamada\n");
        printf("6 - Exibir Chamada\n");
        printf("7 - Salvar Chamada\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarAluno(alunos, &totalAlunos);
                break;
            case 2:
                {
                    char nome[MAX_NOME];
                    printf("Informe o nome do aluno: ");
                    scanf("%s", nome);
                    int indice = buscarAluno(alunos, totalAlunos, nome);
                    if (indice != -1) {
                        printf("Aluno encontrado: %s\n", alunos[indice].nome);
                    } else {
                        printf("Aluno não encontrado.\n");
                    }
                }
                break;
            case 3:
                editarAluno(alunos, totalAlunos);
                break;
            case 4:
                removerAluno(alunos, &totalAlunos);
                break;
            case 5:
                fazerChamada(alunos, totalAlunos);
                break;
            case 6:
                exibirChamada(alunos, totalAlunos);
                break;
            case 7:
                salvarChamada(alunos, totalAlunos, data);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
