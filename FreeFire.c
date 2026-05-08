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