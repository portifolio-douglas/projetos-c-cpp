/*
Em C é necessário compilar o arquivo antes de executá-lo

Os comandos são:

Compilar - gcc <nomedoarquivo>.c -o <nomedoarquivo>.out
Executar - ./<nomedoarquivo>.out
*/


#include <stdio.h>

// Constantes (variáveis "não variáveis", que seu valor não muda)
// Uma constante, por convenção, é declarada usando letras maiúsculas
#define NUMERO 5


int main() {

    // Declarar variáveis (declarar tipo)
    int numero = 42; // Usa 4 bytes de memória para armazenar um valor
    long numero; // "Irmão" do int que armazena números maiores (Usa 8 bytes de memória para armazenar um valor)
    short numero; // "Irmão" do int que armazena números menores (Usa 2 bytes de memória para armazenar um valor)
    int chute; // Variável sem valor para ser armazenada com 'scanf'
    double numero_decimal = 42.0; // Usa 8 bytes de memória para armazenar um valor
    float numero_decimal; // "Irmão" do double que armazena números menores (Usa 4 bytes de memória para armazenar um valor)

    char letra1 = 'A'; // Tipo para armazenar letras
    char letra1[10]; // Tipo para armazenar em arrays
    sprintf(letra1, "letra") // Função para armazenar letras/palavras/frases em uma variável

    // Imprime
    printf("Bem vindo ao nosso jogo de adivinhação!\n");

    // Imprime com valores
    // %d (Máscara de inteiro); %f (Máscara de decimal) -> %.(1)f o número entre () indica a quantidade de casas decimais a serem mostradas
    printf("%d é o número secreto. Não conta para ninguém!/n", numero);

    // %c (Máscara de char)
    printf("%c")

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

    switch (/* Equivalente ao (match) em python */) {
        case 1:
            /* Faça algo */
            break;

        default:
            /* Equivalente à 'case _:' */
            break; // SEMPRE usar o break, caso contrário o código continua a partir do caso selecionado
    }

    // ======================
    // Estrutura de repetição
    // ======================

    // Laço for

    for (int i = 1; i <=3, i++){
        /* Repete o código 3x */
    };
    
}
