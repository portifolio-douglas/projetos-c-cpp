#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "forca.h"


// Variáveis globais
char palavra_secreta[TAMANHO_PALAVRA];
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

    int erros = chutes_errados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros >= 1 ? '(':' '), (erros >= 1 ? '_':' '), (erros >= 1 ? ')':' '));
    printf(" |      %c%c%c  \n", (erros >= 3 ? '\\':' '), (erros >= 2 ? '|':' '), (erros >= 3 ? '/':' '));
    printf(" |       %c     \n", (erros >= 2 ? '|':' '));
    printf(" |      %c %c   \n", (erros >= 4 ? '/':' '), (erros >= 4 ? '\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

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


int chutes_errados () {
    int erros = 0;
    for (int i = 0; i < chutes_dados; i++) {

        int existe = 0;
        for (int j = 0; j < strlen(palavra_secreta); j++) {
            if (chutes[i] == palavra_secreta[j]){

                existe = 1;
                break;
            }
        }

        if (!existe) erros++;
        
    }

    return erros;
}


int enforcou() {
    return chutes_errados() >= 5;
}


void adiciona_palavra() {
    
    char quer;
    
    printf("Deseja adicionar uma nova palavra? (S/N) ");
    scanf(" %c", &quer);

    if (quer == 'S') {
    
        char novapalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra? ");
        scanf("%s", novapalavra);

        FILE* f;

        f = fopen("palavras.txt", "r+");
        if (f == 0) {
            printf("Banco de dados não disponível.\n");
            exit(1);
        }

        int qtde;
        fscanf(f, "%d", &qtde);
        qtde++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtde);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);

        printf("Nova palavra adicionada!\n");

    } else {
        printf("Encerrando...\n");
    }
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

    printf("%s\n", palavra_secreta);

    if(acertou()) {
        printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

    } else {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavra_secreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf(" /                   \\     \n");
        printf(" |   XXXX     XXXX   |     \n");
        printf(" |   XXXX     XXXX   |      \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }

    adiciona_palavra();

}
