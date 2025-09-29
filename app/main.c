#include <stdio.h>
#include <string.h>
#define TAM_MAX_STR 20
#define QTDE_PALAVRAS 1000


/*
Esse arquivo vai ser o nosso grande cocozão, porque não sei como faz pra chamar funções de 
outros arquivos em C.

Portanto, vou jogar todas num arquivo só e foda-se
*/
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

// Merge Sort --------------------------------------------------------------------------------------
void merge_sort(char a[][TAM_MAX_STR], char tmp[][TAM_MAX_STR], int size){
    msort(a, tmp, 0, size - 1);
}

void msort(char a[][TAM_MAX_STR], char tmp[][TAM_MAX_STR], int left, int right){
    if (right > left)
    {
        int mid = (right + left) / 2;
        msort(a, tmp, left, mid);
        msort(a, tmp, mid + 1, right);
        merge(a, tmp, left, mid + 1, right);
    }
}

void merge(char a[][TAM_MAX_STR], char tmp[][TAM_MAX_STR], int left, int mid, int right){
    int left_end = mid - 1;
    int tmp_pos = left;
    int count = right - left + 1;

    while (left <= left_end && mid <= right)
    {
        if (strcmp(a[left], a[mid]) <= 0)
            strcpy(tmp[tmp_pos++], a[left++]);
        else
            strcpy(tmp[tmp_pos++], a[mid++]);
    }

    while (left <= left_end)
        strcpy(tmp[tmp_pos++], a[left++]);

    while (mid <= right)
        strcpy(tmp[tmp_pos++], a[mid++]);

    for (int i = 0; i < count; i++, right--)
        strcpy(a[right], tmp[right]);
}
//--------------------------------------------------------------------------------------------------

// Função utilitária
void copiar_arr(char destino[QTDE_PALAVRAS][TAM_MAX_STR], char origem[QTDE_PALAVRAS][TAM_MAX_STR]){
    for(int i=0; i<100; i++){
        strcpy(destino[i], origem[i]);
    }
}


// Bloco principal
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
    gravarArquivo("/workspaces/sorting-comparison/io/out1.txt", arr_merge);




    // Array auxiliar para o merge sort
    char temp[QTDE_PALAVRAS][TAM_MAX_STR];
    
    printf("Ordenando com Merge Sort...\n");
    merge_sort(arr_merge, temp, QTDE_PALAVRAS);

    gravarArquivo("/workspaces/sorting-comparison/io/out2.txt", arr_merge);

    return 0;
}