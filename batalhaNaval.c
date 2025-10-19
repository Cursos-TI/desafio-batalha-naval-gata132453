#include <stdio.h>
#include <stdbool.h>

#define SIZE 10 // Tamanho do tabuleiro 10x10
int tabuleiro[SIZE][SIZE] = {{0}}; // Inicializa o tabuleiro com água (0)

// Função para exibir o tabuleiro
void exibirTabuleiro() {
    printf("\nTabuleiro Atual:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(" ~ "); // Água
            } else if (tabuleiro[i][j] == 3) {
                printf(" # "); // Navio
            } else if (tabuleiro[i][j] == 1) {
                printf(" ~ "); // Água atacada
            } else if (tabuleiro[i][j] == 2) {
                printf(" X "); // Navio atingido
            }
        }
        printf("\n");
    }
}

// Função para atacar
bool atacar(int linha, int coluna) {
    if (linha < 0 || linha >= SIZE || coluna < 0 || coluna >= SIZE) {
        printf("Coordenadas fora do tabuleiro. Tente novamente.\n");
        return false;
    }

    if (tabuleiro[linha][coluna] == 3) {
        tabuleiro[linha][coluna] = 2; // Navio atingido
        printf("Ataque bem-sucedido! Você atingiu um navio!\n");
        return true;
    } else if (tabuleiro[linha][coluna] == 0) {
        tabuleiro[linha][coluna] = 1; // Água atacada
        printf("Água atacada! Tente novamente.\n");
        return false;
    }
    return false;
}

// Função para verificar se todos os navios foram afundados
bool verificarVitoria() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (tabuleiro[i][j] == 3) { // Se algum navio não foi atingido
                return false;
            }
        }
    }
    return true; // Todos os navios foram afundados
}

int main() {
    int linha, coluna;
    bool vitoria = false;

    // Inicializando os navios no tabuleiro
    tabuleiro[2][2] = 3; // Navio 1 na posição (2,2)
    tabuleiro[4][4] = 3; // Navio 2 na posição (4,4)
    tabuleiro[5][1] = 3; // Navio 3 na posição (5,1)
    tabuleiro[7][8] = 3; // Navio 4 na posição (7,8)

    // Exibir o tabuleiro inicial
    exibirTabuleiro();

    // Loop do jogo
    while (!vitoria) {
        printf("\nDigite as coordenadas de ataque (linha e coluna): ");
        scanf("%d %d", &linha, &coluna);

        // Realizar o ataque
        if (atacar(linha, coluna)) {
            printf("Você acertou!\n");
        } else {
            printf("Você errou! Tente novamente.\n");
        }

        // Exibir o tabuleiro após cada ataque
        exibirTabuleiro();
        
        // Verificar a condição de vitória
        vitoria = verificarVitoria();
    }

    // Final do jogo
    printf("\nParabéns! Você venceu o jogo, todos os navios foram afundados.\n");

    return 0;
}
