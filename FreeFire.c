// Desafio Código da Ilha – Free Fire
// Nível Mestre

// Objetivo: Criar um sistema modular que gerencie componentes de uma "torre de resgate", permitindo cadastrar, organizar, localizar peças específicas e medir a eficiência técnica de cada método escolhido na comparação (Bubble Sort, Insertion Sort e Selection Sort).

// Bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definição de constantes
#define MAX_COMPONENTES 20

// Definição da STRUCT para os componentes da torre de resgate
typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

// Variável global para contar comparações
int numComparacoes = 0; 

// Prótotipos das funções
void adicionarComponentes(Componente vetor[], int* totalComponentes);
void descartarComponentes(Componente vetor[], int* totalComponentes);
void mostrarComponentes(Componente vetor[], int totalComponentes);
void selectionSortPrioridade(Componente vetor[], int totalComponentes);
void insertionSortTipo(Componente vetor[], int totalComponentes);
void bubbleSortNome(Componente vetor[], int totalComponentes);
void buscaBinariaPorNome(Componente vetor[], int totalComponentes, char* nome);
void medirTempo(void (*algoritmo)(Componente[], int), Componente vetor[], int totalComponentes);

// Função principal
int main() {
    Componente torreResgate[MAX_COMPONENTES];
    int totalComponentes = 0;
    int ordenadoPorNome = 0; // Flag para indicar se os componentes estão ordenados por nome
    int opcao, subOpcao;
    char buscaPorNome[30];

    do {
        printf("=============================================\n");
        printf("PLANO DE FUGA - CÓDIGO DA ILHA (NÍVEL MESTRE)\n");
        printf("=============================================\n");
        printf("Itens na mochila: %d/20\n", totalComponentes);
        printf("Status da ordenação por nome: %s", (ordenadoPorNome? "ORDENADO" : "NÃO ORDENADO"));
        printf("\n\n1. Adicionar Componentes\n");
        printf("2. Descartar Componentes\n");
        printf("3. Mostrar Componentes (inventário)\n");
        printf("4. Organizar mochila (ordenar componentes)\n");
        printf("5. Busca binária por Componente-Chave (por nome)\n");
        printf("0. ATIVAR TORRE DE FUGA (sair)\n");
        printf("---------------------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer de entrada
        printf("---------------------------------------------\n");

        switch (opcao) {
            case 1: 
                adicionarComponentes(torreResgate, &totalComponentes);
                ordenadoPorNome = 0; 
                break;
            case 2:
                descartarComponentes(torreResgate, &totalComponentes);
                ordenadoPorNome = 0; 
                break;
            case 3: 
                mostrarComponentes(torreResgate, totalComponentes);
                break;
            case 4:
                if (totalComponentes <= 1) {
                    printf("Não há componentes suficientes para organizar.\n");
                } else {
                    do {
                        printf("\nEscolha o método de ordenação:\n");
                        printf("1. Por prioridade (Selection Sort)\n");
                        printf("2. Por tipo (Insertion Sort)\n");
                        printf("3. Por nome (Bubble Sort)\n");
                        printf("----------------------------------\n");
                        printf("Escolha uma opção: ");
                        scanf("%d", &subOpcao);
                        getchar(); 
                        printf("----------------------------------\n");

                        switch (subOpcao) {
                            case 1:
                                medirTempo(selectionSortPrioridade, torreResgate, totalComponentes);
                                ordenadoPorNome = 0; 
                                printf("Componentes organizados por prioridade.\n");
                                break;
                            case 2:
                                medirTempo(insertionSortTipo, torreResgate, totalComponentes);
                                ordenadoPorNome = 0;
                                printf("Componentes organizados por tipo.\n");
                                break;
                            case 3:
                                medirTempo(bubbleSortNome, torreResgate, totalComponentes);
                                ordenadoPorNome = 1; 
                                printf("Componentes organizados por nome. Busca binária liberada!\n");
                                break;
                            default:
                                printf("Opção inválida. Tente novamente.\n");
                        } 
                    } while (subOpcao < 1 || subOpcao > 3);
                }
                break;

            case 5:
                if (!ordenadoPorNome) {
                    printf("[AVISO] Os componentes precisam estar organizados por nome para a realização de uma busca binária.\n");
                } else {
                    printf("Digite o nome do componente que deseja buscar: ");
                    fgets(buscaPorNome, sizeof(buscaPorNome), stdin);
                    buscaPorNome[strcspn(buscaPorNome, "\n")] = '\0'; 
                    buscaBinariaPorNome(torreResgate, totalComponentes, buscaPorNome);
                }
                break;
            case 0:
                printf("Ativando a torre de fuga... Boa sorte!\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);
    return 0;
}

// Função para medir o tempo de execução e contar comparações
void medirTempo(void (*algoritmo)(Componente[], int), Componente vetor[], int totalComponentes) {
    numComparacoes = 0;
    clock_t inicio = clock();
    
    algoritmo(vetor, totalComponentes);
    
    clock_t fim = clock();
    
    // Cálculo: (Diferença de ticks / Ticks por segundo) * 1000 para milissegundos
    double tempoMilissegundos = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;

    printf("\n>>> RELATÓRIO DE DESEMPENHO TÁTICO <<<\n");
    printf("Comparações realizadas: %d\n", numComparacoes);
    printf("Tempo de CPU: %.10f ms (milissegundos)\n", tempoMilissegundos);
    mostrarComponentes(vetor, totalComponentes);
}

// Função para adicionar componentes à mochila
void adicionarComponentes(Componente vetor[], int* totalComponentes) {
    if (*totalComponentes < MAX_COMPONENTES) {
        printf("Nome do componente: ");
        fgets(vetor[*totalComponentes].nome, 30, stdin);
        vetor[*totalComponentes].nome[strcspn(vetor[*totalComponentes].nome, "\n")] = 0;

        printf("Tipo (ex: cura, arma, eletronico, municao e etc.): ");
        fgets(vetor[*totalComponentes].tipo, 20, stdin);
        vetor[*totalComponentes].tipo[strcspn(vetor[*totalComponentes].tipo, "\n")] = 0;

        printf("Prioridade (1-10): ");
        scanf("%d", &vetor[*totalComponentes].prioridade);
        getchar();

        (*totalComponentes)++;
        printf("Item adicionado ao inventário da mochila!\n");
    } else {
        printf("Mochila cheia!\n");
    }
}


