//7. Napisz program, który wczyta liczbę rzeczywistą i wypisze jej odwrotność oraz jej pierwiastek kwadratowy. Program nie //powinien obliczać odwrotności liczby 0 oraz pierwiastka z liczby ujemnej. W takiej sytuacji zamiast obliczeń program //powinien wypisać odpowiedni komunikat.

#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, suma, iloczyn;
    char *msg1 = "Najwieksza liczba to: %d\n";
    char *msg2 = "Najmniejsza liczba to: %d\n";
    
    printf("Wprowadz trzy liczby calkowite: ");
    scanf("%d %d %d", &a, &b , &c);
    
    suma = a + b + c;
    iloczyn = a * b * c;
    
    printf("Suma wynosi: %d\n", suma);
    printf("Iloczyn wynosi: %d\n", iloczyn);
    
    //Najmniejsza wprowadzona liczba:
    if (a < b && a < c) {
        printf(msg2, a);
    }
    else if (b < a && b < c) {
        printf(msg2, b);
    }
    else if (c < b && c < a) {
        printf(msg2, c);
    }
    
    //Najwieksza wprowadzona liczba:
    if (a > b && a > c) {
        printf(msg1, a);
    }
    else if (b > a && b > c) {
        printf(msg1, b);
    }
    else if (c > b && c > a) {
        printf(msg1, c);
    }
    
    
}
