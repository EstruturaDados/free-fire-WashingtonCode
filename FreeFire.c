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
