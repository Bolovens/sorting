#include <stdio.h>
#include <string.h>

typedef struct Species {
    int id;
    char name[45];
} Plant;

Plant plants[1001];

void sort(Plant plants[1001], int length);
void divide(Plant plants[1001], int left, int right);
void merge(Plant plants[1001], int left, int mid, int right);

void sort(Plant plants[1001], int length) {
    divide(plants, 0, length - 1);
}

void divide(Plant plants[1001], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        divide(plants, left, mid);
        divide(plants, mid + 1, right);

        merge(plants, left, mid, right);
    }
}

void merge(Plant plants[1001], int left, int mid, int right) {
    int leftLength = mid - left + 1;
    int rightLength = right - mid; 

    Plant tempLeft[leftLength];
    Plant tempRight[rightLength];

    int i, j, k;
    for (i = 0; i < leftLength; i++) {
        tempLeft[i] = plants[i + left];
    }

    for (i = 0; i < rightLength; i++) {
        tempRight[i] = plants[mid + i + 1];
    }

    for (i = 0, j = 0, k = left; k <= right; k++) {
        if ((i < leftLength) && (j >= rightLength || strcmp(tempLeft[i].name, tempRight[j].name) <= 0)) {
            plants[k] = tempLeft[i];
            i++;
        } else {
            plants[k] = tempRight[j];
            j++;
        }
    }
   
}

int main(int argc, char *argv[]) {
    int length;
    FILE *ptr = fopen("testdata.in", "r");
    fscanf(ptr, "%d", &length);

    for (int i = 0; i < length; i++) {
        fscanf(ptr, "%d#%[^\n]s", &plants[i].id, plants[i].name);
    }

    fclose(ptr);

    sort(plants, length);

    for (int i = 0; i < length; i++) {
        printf("%d %s\n", plants[i].id, plants[i].name);
    }
    
    return 0;
}