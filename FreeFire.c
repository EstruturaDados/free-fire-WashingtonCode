// Desafio Código da Ilha – Free Fire
// Nível Aventureiro

// Objetivo: Desenvolver, em linguagem C, duas versões do sistema de inventário ("mochila"), utilizando estruturas de dados distintas: vetores e listas encadeadas. Após utilizar as mesmas operações básicas (inserção, remoção, listagem e busca) nas duas versões, ao final, comparar o desempenho das estruturas. Após ordenar os dados no vetor, você deverá aplicar uma busca binária para localizar com rapidez um item crítico.

// Bibliotecas Necessárias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição de Constantes
#define MAX_ITENS 10

// Definição das Structs
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

typedef struct No {
    Item dados;
    struct No* proximo;
} No;

// Variáveis Globais para Contagem de Comparações
int comparacoesBusca = 0;

// --- PROTÓTIPOS DE FUNÇÕES ---

// Funções de Vetor
void inserirVetor(Item vetor[], int *totalItens);
void listarVetor(Item vetor[], int totalItens);
void buscarSequencialVetor(Item vetor[], int totalItens);
void ordenarVetor(Item vetor[], int totalItens);
void buscarBinariaVetor(Item vetor[], int totalItens);
void removerVetor(Item vetor[], int *totalItens);

// Funções de Lista Encadeada
void inserirLista(No** primeiroItem);
void listarLista(No* primeiroItem);
void buscarLista(No* primeiroItem);
void removerLista(No** primeiroItem);
void limparMochilaLista(No* primeiroItem);

// --- FUNÇÃO MAIN ---
int main() {
    Item mochilaVetor[MAX_ITENS];
    int totalVetor = 0;
    No* mochilaLista = NULL;
    int opcao, subOpcao;
    
    // Loop Principal do Menu
    do {
        printf("\n=== DESAFIO CÓDIGO DA ILHA (FREE FIRE) ===\n");
        printf(">>> INVENTÁRIO DA MOCHILA\n");
        printf(">>> TERMINAL TÁTICO: SELECIONE O MODO DE ARMAZENAMENTO\n");
        printf("1. Modo Vetor (lista sequencial/estático)\n");
        printf("2. Modo Lista Encadeada (Dinâmico)\n");
        printf("0. Sair\n");
        printf("Selecione o comando de ação: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            do {
                printf("\n--- MODO VETOR ---\n");
                printf(">>> TERMINAL TÁTICO: OPERAÇÕES DE INVENTÁRIO\n");
                printf("1. Inserir item (loot)\n");
                printf("2. Listar item\n");
                printf("3. Buscar item (busca sequencial).\n");
                printf("4. Ordenar/Buscar item (busca binária).\n");
                printf("5. Descartar item\n");
                printf("0. Voltar\n");
                printf("Selecione o comando de ação: ");
                scanf("%d", &subOpcao);
                getchar();
                if (subOpcao == 1) inserirVetor(mochilaVetor, &totalVetor);
                else if (subOpcao == 2) listarVetor(mochilaVetor, totalVetor);
                else if (subOpcao == 3) buscarSequencialVetor(mochilaVetor, totalVetor);
                else if (subOpcao == 4) {
                    ordenarVetor(mochilaVetor, totalVetor);
                    buscarBinariaVetor(mochilaVetor, totalVetor);
                }
                else if (subOpcao == 5) removerVetor(mochilaVetor, &totalVetor);
            } while (subOpcao != 0);
        } else if (opcao == 2) {
            do {
                printf("\n--- MODO LISTA ENCADEADA ---\n");
                printf(">>> TERMINAL TÁTICO: OPERAÇÕES DE INVENTÁRIO\n");
                printf("1. Inserir item (loot)\n");
                printf("2. Listar item\n");
                printf("3. Buscar item\n");
                printf("4. Descartar item\n");
                printf("0. Voltar\n");
                printf("Selecione o comando de ação: ");
                scanf("%d", &subOpcao);
                getchar();
                if (subOpcao == 1) inserirLista(&mochilaLista);
                else if (subOpcao == 2) listarLista(mochilaLista);
                else if (subOpcao == 3) buscarLista(mochilaLista);
                else if (subOpcao == 4) removerLista(&mochilaLista);
            } while (subOpcao != 0);
        }
    } while (opcao != 0);
    
    if (mochilaLista != NULL) {
        limparMochilaLista(mochilaLista);
    }

    printf("Saindo do jogo...\n");
    return 0;
}

// --- IMPLEMENTAÇÃO VETOR ---

// Função para Inserir Item no Vetor
void inserirVetor(Item vetor[], int *totalItens) {
    if (*totalItens < MAX_ITENS) {
        printf("Nome do item: "); fgets(vetor[*totalItens].nome, 30, stdin); vetor[*totalItens].nome[strcspn(vetor[*totalItens].nome, "\n")] = 0;
        printf("Tipo do item: "); fgets(vetor[*totalItens].tipo, 20, stdin); vetor[*totalItens].tipo[strcspn(vetor[*totalItens].tipo, "\n")] = 0;
        printf("Qtd do item: "); scanf("%d", &vetor[*totalItens].quantidade);
        getchar();
        (*totalItens)++;
        printf("Item registrado com sucesso no banco de dados estático.\n");
    } else printf("Mochila (Vetor) cheia!\n");
}

// Função para Listar Itens do Vetor
void listarVetor(Item vetor[], int totalItens) {
    printf("\n%-20s | %-15s | %s\n", "NOME", "TIPO", "QTD");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < totalItens; i++) 
        printf("%-20s | %-15s | %d\n", vetor[i].nome, vetor[i].tipo, vetor[i].quantidade);
}

// Função para Buscar Item no Vetor (Busca Sequencial)
void buscarSequencialVetor(Item vetor[], int totalItens) {
    char itemAlvo[30];
    comparacoesBusca = 0;
    printf("Qual o nome do item que deseja buscar? "); fgets(itemAlvo, 30, stdin); itemAlvo[strcspn(itemAlvo, "\n")] = 0;
    
    for (int i = 0; i < totalItens; i++) {
        comparacoesBusca++;
        if (strcasecmp(vetor[i].nome, itemAlvo) == 0) {
            printf("[DADO LOCALIZADO] Item detectado após %d varreduras no sistema\n", comparacoesBusca);
            return;
        }
    }
    printf("[ERRO DE RASTREIO] Após %d varreduras no sistema, o item não foi localizado no inventário.\n", comparacoesBusca);
}

// Função para Ordenar o Vetor (Bubble Sort) e Preparar para Busca Binária
void ordenarVetor(Item vetor[], int totalItens) {
    // Bubble Sort: Ordenando por Nome
    for (int i = 0; i < totalItens - 1; i++) {
        for (int j = 0; j < totalItens - i - 1; j++) {
            if (strcasecmp(vetor[j].nome, vetor[j+1].nome) > 0) {
                Item temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
    printf("Vetor ordenado para busca binária.\n");
}


// Função para Buscar Item no Vetor (Busca Binária)
void buscarBinariaVetor(Item vetor[], int totalItens) {
    char itemAlvo[30];
    int inicio = 0, fim = totalItens - 1, meio;
    comparacoesBusca = 0;
    printf("Qual o nome do item que deseja buscar de forma binária?: "); fgets(itemAlvo, 30, stdin); itemAlvo[strcspn(itemAlvo, "\n")] = 0;

    while (inicio <= fim) {
        comparacoesBusca++;
        meio = (inicio + fim) / 2;
        int resultadoComparacao = strcasecmp(vetor[meio].nome, itemAlvo);
        if (resultadoComparacao == 0) {
            printf("[DADO LOCALIZADO] Item detectado após %d varreduras no sistema de forma binária.\n", comparacoesBusca);
            return;
        } else if (resultadoComparacao < 0) inicio = meio + 1;
        else fim = meio - 1;
    }
    printf("[ERRO DE RASTREIO] Após %d varreduras no sistema, o item não foi localizado no inventário.\n", comparacoesBusca);
}

// Função para Remover Item do Vetor
void removerVetor(Item vetor[], int *totalItens) {
    char itemAlvo[30];
    printf("Informe o nome do item para descarte: "); fgets(itemAlvo, 30, stdin); itemAlvo[strcspn(itemAlvo, "\n")] = 0;
    for (int i = 0; i < *totalItens; i++) {
        if (strcasecmp(vetor[i].nome, itemAlvo) == 0) {
            for (int j = i; j < (*totalItens) - 1; j++) vetor[j] = vetor[j+1];
            (*totalItens)--;
            printf("Item descartado com sucesso!\n");
            return;
        }
    }
}

// --- IMPLEMENTAÇÃO LISTA ENCADEADA ---

// Função para Inserir Item na Lista Encadeada
void inserirLista(No** primeiroItem) {
    No* novo = (No*)malloc(sizeof(No));
    printf("Nome do item: "); fgets(novo->dados.nome, 30, stdin); novo->dados.nome[strcspn(novo->dados.nome, "\n")] = 0;
    printf("Tipo do item: "); fgets(novo->dados.tipo, 20, stdin); novo->dados.tipo[strcspn(novo->dados.tipo, "\n")] = 0;
    printf("Qtd do item: "); scanf("%d", &novo->dados.quantidade); 
    getchar();
    novo->proximo = *primeiroItem;
    *primeiroItem = novo;
    printf("Item registrado com sucesso no banco de dados da lista encadeada!\n");
}