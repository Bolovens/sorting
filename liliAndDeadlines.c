#include <stdio.h>
#include <string.h>

typedef struct Schedule {
    char subject[11];
    long long int dueDate;
} Deadline;

Deadline subjects[100];

int main(int argc, char *argv[]) {
    int length;
    scanf("%d", &length);

    for (int i = 0; i < length; i++) {
        scanf("%s %lld", &subjects[i].subject, &subjects[i].dueDate);
    }

    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (subjects[j].dueDate > subjects[j + 1].dueDate || (subjects[j].dueDate == subjects[j + 1].dueDate && strcmp(subjects[j].subject, subjects[j + 1].subject) > 0)) {
                Deadline temp = subjects[j];
                subjects[j] = subjects[j + 1];
                subjects[j + 1] = temp;
            } 
        }
    }

    for (int i = 0; i < length; i++) {
        printf("%s\n", subjects[i].subject);
    }
    
    return 0;
}