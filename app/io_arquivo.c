#include <stdio.h>
#include <string.h>
#define TAM_MAX_STR 20 

void lerArquivo(FILE *entrada, char[1000][TAM_MAX_STR] arr_gravacao) {
    if(entrada == NULL) {
        printf("Erro na abertura do arquivo de entrada\n");
        return;
    }

    char[TAM_MAX_STR] palavra;
    for(int i=0; i<1000; i++) {
        fread(entrada);
        arr_gravacao[i] = byte;
    }
}

void gravarArquivo(FILE *saida, char[1000][TAM_MAX_STR] arr_ordenado) {
    if(saida == NULL) {
        printf("Erro na abertura do arquivo de saída\n");
        return;
    }
gis tt

}


int main() {

    return 0;
}