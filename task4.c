#include <stdio.h>
#include <string.h>
#include <math.h>
#define max_line_length 100
#define max_quantity_of_numbers 100
int sgn(int a) {
    if (a < 0) {
        return -1;
    }
    if (a == 0) {
        return 0;
    }
    return 1;
}
int good_array(int *array, int size) {
    int flag = 1;
    int signum = 0;
    int temp = 0;
    if (size == 1) {
        return flag;
    }
    signum = sgn(array[1] - array[0]);
    for (int i = 0; i < size - 1; i++) {
        temp = array[i + 1] - array[i];
        if (signum != sgn(temp) || fabs(temp) >3 || fabs(temp) < 1) {
            flag = 0;
        }
    }
    return flag;
}
int practically_good_array(int *array, int size) {
    int flag = 0;
    int temp[size - 1];
    if (size == 1) {
        return 1;
    }
    for (int i = 0; i < size; i++) {
        int t = 0;
        for (int j = 0; j < size - 1; j++) {
            if (j == i) {
                t++;
            }
            temp[j] = array[t];
            t++;
        }
        if (good_array(temp, size - 1) == 1) {
            flag = 1;
        }
    }
    return flag;
}
int main(int argc, char *argv[])
{
    int *A = NULL;
    int ans = 0;
    int cnt = 0;
    char line[max_line_length];
    int array[max_quantity_of_numbers];
    int number = 0;
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
    while (fgets(line, max_line_length, input) != NULL) { //читатет до \n 
        cnt = 0;
        char *token = strtok(line, " \t\n");   //разбивает строку на токены
        while (token != NULL) {
            if (sscanf(token, "%d", &number) == 1) { //преобразует токены в число
                array[cnt] = number;
                cnt++;
            }
            token = strtok(NULL, " \t\n");
        }
        ans += practically_good_array(array, cnt);
    }
    printf("%d\n", ans);
    fclose(input);
    return 0;
}