#include <stdio.h>

void podaj_liczbe(char *prompt, int *x){
    printf("%s", prompt);
    scanf("%d",x);
}

void wczytaj_double(char *prompt, double *x){
    printf("%s", prompt);
    scanf("%lf",x);
}
