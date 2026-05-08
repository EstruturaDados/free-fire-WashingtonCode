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

