#include <stdio.h>

int main() {
    // Quantidade de movimentos para cada peça
    const int movimentosTorre = 5;
    const int movimentosBispo = 5;
    const int movimentosRainha = 8;

    int i;

    // Movimento da Torre (5 casas para a direita) usando FOR
    printf("Movimento da Torre:\n");
    for (i = 1; i <= movimentosTorre; i++) {
        printf("Direita\n");
    }

    // Movimento do Bispo (5 casas na diagonal cima-direita) usando WHILE
    printf("\nMovimento do Bispo:\n");
    i = 1;
    while (i <= movimentosBispo) {
        printf("Cima Direita\n");
        i++;
    }

    // Movimento da Rainha (8 casas para a esquerda) usando DO-WHILE
    printf("\nMovimento da Rainha:\n");
    i = 1;
    do {
        printf("Esquerda\n");
        i++;
    } while (i <= movimentosRainha);

    return 0;
}
