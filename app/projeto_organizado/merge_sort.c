#include <stdio.h>
#include <string.h>

#define QTDE_PALAVRAS 1000
#define TAM_MAX_STR 20

void merge(char a[][TAM_MAX_STR], char tmp[][TAM_MAX_STR], int left, int mid, int right);
void msort(char a[][TAM_MAX_STR], char tmp[][TAM_MAX_STR], int left, int right);
void merge_sort(char a[][TAM_MAX_STR], char tmp[][TAM_MAX_STR], int size);

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
