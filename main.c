/*---------------------------------------------
Alunos:
 - Theo Espósito Simões Resende  RA: 10721356
 - Kauê Lima Rodrigues Meneses   RA: 10410594
----------------------------------------------*/

#include <stdio.h>
#include <string.h>
#define TAM_MAX_STR 30
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
        fgets(palavra, TAM_MAX_STR, entrada);

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
            cont++; // Incremento do contador para medir a quantidade de passos
            strcpy(arr[j+1], arr[j]);
            j--;
        }
        strcpy(arr[j+1], chave);
    }
    return cont;
}

// Merge Sort --------------------------------------------------------------------------------------
long contador_passos_merge = 0;

// Função principal do merge sort
void merge_sort(char a[][TAM_MAX_STR], char tmp[][TAM_MAX_STR], int size){
    contador_passos_merge = 0; // zera contador antes de começar
    msort(a, tmp, 0, size - 1);
}

// Função recursiva
void msort(char a[][TAM_MAX_STR], char tmp[][TAM_MAX_STR], int left, int right){
    if (right > left)
    {
        int mid = (right + left) / 2;
        msort(a, tmp, left, mid);
        msort(a, tmp, mid + 1, right);
        merge(a, tmp, left, mid + 1, right);
    }
}

// Função de mesclagem com contador
void merge(char a[][TAM_MAX_STR], char tmp[][TAM_MAX_STR], int left, int mid, int right){
    int left_end = mid - 1;
    int tmp_pos = left;
    int count = right - left + 1;

    while (left <= left_end && mid <= right)
    {
        contador_passos_merge++; // conta comparação
        if (strcmp(a[left], a[mid]) <= 0){
            strcpy(tmp[tmp_pos++], a[left++]);
            contador_passos_merge++; // conta cópia
        }
        else {
            strcpy(tmp[tmp_pos++], a[mid++]);
            contador_passos_merge++; // conta cópia
        }
    }

    while (left <= left_end){
        strcpy(tmp[tmp_pos++], a[left++]);
        contador_passos_merge++; //conta copia
    }

    while (mid <= right){
        strcpy(tmp[tmp_pos++], a[mid++]);
        contador_passos_merge++; //conta copia
    }

    for (int i = 0; i < count; i++, right--){
        strcpy(a[right], tmp[right]);
        contador_passos_merge++; //conta copia de volta para o array original
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
    char in[] = "./io/in.txt";
    char output_insertion[] = "./io/out1.txt";
    char output_merge[] = "./io/out2.txt";
    
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
    gravarArquivo(output_insertion, arr_insertion);
    
    printf("Insertion Sort: %d passos\n\n", qtde_passos_insertion);


    // Array auxiliar para o merge sort
    char temp[QTDE_PALAVRAS][TAM_MAX_STR];
    
    printf("Ordenando com Merge Sort...\n");
    
    merge_sort(arr_merge, temp, QTDE_PALAVRAS);

    printf("Gravando arquivo ordenado...\n");
    gravarArquivo(output_merge, arr_merge);

    //printando passos----------------------------------------
    printf("Merge Sort: %ld passos\n", contador_passos_merge);

    return 0;
}