#include <stdio.h>
#include <stdlib.h>
#define LENGTH 25

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
    int tc;
    scanf("%d", &tc);

    for (int i = 1; i <= tc; i++) {
        int *array = (int *)malloc(LENGTH * sizeof(int));

        for (int j = 0; j < LENGTH; j++) {
            scanf("%d", &array[j]);
        }

        call(array, LENGTH);
        
        int *result = (int *)malloc(5 * sizeof(int));
        result[0] = array[0] / 2;
        result[4] = array[24] / 2;
        result[1] = array[1] - result[0];
        result[3] = array[23] - result[4];

        for (int j = 0; j < 5; j++) {
            if (j == 2) {
                continue;
            }

            for (int k = 0; k < 5; k++) {
                if (k == 2) {
                    continue;
                }

                int total = result[j] + result[k];
                for (int l = 0; l < LENGTH; l++) {
                    if (total == array[l]) {
                        array[l] = -1;
                        break;
                    }
                }
            }
        }

        for (int l = 0; l < LENGTH; l++) {
            if (array[l] != -1) {
                result[2] = array[l] - result[0];
                break;
            }
        }

        printf("Case #%d: %d %d %d %d %d\n", i, result[0], result[1], result[2], result[3], result[4]);

        free(result);
        free(array);
    }
    
    return 0;
}