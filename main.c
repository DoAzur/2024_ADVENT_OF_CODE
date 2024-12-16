#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void read_arrays(FILE *input, int **A, int**B, int *size)
{
    int length = 1; //текущее выделение памяти относительно длины length
    int t = 2;
    int element_A = 0;
    int element_B = 0;
    *size = 0; //длина итогого массива
    *A = malloc(length * sizeof(int));
    *B = malloc(length * sizeof(int));
    t = fscanf(input, "%d %d", &element_A, &element_B);
    while (t == 2) {
        if (*size >= length) {
            length *= 2;
            int *temp1 = realloc(*A, length * sizeof(int));
            *A = temp1;
            int *temp2 = realloc(*B, length * sizeof(int));
            *B = temp2;
        }
        (*A)[*size] = element_A;
        (*B)[*size] = element_B;
        (*size)++;
        t = fscanf(input, "%d %d", &element_A, &element_B);
    }
}
void buble_sort(int *array, int size){
    int temp;
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - 1; j++){
            if (array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
int main(void)
{
    int *A = NULL;
    int *B = NULL;
    int size = 0;
    int ans = 0;
    FILE *input = NULL;
    input = fopen("data1.txt", "r");
    if (input == NULL) {
        printf("error\n");
        return -1;
    }
    read_arrays(input, &A, &B, &size);
    fclose(input);
    buble_sort(A, size);
    buble_sort(B, size);
    for (int i = 0; i < size; i++){
        ans += fabs(A[i] - B[i]);
    }
    printf("%d\n", ans);
    return 0;
}