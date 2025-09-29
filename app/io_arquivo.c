#include <stdio.h>
#include <string.h>
#define TAM_MAX_STR 20 

int lerArquivo(char[] path_entrada, char[1000][TAM_MAX_STR] arr_gravacao) {
    FILE *entrada = fopen(path_entrada, "r");
    if(entrada == NULL) {
        printf("Erro na abertura do arquivo de entrada! Confira o path: ");
        printf(path_entrada);
        printf("\n");
        return -1;
    }

    for(int i=0; i<1000; i++) {
        char[TAM_MAX_STR] palavra;

        // É preciso colocar o \0 aqui??? 
        fgets(palavra, TAM_MAX_STR, entrada);

        if(palavra == null){
            printf("Erro ao ler uma palavra em %s", path_entrada);
            return -2;
        }

        arr_gravacao[i] = palavra;
    }

    fclose(entrada);
    return 0;
}

int gravarArquivo(char path_saida[], char arr_ordenado[1000][TAM_MAX_STR]) {
    FILE *saida = fopen(path_saida, "w");
    
    if(saida == NULL) {
        printf("Erro na abertura do arquivo de saída! Confira o path: ");
        printf(path_saida);
        printf("\n");

        return -1;
    }

    
    for(int i = 0; i<1000; i++){
        fprintf(saida,"%s\n",arr_ordenado[i]);
    }
}


int main() {
    // Testando leitura de in:
    char in[] = "/home/theo-esposito/VSCodeProjects/sorting-comparison/io/in.txt";
    char arr [TAM_MAX_STR][1000];

    lerArquivo(in, )
    return 0;
}