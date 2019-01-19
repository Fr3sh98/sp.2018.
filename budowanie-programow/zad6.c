// 6. Napisz program, który wczyta liczbę rzeczywistą i
// wypisze jej pierwiastek kwadratowy.
// W wypadku podania liczby ujemnej,
// program powinien wypisać komunikat o błędzie oraz
// zakończyć działanie.


#include<stdio.h>
#include<math.h>

void podaj_liczbe(const char *prompt, double *x);

int main() {
    double a, b;
    
    
    podaj_liczbe("podaj liczbeliczba calkowita: ", &a);
    if (a >=0){
        b=sqrt(a);
        printf("pierwiastek z %lf to %lf\n", a,b);
    }else {
        printf("! blad\n");
    }
    return 0;
}



void podaj_liczbe(const char * prompt, double *x){
    puts(prompt);
    scanf("%lf", x);
}
