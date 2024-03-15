#include <stdio.h>

int main() {
    // imprime cabecalho do nosso jogo
    printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");

    int numerosecreto = 42;

    int chute;

    for (int i = 1; i <= 3; i++){
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);
        
        if(chute == numerosecreto) {
            
            printf("Parabéns! Você acertou!\n");
            printf("Jogue de novo, você é um bom jogador!\n");
            
            break;
        }

        else {
            
            if(chute > numerosecreto) {
                printf("Seu chute foi maior que o número secreto\n");
            }
            
            if(chute < numerosecreto) {
                printf("Seu chute foi menor que o número secreto\n");
            }
        }
    }
    printf("Fim de jogo!\n");
}
