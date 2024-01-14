#include <stdio.h>
#include <stdlib.h>

void call(int *array, int length);
void divide(int *array, int left, int right);
void merge(int *array, int left, int mid, int right);
int search(int *array, int target, int left, int right);

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

    int *tempLeft = (int *)malloc(leftLength * sizeof(int));
    int *tempRight = (int *)malloc(rightLength * sizeof(int));

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

    free(tempLeft);
    free(tempRight);
}

int search(int *array, int target, int left, int right) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;
    if (array[mid] == target) {
        return mid + 1;
    } else if (array[mid] > target) {
        return search(array, target, left, mid - 1);
    } else if (array[mid] < target) {
        return search(array, target, mid + 1, right);
    }
}

int main(int argc, char *argv[]) {
    int length;
    scanf("%d", &length);

    int *line = (int *)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        scanf("%d", &line[i]);
    }

    call(line, length);

    int lengthCall;
    scanf("%d", &lengthCall);

    int *call = (int *)malloc(lengthCall * sizeof(int));
    for (int i = 0; i < lengthCall; i++) {
        scanf("%d", &call[i]);
    }

    for (int i = 0; i < lengthCall; i++) {
        int index = search(line, call[i], 0, length - 1);
        printf("%d\n", index);
    }

    free(line);
    free(call);
    
    return 0;
}