#include <stdio.h>

void call(int array[], int length);
void divide(int array[], int left, int right);
void merge(int array[], int left, int mid, int right);

void call(int array[], int length) {
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

    int tempLeft[leftLength], tempRight[rightLength];

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
        int length;
        scanf("%d", &length);

        int array[length];
        double mean = 0;
        for (int j = 0; j < length; j++) {
            scanf("%d", &array[j]);
            mean += array[j];
        }

        call(array, length);

        double median;
        if (length % 2 != 0) {
            median = array[(length - 1) / 2];
        } else {
            median = (double) (array[(length - 1) / 2] + array[length / 2]) / 2;
        }

        printf("Case #%d:\n", i);
        printf("Mean : %.2lf\n", mean / length);
        printf("Median : %.2lf\n", median);
    }
    
    return 0;
}