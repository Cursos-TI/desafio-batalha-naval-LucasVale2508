#include <stdio.h>
#include <stdlib.h> //Inclusão de biblioteca para adicionar a função abs()

// Troca dos valores fixos do tamanho do tabuleiro
#define LINHAS 10
#define COLUNAS 10
#define TAM_HABILIDADE 5


// Função para criar matriz de habilidade Cone (valor 1)
void criar_cone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE])
{
    for (int i = 0; i < TAM_HABILIDADE; i++)
    {
        for (int j = 0; j < TAM_HABILIDADE; j++)
        {
            habilidade[i][j] = (j >= i && j < TAM_HABILIDADE - i) ? 1 : 0;
        }
    }
}

// Função para criar matriz de habilidade Cruz (valor 3)
void criar_cruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE])
{
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++)
    {
        for (int j = 0; j < TAM_HABILIDADE; j++)
        {
            habilidade[i][j] = (i == centro || j == centro) ? 1 : 0;
        }
    }
}

// Função para criar matriz de habilidade Octaedro (valor 2)
void criar_octaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE])
{
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++)
    {
        for (int j = 0; j < TAM_HABILIDADE; j++)
        {
            int dist_i = abs(i - centro);
            int dist_j = abs(j - centro);
            habilidade[i][j] = (dist_i + dist_j <= centro) ? 1 : 0;
        }
    }
}

// Função para aplicar habilidade ao tabuleiro
void aplicar_habilidade(int tabuleiro[LINHAS][COLUNAS], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                        int linha_origem, int coluna_origem, int valor_hab)
{
    int offset = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++)
    {
        for (int j = 0; j < TAM_HABILIDADE; j++)
        {
            int linha_tab = linha_origem - offset + i;
            int coluna_tab = coluna_origem - offset + j;

            if (linha_tab >= 0 && linha_tab < LINHAS &&
                coluna_tab >= 0 && coluna_tab < COLUNAS &&
                habilidade[i][j] == 1)
            {
                tabuleiro[linha_tab][coluna_tab] = valor_hab;
            }
        }
    }
}

// Função para exibir as habilidades
void exibir_habilidades(int tabuleiro[LINHAS][COLUNAS])
{
    printf("   ");
    for (int j = 0; j < COLUNAS; j++)
    {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    for (int i = 0; i < LINHAS; i++)
    {
        printf("%2d ", i + 1);
        for (int j = 0; j < COLUNAS; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int tabuleiro[LINHAS][COLUNAS] = {0}; // Inicializa tudo com 0 (água)

    // Cria as matrizes de habilidade
    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    criar_cone(cone);
    criar_cruz(cruz);
    criar_octaedro(octaedro);

    // Aplica as habilidades ao tabuleiro
    aplicar_habilidade(tabuleiro, cone, 3, 4, 1);     // Cone (valor 1)
    aplicar_habilidade(tabuleiro, cruz, 6, 3, 3);     // Cruz (valor 3)
    aplicar_habilidade(tabuleiro, octaedro, 7, 7, 2); // Octaedro (valor 2)

     // Exibe apenas as habilidades
     printf("Mapa de Habilidades:\n");
     printf("0: Água | 1: Cone | 2: Octaedro | 3: Cruz\n\n");
     exibir_habilidades(tabuleiro);
 
     return 0;
 }

    