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

    int *leftTemp = (int *)malloc(leftLength * sizeof(int));
    int *rightTemp = (int *)malloc(rightLength * sizeof(int));

    int i, j, k;
    for (i = 0; i < leftLength; i++) {
        leftTemp[i] = array[i + left];
    }

    for (i = 0; i < rightLength; i++) {
        rightTemp[i] = array[i + mid + 1];
    }

    for (i = 0, j = 0, k = left; k <= right; k++) {
        if ((i < leftLength) && (j >= rightLength || leftTemp[i] < rightTemp[j])) {
            array[k] = leftTemp[i];
            i++;
        } else {
            array[k] = rightTemp[j];
            j++;
        }
    }

    free(leftTemp);
    free(rightTemp);
}

int main (int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);

    for (int i = 1; i <= tc; i++) {
        int length;
        scanf("%d", &length);

        int *array = (int *)malloc(length * sizeof(int));
        for (int j = 0; j < length; j++) {
            scanf("%d", &array[j]);
        }

        call(array, length);

        int lengthTemp = length / 2;

        int rightDiff = 0;
        int leftDiff = 0;

        for (int j = 1; j < lengthTemp; j++) {
            if (j == 1 || array[j] - array[j - 1] > leftDiff) {
                leftDiff = array[j] - array[j - 1];
            } 
        }     

        for (int j = lengthTemp + 1; j < length; j++) {
            if (j == lengthTemp + 1 || array[j] - array[j - 1] > rightDiff) {
                rightDiff = array[j] - array[j - 1];
            }
        }

        printf("Case #%d: %d\n", i, (leftDiff > rightDiff) ? leftDiff : rightDiff);

        free(array);
    }
        
    return 0;
}