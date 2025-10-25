#include <stdio.h>
#include <string.h>

#define QTDE_PALAVRAS 10000
#define TAM_MAX_STR 20

long contador_passos = 0; //contador global

void merge(char a[][TAM_MAX_STR], char tmp[][TAM_MAX_STR], int left, int mid, int right);
void msort(char a[][TAM_MAX_STR], char tmp[][TAM_MAX_STR], int left, int right);
void merge_sort(char a[][TAM_MAX_STR], char tmp[][TAM_MAX_STR], int size);

void merge_sort(char a[][TAM_MAX_STR], char tmp[][TAM_MAX_STR], int size){
    contador_passos = 0; //zera antes de começar
    msort(a, tmp, 0, size - 1);
    printf("\nTotal de passos do merge: %ld\n", contador_passos);
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
        contador_passos++; //conta a comparação
        if (strcmp(a[left], a[mid]) <= 0)
            strcpy(tmp[tmp_pos++], a[left++]);
        else
            strcpy(tmp[tmp_pos++], a[mid++]);
        contador_passos++; //conta a copia
    }

    while (left <= left_end){
        strcpy(tmp[tmp_pos++], a[left++]);
        contador_passos++;
    }

    while (mid <= right){
        strcpy(tmp[tmp_pos++], a[mid++]);
        contador_passos++;
    }

    for (int i = 0; i < count; i++, right--){
        strcpy(a[right], tmp[right]);
        contador_passos++;
    }
}
