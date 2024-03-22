#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "forca.h"


// Variáveis globais
char palavra_secreta[20];
char chutes[26];
int chutes_dados = 0;


void abertura() {
    printf("****************\n");
    printf(" Jogo de Forca *\n");
    printf("****************\n\n");

}


void chuta() {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutes_dados] = chute;
    chutes_dados++;

}


int ja_chutou(char letra) {
    int achou = 0;
    
    for (int j = 0; j < chutes_dados; j++) {
        if (chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;

}


void desenha_forca() {
    for (int i = 0; i < strlen(palavra_secreta); i++) {

        int achou = ja_chutou(palavra_secreta[i]);

        if (achou) {
            printf("%c ", palavra_secreta[i]);
        } else {
            printf("_ ");
        }          
    }
    printf("\n");
}


int acertou() {
    for (int i = 0; i < strlen(palavra_secreta); i++) {
        if (!ja_chutou(palavra_secreta[i])) {
            return 0;
        }
    }

    return 1;
}


int enforcou() {
    int erros = 0;
    for (int i = 0; i < chutes_dados; i++) {

        int existe = 0;
        for (int j = 0; j< strlen(palavra_secreta); j++) {
            if (chutes[i] == palavra_secreta[j]){

                existe = 1;
                break;
            }
        }

        if (!existe) erros++;
        
    }

    return erros >= 5;
}


void escolhe_palavra() {
    FILE* f;
    
    f = fopen("palavras.txt", "r");
    if (f == 0) {
        printf("Banco de dados não disponível.");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);


    srand(time(0));
    int rand_num = rand() % qtddepalavras;

    for (int i = 0; i <= rand_num; i++) {
        fscanf(f, "%s", palavra_secreta);
    }

    fclose(f);
}


int main() {

    escolhe_palavra();
    abertura();

    do {

        desenha_forca();
        chuta();
                
    } while (!acertou() && !enforcou());

}
