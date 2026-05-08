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

