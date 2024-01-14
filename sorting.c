#include <stdio.h>
#include <stdlib.h>

void sort(int array[], int length);
void divide(int array[], int left, int right);
void merge(int array[], int left, int mid, int right);

void sort(int array[], int length) {
    divide(array, 0, length - 1);
}

void divide(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        divide(array, left, mid);
        divide(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

void merge(int array[], int left, int mid, int right) {
    int leftLength = mid - left + 1;
    int rightLength = right - mid;

    int tempLeft[leftLength];
    int tempRight[rightLength];

    int i, j, k;
    for (i = 0; i < leftLength; i++) {
        tempLeft[i] = array[left + i];
    }

    for (i = 0; i < rightLength; i++) {
        tempRight[i] = array[mid + i + 1];
    }

    for (i = 0, j = 0, k = left; k <= right; k++) {
        if ((i < leftLength) && (j >= rightLength || tempLeft[i] <= tempRight[j])) {
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

    int array[length];
    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]);
    }

    sort(array, length);

    int difference = 0, count = 0;
    for (int i = 1; i < length; i++) {
        if (difference < array[i] - array[i - 1]) {
            difference = abs(array[i] - array[i - 1]);
        }
    }
    
    for (int i = 1; i < length; i++) {
        if (difference == abs(array[i] - array[i - 1])) {
            if (count == 0) {
                printf("%d %d", array[i - 1], array[i]);
            } else {
                printf(" %d %d", array[i - 1], array[i]);
            }
            count++;
        }
    }
    printf("\n");

    return 0;
}