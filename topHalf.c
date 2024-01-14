#include <stdio.h>
#include <stdlib.h>

void call(int *array, int length);
void divide(int *array, int left, int right);
void merge(int *array, int left, int mid, int right);

void call(int *array, int length) {
    divide(array, 0, length - 1);
}

void divide(int *array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        divide(array, left, mid);
        divide(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

void merge(int *array, int left, int mid, int right) {
    int leftLength = mid - left + 1;
    int rightLength = right - mid;

    int tempLeft[leftLength];
    int tempRight[rightLength];

    int i, j, k;
    for (i = 0; i < leftLength; i++) {
        tempLeft[i] = array[i + left];
    }

    for (i = 0; i < rightLength; i++) {
        tempRight[i] = array[i + mid + 1];
    }

    for (i = 0, j = 0, k = left; k <= right; k++) {
        if ((i < leftLength) && (j >= rightLength || tempLeft[i] < tempRight[j])) {
            array[k] = tempLeft[i];
            i++;
        } else {
            array[k] = tempRight[j];
            j++;
        }
    }
}

int main(int argc, char *argv[]) {
    int length;
    scanf("%d", &length);

    int *array = malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]);
    }

    call(array, length);

    for (int i = length / 2 + 1; i < length; i++) {
        if (i == length / 2 + 1) {
            printf("%d", array[i]);
        } else {
            printf(" %d", array[i]);
        }
    }

    printf("\n");

    free(array);

    return 0;
}