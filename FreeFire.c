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


