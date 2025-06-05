#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo estrutura para armazenar os dados de uma carta
struct CartaSuperTrunfo {
    char estado;                  // Letra de A a H
    char codigo[4];              // Código da carta (ex: A01)
    char nomeCidade[100];       // Nome da cidade
    int populacao;              // População
    float area;                 // Área em km²
    float pib;                  // PIB
    int pontosTuristicos;      // Número de pontos turísticos
};

// Função para inserir os dados de uma carta
void inserirCarta(struct CartaSuperTrunfo *carta, int numeroCarta) {
    printf("\n--- Inserir dados da Carta %d ---\n", numeroCarta);

    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta->estado);

    printf("Código da Carta (ex: A01): ");
    scanf(" %3s", carta->codigo);

    printf("Nome da Cidade: ");
    getchar(); // Limpar o buffer do teclado
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = 0; // Remover o '\n'

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

// Função para exibir os dados de uma carta
void exibirCarta(struct CartaSuperTrunfo carta, int numeroCarta) {
    printf("\nCarta %d:\n", numeroCarta);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
}

int main() {
    struct CartaSuperTrunfo carta1, carta2;

    // Inserir dados das duas cartas
    inserirCarta(&carta1, 1);
    inserirCarta(&carta2, 2);

    // Exibir os dados
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    return 0;
}
