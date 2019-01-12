#include <stdio.h>
void f1() {
    //deklaracja oraz otwarcie pliku z danymi
    FILE *file = fopen("data1", "r");
    //buffor ktory jest w stanie przyjąć do 1000 znaków
    char currentline[1000];
    //zmienna przechowujaca sumę liczb wejścoiwych
    int a = 0;
    
    //pętla przechodząca przez plik i wczytująca wszystkie linie aż do końca pliku
    while (fgets(currentline, sizeof(currentline), file) != NULL) {
        int n = 0;
        //wczytanie lini z pliku do zmiennej n
        sscanf(currentline, "%d", &n);
        //dodawanie zmiennej n do zmiennej a
        a += n;
    }
    //zamknięcie pliku
    fclose(file);
    
    printf("1) %d\n", a);
}
int main() {
    f1();
    return 0;
}

