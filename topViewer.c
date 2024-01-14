#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Data {
    char title[1005];
    char name[1005];
    int view;
} Video;

Video videos[102];

int main(int argc, char *argv[]) {
    FILE *ptr = fopen("testdata.in", "r");
    int length = 0;

    while (!feof(ptr)) {
        fscanf(ptr, "%[^#]#%[^#]#%d\n", videos[length].title, videos[length].name, &videos[length].view);
        // fgetc(ptr);
        length++;
    }

    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if ((videos[j].view < videos[j + 1].view) || (videos[j].view == videos[j + 1].view && strcmp(videos[j].title, videos[j + 1].title) > 0)) {
                Video temp = videos[j];
                videos[j] = videos[j + 1];
                videos[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < length; i++) {
        printf("%s by %s - %d\n", videos[i].title, videos[i].name, videos[i].view);
    }
    
    fclose(ptr);

    return 0;
}