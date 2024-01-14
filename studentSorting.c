#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct List {
    char id[11];
    char name[21];
} Student;

Student students[1001];

void call(Student students[1001], int length);
void divide(Student students[1001], int left, int right);
void merge(Student students[1001], int left, int mid, int right);

void call(Student students[1001], int length) {
    divide(students, 0, length - 1);
}

void divide(Student students[1001], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        divide(students, left, mid);
        divide(students, mid + 1, right);

        merge(students, left, mid, right);
    }
}

void merge(Student students[1001], int left, int mid, int right) {
    int leftLength = mid - left + 1;
    int rightLength = right - mid;

    Student tempLeft[leftLength];
    Student tempRight[rightLength];

    int i, j, k;
    for (i = 0; i < leftLength; i++) {
        tempLeft[i] = students[i + left];
    }

    for (i = 0; i < rightLength; i++) {
        tempRight[i] = students[i + mid + 1];
    }

    for (i = 0, j = 0, k = left; k <= right; k++) {
        if ((i < leftLength) && (j >= rightLength || strcmp(tempLeft[i].id, tempRight[j].id) <= 0)) {
            students[k] = tempLeft[i];
            i++;
        } else {
            students[k] = tempRight[j];
            j++;
        }
    }
}

int main(int argc, char *argv[]) {
    int length;
    FILE *ptr = fopen("testdata.in", "r");
    fscanf(ptr, "%d", &length);

    for (int i = 0; i < length; i++) {
        fscanf(ptr, "%s %s", students[i].id, students[i].name);
    }

    fclose(ptr);

    call(students, length);

    for (int i = 0; i < length; i++) {
        printf("%s %s\n", students[i].id, students[i].name);
    }
    
    return 0;
}