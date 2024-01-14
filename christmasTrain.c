#include <stdio.h>

int main(int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);

    for (int i = 1; i <= tc; i++) {
        int length, minute;
        scanf("%d %d", &length, &minute);

        int array[length];
        for (int j = 0; j < length; j++) {
            scanf("%d", &array[j]);
        }

        int count = 0;
        for (int j = 0; j < length - 1; j++) {
            for (int k = 0; k < length - j - 1; k++) {
                if (array[k] > array[k + 1]) {
                    int temp = array[k];
                    array[k] = array[k + 1];
                    array[k + 1] = temp;
                    count += minute;
                }
            }
        }

        printf("Case #%d: %d\n", i, count);
    }
    
    return 0;
}