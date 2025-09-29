// https://github.com/ThEsposito/bmp-compressor/blob/main/Proj2_Compactacao_BMP_v2.c

#include <stdio.h>
#include <string.h>

// Define o tamanho do vetor de strings e o tamanho máximo de cada string
#define SIZE 1000
#define MAX_LEN 100

void merge(char a[][MAX_LEN], char tmp[][MAX_LEN], int left, int mid, int right);
void msort(char a[][MAX_LEN], char tmp[][MAX_LEN], int left, int right);
void merge_sort(char a[][MAX_LEN], char tmp[][MAX_LEN], int size);

int main() {

    //TROCAR AQUI PELA LEITURA DO ARQUIVO ---------------------------------
    char a[SIZE][MAX_LEN] = {
        "tigre", "leao", "macaco", "girafa", "zebra"
    };
    char tmp[SIZE][MAX_LEN];

    int n = 5; // quantidade de strings preenchidas

    printf("Antes:\n");
    for (int i = 0; i < n; i++) printf("%s ", a[i]);
    printf("\n");


    //quais parametros passar-----------------------------
    merge_sort(a, tmp, n);

    printf("Depois:\n");
    for (int i = 0; i < n; i++) printf("%s ", a[i]);
    printf("\n");

    return 0;
}

void merge_sort(char a[][MAX_LEN], char tmp[][MAX_LEN], int size)
{
    msort(a, tmp, 0, size - 1);
}

void msort(char a[][MAX_LEN], char tmp[][MAX_LEN], int left, int right)
{
    if (right > left){
        int mid = (right + left) / 2;
        msort(a, tmp, left, mid);
        msort(a, tmp, mid + 1, right);
        merge(a, tmp, left, mid + 1, right);
    }
}

void merge(char a[][MAX_LEN], char tmp[][MAX_LEN], int left, int mid, int right)
{
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
