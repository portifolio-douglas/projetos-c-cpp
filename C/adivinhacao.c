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

    while (1) {

        printf("Tentativa %d\n", tentativas);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);

        if (chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }
        printf("Seu chute foi %d\n", chute);

        int acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;
        
        if(acertou) {
            
            printf("Parabéns! Você acertou em %d tentativas\n", tentativas);
            printf("Jogue de novo, você é um bom jogador!\n");
            
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
    printf("Total de pontos: %.1f\n", pontos);
}
