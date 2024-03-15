#include <stdio.h>

int main() {

    // Declarar variáveis (declarar tipo)
    int numero = 42;
    int chute; // Variável sem valor para ser armazenada com 'scanf'
    float numero_flutuante = 42.0;

    // Imprime
    printf("Bem vindo ao nosso jogo de adivinhação!\n");

    // Imprime com valores
    printf("%d é o número secreto. Não conta para ninguém!/n", numero);

    // Lê do teclado (paralelo do 'input')
    scanf("%d", &chute);

    // =====================
    // Estrutura condicional
    // =====================

    // Condição if

    if (/* Condição */) {
        /* Faça algo */ 
    };

    else {
        /* Faça algo */ 
    };

    // ======================
    // Estrutura de repetição
    // ======================

    // Laço for

    for (int i = 1; i <=3, i++){
        /* Repete o código 3x */
    }
    
}
