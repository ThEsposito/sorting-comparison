#include <stdio.h>
#include <string.h>
#define TAM_MAX_STR 20

int lerArquivo(char path_entrada[50], char arr_gravacao[1000][TAM_MAX_STR]) {
    FILE *entrada = fopen(path_entrada, "r");
    if(entrada == NULL) {
        printf("Erro na abertura do arquivo de entrada! Confira o path: ");
        printf("%s", path_entrada);
        printf("\n");
        
        return -1;
    }

    for (int i = 0; i < 1000; i++){
        char palavra[TAM_MAX_STR];

        // Vou manter o \n no final das strings porque vamos precisar dele depois
        if (fgets(palavra, TAM_MAX_STR, entrada) == NULL){
            printf("Erro ao ler uma palavra em %s", path_entrada);
            return -2;
        }
        strcpy(arr_gravacao[i], palavra);
    }

    fclose(entrada);
    return 0;
}

int gravarArquivo(char path_saida[], char arr_ordenado[1000][TAM_MAX_STR]){
    FILE *saida = fopen(path_saida, "w");
    if (saida == NULL) {
        printf("Erro na abertura do arquivo de saída! Confira o path: ");
        printf("%s", path_saida);
        printf("\n");

        return -1;
    }

    for (int i = 0; i < 1000; i++){
        fprintf(saida, "%s", arr_ordenado[i]);
    }
    return 0;
}

int main() {
// Testando leitura de in:
    char in[] = "/workspaces/sorting-comparison/io/in.txt";
    char arr[1000][TAM_MAX_STR];

    lerArquivo(in, arr);

    for (int i = 0; i < 1000; i++){
        printf("%s", arr[i]);
    }

    gravarArquivo("/workspaces/sorting-comparison/io/test.txt", arr);

    return 0;
}