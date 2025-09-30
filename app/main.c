/*---------------------------------------------
Alunos:
 - Theo Espósito Simões Resende  RA: 10721356
 - Kauê Lima Rodrigues Meneses   RA: 10410594
----------------------------------------------*/

#include <stdio.h>
#include <string.h>
#define TAM_MAX_STR 20
#define QTDE_PALAVRAS 10000

// ENTRADA E SAÍDA ---------------------------------------------------------------------------------
int lerArquivo(char path_entrada[50], char arr_gravacao[QTDE_PALAVRAS][TAM_MAX_STR]) {
    FILE *entrada = fopen(path_entrada, "r");
    if(entrada == NULL) {
        printf("Erro na abertura do arquivo de entrada! Confira o path: ");
        printf("%s", path_entrada);
        printf("\n");
        
        return -1;
    }

    for (int i = 0; i < QTDE_PALAVRAS; i++){
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

int gravarArquivo(char path_saida[], char arr_ordenado[QTDE_PALAVRAS][TAM_MAX_STR]){
    FILE *saida = fopen(path_saida, "w");
    if (saida == NULL) {
        printf("Erro na abertura do arquivo de saída! Confira o path: ");
        printf("%s", path_saida);
        printf("\n");

        return -1;
    }

    for (int i = 0; i < QTDE_PALAVRAS; i++){
        fprintf(saida, "%s", arr_ordenado[i]);
    }
    return 0;
}

//--------------------------------------------------------------------------------------------------

// A função retorna a quantidade de passos que o algoritmo levou para ser executado
int insertion_sort(char arr[QTDE_PALAVRAS][TAM_MAX_STR]){
    int cont = 0; // Contador para as repetições
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

// Merge Sort --------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r){
    
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Cria os subarrays temporários
    int L[n1], R[n2];

    // Copia os dados para os subarrays
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r){
    
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

//--------------------------------------------------------------------------------------------------

// Função utilitária
void copiar_arr(char destino[QTDE_PALAVRAS][TAM_MAX_STR], char origem[QTDE_PALAVRAS][TAM_MAX_STR]){
    for(int i=0; i<QTDE_PALAVRAS; i++){
        strcpy(destino[i], origem[i]);
    }
}


// Bloco principal
int main(){
    char in[] = "/home/theo-esposito/VSCodeProjects/sorting-comparison/io/in.txt";
    char output_insertion[] = "/home/theo-esposito/VSCodeProjects/sorting-comparison/io/out1.txt";
    char output_merge[] = "/home/theo-esposito/VSCodeProjects/sorting-comparison/io/out2.txt";
    
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
    printf("Gravando array ordenado do Insertion Sort...\n");
    gravarArquivo(output_insertion, arr_insertion);
    
    printf("Insertion Sort: %d passos\n\n", qtde_passos_insertion);


    // Array auxiliar para o merge sort
    char temp[QTDE_PALAVRAS][TAM_MAX_STR];
    
    printf("Ordenando com Merge Sort...\n");
    merge_sort(arr_merge,0, QTDE_PALAVRAS - 1);

    printf("Gravando array ordenado pelo Merge Sort no arquivo...\n");

    gravarArquivo(output_merge, arr_merge);

    return 0;
}