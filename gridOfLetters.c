#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortString(char string[205], int length);
void divideString(char string[205], int left, int right);
void mergeString(char string[205], int left, int mid, int right);

void sortString(char string[205], int length) {
    divideString(string, 0, length - 1);
}

void divideString(char string[205], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        divideString(string, left, mid);
        divideString(string, mid + 1, right);

        mergeString(string, left, mid, right);
    }
}

void mergeString(char string[205], int left, int mid, int right) {
    int leftLength = mid - left + 1;
    int rightLength = right - mid;

    char tempLeft[leftLength];
    char tempRight[rightLength];

    int i, j, k;
    for (i = 0; i < leftLength; i++) {
        tempLeft[i] = string[i + left];
    }

    for (i = 0; i < rightLength; i++) {
        tempRight[i] = string[i + mid + 1];
    }

    for (i = 0, j = 0, k = left; k <= right; k++) {
        if ((i < leftLength) && (j >= rightLength || tempLeft[i] < tempRight[j])) {
            string[k] = tempLeft[i];
            i++;
        } else {
            string[k] = tempRight[j];
            j++;
        }
    }
}

void sort(char **matrix, int length);
void divide(char **matrix, int left, int right);
void merge(char **matrix, int left, int mid, int right);

void sort(char **matrix, int length) {
    divide(matrix, 0, length - 1);
}

void divide(char **matrix, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        divide(matrix, left, mid);
        divide(matrix, mid + 1, right);

        merge(matrix, left, mid, right);
    }
}

void merge(char **matrix, int left, int mid, int right) {
    int leftLength = mid - left + 1;
    int rightLength = right - mid;

    char tempLeft[leftLength][205];
    char tempRight[rightLength][205];

    int i, j, k;
    for (i = 0; i < leftLength; i++) {
        strcpy(tempLeft[i], matrix[i + left]);
    }

    for (i = 0; i < rightLength; i++) {
        strcpy(tempRight[i], matrix[i + mid + 1]);
    }

    for (i = 0, j = 0, k = left; k <= right; k++) {
        if ((i < leftLength) && (j >= rightLength || strcmp(tempLeft[i], tempRight[j]) > 0)) {
            strcpy(matrix[k], tempLeft[i]);
            i++;
        } else {
            strcpy(matrix[k], tempRight[j]);
            j++;
        }
    }
}

int main(int argc, char *argv[]) {
    int row, column;
    scanf("%d %d", &row, &column);

    char **matrix = (char **)malloc(row * sizeof(char *));
    for (int i = 0; i < row; i++) {
        matrix[i] = (char *)malloc((column + 1) * sizeof(char));
        scanf("%s", matrix[i]);
        sortString(matrix[i], column);
    }

    sort(matrix, row);

    for (int i = 0; i < row; i++) {
        printf("%s\n", matrix[i]);
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}