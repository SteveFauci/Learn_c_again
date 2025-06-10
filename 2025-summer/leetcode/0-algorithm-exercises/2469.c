#include <stdio.h>
#include <stdlib.h>
double* convertTemperature(double celsius) {
    double* p = (double*)malloc(2 * sizeof(double));
    p[0] = celsius + 273.15;
    p[1] = celsius * 1.8 + 32.0;
    return p;
}

int main() {
    double temp;
    scanf("%lf", &temp);
    double* p = convertTemperature(temp);
    printf("[%.3lf,%.3lf]\n", *p, *(p + 1));
    printf("[%.3lf,%.3lf]\n", p[0], p[1]);
    free(p);
}