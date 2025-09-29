#include <stdio.h>
#include <string.h>

#define TAM_MAX_STR 20
#define QTDE_PALAVRAS 1000

// Ele retorna a qtde de passos
int insertion_sort(char arr[QTDE_PALAVRAS][TAM_MAX_STR]){
    int cont = 0;
    for (int i = 1; i < QTDE_PALAVRAS; ++i) {
        char chave[TAM_MAX_STR];
        strcpy(chave, arr[i]);

        int j = i - 1;
        while (j >= 0 && strcmp(arr[j], chave) > 0) {
            cont++; // CONTADOR AQUI Ó
            strcpy(arr[j+1], arr[j]);
            j--;
        }
        strcpy(arr[j+1], chave);
    }
    return cont;
}