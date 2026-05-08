// Desafio Código da Ilha – Edição Free Fire
// Nível Novato: Inventário Básico

// Objetivo: Desenvolver, em linguagem C, um sistema básico de inventário (mochila), com quantidade máxima de itens definida, utilizando estruturas de dados compostas (structs) e listas sequenciais. O sistema deve permitir ao jogador:
// 1. Coletar itens e adicioná-los à mochila
// 2. Listar os itens armazenados
// 3. Buscar itens específicos no inventário
// 4. Remover itens da mochila

// Bibliotecas necessárias 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constante para definir a capacidade máxima da mochila
#define MAX_ITENS 10

// Definição da struct Item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Protótipos das funções para modularização
void inserirItem(Item mochila[], int *total);
void removerItem(Item mochila[], int *total);
void listarItens(Item mochila[], int total);
void buscarItem(Item mochila[], int total);

// Função principal
int main() {
    // Declaração da mochila e controle dos itens
    Item mochila[MAX_ITENS]; 
    int totalItens = 0;      
    int opcao;

    // Loop principal do menu
    do {
        printf("\n--- MENU DE INVENTARIO: FREE FIRE ---\n");
        printf("1. Inserir Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Mochila\n");
        printf("4. Buscar Item\n");
        printf("0. Sair\n");
        printf("Escolha uma ação: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        // Processamento da opção escolhida utilizando switch-case
        switch(opcao) {
            case 1: inserirItem(mochila, &totalItens); break;
            case 2: removerItem(mochila, &totalItens); break;
            case 3: listarItens(mochila, totalItens); break;
            case 4: buscarItem(mochila, totalItens); break;
            case 0: printf("Saindo do jogo...\n"); break;
            default: printf("Ação inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}

// Funcao para inserir novos itens na mochila
void inserirItem(Item mochila[], int *total) {
    if (*total < MAX_ITENS) {
        printf("\nNome do item: ");
        fgets(mochila[*total].nome, 30, stdin);
        mochila[*total].nome[strcspn(mochila[*total].nome, "\n")] = 0; // Remove o \n

        printf("Tipo (arma/municao/cura/protecao): ");
        fgets(mochila[*total].tipo, 20, stdin);
        mochila[*total].tipo[strcspn(mochila[*total].tipo, "\n")] = 0;

        printf("Quantidade: ");
        scanf("%d", &mochila[*total].quantidade);
        getchar();

        (*total)++;
        printf("Item coletado com sucesso!\n");
        listarItens(mochila, *total);
    } else {
        printf("\n[AVISO] Mochila cheia! Jogue algo fora para liberar espaço.\n");
    }
}

// Funcao para listar todos os itens atuais
void listarItens(Item mochila[], int total) {
    printf("\n--- SUA MOCHILA ATUAL (%d/%d) ---\n", total, MAX_ITENS);
    if (total == 0) {
        printf("Mochila vazia.\n");
    } else {
        for (int i = 0; i < total; i++) {
            printf("[%d] %-20s | Tipo: %-15s | Qtd: %4d\n", i+1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
        }
    }
}

