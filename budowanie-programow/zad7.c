/*Napisz program, który wczyta liczbę rzeczywistą i wypisze
 jej odwrotność oraz jej pierwiastek kwadratowy. Program nie
 powinien obliczać odwrotności liczby 0 oraz pierwiastka z
 liczby ujemnej. W takiej sytuacji zamiast obliczeń program
 powinien wypisać odpowiedni komunikat.*/

#include<stdio.h>
#include<math.h>
#include"helper.h"

int main()
{
    double liczba, odwrotnosc, pierwiastek;
    
    wczytaj_double("podaj liczbe: " ,&liczba);
    
    odwrotnosc = 1/ liczba;
    pierwiastek =sqrt(liczba);
    
    if(liczba == 0){
        printf("dla liczby 0 nie ma odwrotnosci\n");
        printf("liczba:%.2lf, pierwiastek: %.2lf\n",
               liczba,  pierwiastek);
    }
    else if (liczba < 0){
        printf("nie isnieje pierwiastek z liczby ujemniej %lf\n", liczba);
        printf("liczba:%.2lf,odwrotnosc: %.2lf,\n",
               liczba, odwrotnosc );
        
    }
    else
    {
        printf("liczba:%.2lf,odwrotnosc: %.2lf, pierwiastek: %.2lf\n",
               liczba, odwrotnosc, pierwiastek);
    }
    return 0;
}
