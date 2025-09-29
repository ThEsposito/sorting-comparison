#include <stdio.h>
#include <string.h>
#define TAM_MAX_STR 20
#define QTDE_PALAVRAS 1000

/*
Esse arquivo vai ser o nosso grande cocozão, porque não sei como faz pra chamar funções de 
outros arquivos em C.

Portanto, vou jogar todas num arquivo só e foda-se
*/

void copiar_arr(char destino[QTDE_PALAVRAS][TAM_MAX_STR], char origem[QTDE_PALAVRAS][TAM_MAX_STR]){
    for(int i=0; i<100; i++){
        strcpy(destino[i], origem[i]);
    }
}

int main(){
    char in[] = "/workspaces/sorting-comparison/io/in.txt";
    char output_merge[] = "/workspaces/sorting-comparison/io/out2.txt";
    char output_insertion[] = "/workspaces/sorting-comparison/io/out1.txt";

    char arr_insertion[QTDE_PALAVRAS][TAM_MAX_STR];
    // Leitura da entrada:
    lerArquivo(in, arr_insertion);

    // Como o insertion vai ordenar esse array, criei uma cópia para o merge utilizar
    char arr_merge[QTDE_PALAVRAS][TAM_MAX_STR];
    copiar_arr(arr_merge, arr_insertion);
    



    // Ordena e conta a quantidade de passos para a execução do Insertion Sort
    printf("Ordenando com Insertion Sort...\n");
    int qtde_passos_insertion = insertion_sort(arr_insertion);

    // Grava o array ordenado pelo Insertion em out1.txt
    printf("Gravando arquivo ordenado...\n");
    gravarArquivo("/workspaces/sorting-comparison/io/out1.txt", arr_insertion);
    
    printf("Insertion Sort: %d passos\n\n", qtde_passos_insertion);


    // Array auxiliar para o merge sort
    char temp[QTDE_PALAVRAS][TAM_MAX_STR];
    
    printf("Ordenando com Merge Sort...\n");
    merge_sort(arr_merge, temp, QTDE_PALAVRAS);

    gravarArquivo("/workspaces/sorting-comparison/io/out2.txt", arr_merge);

    return 0;
}