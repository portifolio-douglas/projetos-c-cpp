#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n          Bem vindo ao    \n");
    printf("     |_|_|nnnn nnnn|_|_|      Jogo de Adivinhação!\n");
    printf("    |" "  |  |_|  |"  " |                         \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");
    
    srand(time(0));

    int numerosecreto = rand() % 100;

    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;
    
    int nivel;

    int num_tentativas;
    do {
        printf("Escolha a dificuldade:\n");
        printf("(1) Fácil  (2) Médio  (3) Difícil\n\n");
        printf("Sua escolha: ");
        scanf("%d", &nivel);
        printf("\n");

        switch (nivel) {
        case 1:
            num_tentativas = 20;
            break;
        
        case 2:
            num_tentativas = 15;
            break;
        
        case 3:
            num_tentativas = 6;
            break;
        
        default:
            printf("Insira uma dificuldade válida!\n\n");
            break;
        }
    } while (nivel > 3);

    for (int i = 1; i <= num_tentativas; i++) {

        printf("Tentativa %d\n", tentativas);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);

        if (chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }
        printf("Seu chute foi %d\n", chute);

        acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;
        
        if(acertou) {
            break;
        }

        else if(maior) {
            printf("Seu chute foi maior que o número secreto\n");
        }

        else {
            printf("Seu chute foi menor que o número secreto\n");
        }

        tentativas++;

        double pontos_perdidos = abs(chute - numerosecreto) / 2.0;
        pontos -= pontos_perdidos;
        
    }
    printf("Fim de jogo!\n\n");

    if (acertou) {

        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");

        printf("Parabéns! Você acertou em %d tentativas\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    } else {
        
        printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
        printf("\n\n");

        printf("Você perdeu! Tente de novo!\n");
    }
}
