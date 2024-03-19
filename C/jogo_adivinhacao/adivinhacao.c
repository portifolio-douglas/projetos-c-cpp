#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    // imprime cabecalho do nosso jogo
    printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");
    
    srand(time(0));

    int numerosecreto = rand() % 100;

    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;
    
    int nivel;
    printf("Escolha a dificuldade:\n");
    printf("(1) Fácil  (2) Médio  (3) Difícil\n\n");
    printf("Sua escolha: ");
    scanf("%d", &nivel);

    int num_tentativas;
    switch (nivel) {
        case 1:
            num_tentativas = 20;
            break;
        
        case 2:
            num_tentativas = 15;
            break;
        
        default:
            num_tentativas = 6;
            break;
    }

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
    printf("Fim de jogo!\n");

    if (acertou) {
        printf("Parabéns! Você acertou em %d tentativas\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    } else {
        printf("Você perdeu! Tente de novo!\n");
    }
}
