#include <stdio.h>
#include <string.h>

typedef struct List {
    char city[1005];
    double temperature;
    char metric;
} City;

City cities[101];

int main(int argc, char *argv[]) {
    FILE *ptr = fopen("testdata.in", "r");

    int length = 0;
    while (!feof(ptr)) {
        fscanf(ptr, "%[^#]#%lf#%c\n", cities[length].city, &cities[length].temperature, &cities[length].metric);
        length++;
    }

    fclose(ptr);

    for (int i = 0; i < length - 1; i++) {
        for (int j = length - 1; j > i; j--) {
            double firstTemperature = cities[j].temperature;
            double secondTemperature = cities[j - 1].temperature;

            if (cities[j].metric == 'F') {
                firstTemperature = (firstTemperature - 32) * 5.0 / 9;
            }

            if (cities[j - 1].metric == 'F') {
                secondTemperature = (secondTemperature - 32) * 5.0 / 9;
            }
            
            if ((firstTemperature < secondTemperature) || ((firstTemperature == secondTemperature) && (strcmp(cities[j].city, cities[j - 1].city) < 0))) {
                City temp = cities[j];
                cities[j] = cities[j - 1];
                cities[j - 1] = temp;
            }
        }
    }

    for (int i = 0; i < length; i++) {
        printf("%s is %.2lf%c\n", cities[i].city, cities[i].temperature, cities[i].metric);
    }
    
    return 0;
}