#include <stdio.h>

int main()
{
    int tabuleiro[10][10] = {0}; // Inicia a matriz com 0

    // Posição do navio na horizontal
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;

    // Posição do navio na vertical
    tabuleiro[5][0] = 3;
    tabuleiro[6][0] = 3;
    tabuleiro[7][0] = 3;

    // Posição do navio 1 na diagonal
    tabuleiro[2][8] = 3;
    tabuleiro[3][7] = 3;
    tabuleiro[4][6] = 3;

    // Posição do navio 2 na diagonal
    tabuleiro[6][8] = 3;
    tabuleiro[7][7] = 3;
    tabuleiro[8][6] = 3;

    // Verificando se há sobreposição de navios
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (tabuleiro[i][j] > 3)
            {
                printf("Erro: Sobreposição de navios na posição (%d,%d)\n", i, j);
                return 1;
            }
        }
    }

    // Colunas da matriz com letras de A a J
    printf("   "); // Espaço para alinhar as letras com  os números de cada coluna
    for (int j = 0; j < 10; j++)
    {
        printf("%c ", 'A' + j); // Converte números em strings de A a J (0-9)
    }
    printf("\n"); // Quebra de linha após finalizar a conversão

    // Numeração das linhas de 1 a 10
    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", i + 1);       // Adiciona largura mínima de dois dígitos à esquerda e um espaço à direita do tabuleiro iniciando a primeira linha com número 1
        for (int j = 0; j < 10; j++) // Percorre as colunas
        {
            printf("%d ", tabuleiro[i][j]); // Imprime o valor da posição dos navios
        }
        printf("\n"); // Quebra de linha após cada linha do tabuleiro
    }

    return 0;
}