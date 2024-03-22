#include <stdio.h>
#include <string.h>


void abertura() {

    printf("****************\n");
    printf(" Jogo de Forca *\n");
    printf("****************\n\n");

}


void chuta(char chutes[26], int* tentativas) {

    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[(*tentativas)] = chute;
    (*tentativas)++;

}


int jachutou(char letra, char chutes[26], int tentativas) {

    int achou = 0;
    
    for (int j = 0; j < tentativas; j++) {
        if (chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;

}


void desenha_forca(char palavra_secreta[20], char chutes[26], int tentativas) {

    for (int i = 0; i < strlen(palavra_secreta); i++) {

        int achou = jachutou(palavra_secreta[i], chutes, tentativas);

        if (achou) {
            printf("%c ", palavra_secreta[i]);
        } else {
            printf("_ ");
        }          
    }
    printf("\n");

}


void escolhe_palavra(char palavra_secreta[20]) {

    sprintf(palavra_secreta, "MELANCIA");

}


int main() {

    char palavra_secreta[20];

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    abertura();

    do {

        desenha_forca(palavra_secreta, chutes, tentativas);

        chuta(chutes, &tentativas);
                
    } while (!acertou && !enforcou);

    
}
