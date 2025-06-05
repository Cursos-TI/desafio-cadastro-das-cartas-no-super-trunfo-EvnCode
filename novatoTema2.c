#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
struct CartaSuperTrunfo {
    char estado;
    char codigo[4];
    char nomeCidade[100];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para inserir os dados de uma carta
void inserirCarta(struct CartaSuperTrunfo *carta, int numeroCarta) {
    printf("\n--- Inserir dados da Carta %d ---\n", numeroCarta);

    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta->estado);

    printf("Código da Carta (ex: A01): ");
    scanf(" %3s", carta->codigo);

    printf("Nome da Cidade: ");
    getchar(); // Limpar buffer
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = 0;

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Calcula densidade e PIB per capita
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1e9) / carta->populacao; // PIB em reais
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
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", carta.pibPerCapita);
}

// Função para comparar dois valores e imprimir o resultado
void compararCartas(struct CartaSuperTrunfo c1, struct CartaSuperTrunfo c2) {
    printf("\n--- Comparação de Cartas (Atributo: População) ---\n");
    printf("Carta 1 - %s (%c): %d habitantes\n", c1.nomeCidade, c1.estado, c1.populacao);
    printf("Carta 2 - %s (%c): %d habitantes\n", c2.nomeCidade, c2.estado, c2.populacao);

    if (c1.populacao > c2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nomeCidade);
    } else if (c2.populacao > c1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    // Para comparar outro atributo, substitua a lógica acima por outra, por exemplo:
    // - PIB: usar c1.pib e c2.pib
    // - Densidade Populacional: menor valor vence
    // - PIB per capita: maior valor vence
}

int main() {
    struct CartaSuperTrunfo carta1, carta2;

    // Cadastro das cartas
    inserirCarta(&carta1, 1);
    inserirCarta(&carta2, 2);

    // Exibir os dados
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Comparar cartas
    compararCartas(carta1, carta2);

    return 0;
}
