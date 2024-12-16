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
int cnt_number(int number, int *array, int size)
{
    int cnt = 0;
    for(int i = 0; i < size; i++) {
        if (array[i] == number) {
            cnt += 1;
        }
    }
    return cnt;
}
int main(int argc, char *argv[])
{
    int *A = NULL;
    int *B = NULL;
    int size = 0;
    int ans = 0;
    FILE *input = NULL;
    if (argc != 2) {
        printf("error\n");
        return -1;
    }
    input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("error\n");
        return -1;
    }
    read_arrays(input, &A, &B, &size);
    fclose(input);
    for(int i = 0; i < size; i++) {
        ans += A[i] * cnt_number(A[i], B, size);
    }
    printf("%d ", ans);
    free(A);
    free(B);
    return 0;
}
