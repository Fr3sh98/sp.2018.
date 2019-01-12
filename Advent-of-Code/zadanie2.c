
#include <stdio.h>
void f2() {
    //deklaracja oraz otwarcie pliku z danymi
    FILE *file = fopen("data2", "r");
    //wszystiie linie w pliku mają taką samą długość więc mozemy z góry ustalić długość buffora
    char currentline[32];
    int a = 0, b = 0;
    
    //pętla przechodząca przez plik i wczytująca wszystkie linie aż do końca pliku
    while (fgets(currentline, sizeof(currentline), file) != NULL) {
        int aa = 0, bb = 0;
        int letters = 'z' - 'a' + 1;
        int array[letters];
        //wypełniamy naszą tablicę zerami
        for (int i = 0; i < letters; i++)
            array[i] = 0;
        
        //zliczanie ilości wystąpień liter w linii
        for (int i = 0; i < 27; i++)
            array[currentline[i] - 'a']++;
        
        //sprawdzanie czy linia spełnia warunki zadania
        for (int i = 0; i < letters; i++) {
            if (array[i] == 2)
                aa = 1;
            else if (array[i] == 3)
                bb = 1;
        }
        
        if (aa == 1) a++;
        if (bb == 1) b++;
    }
    
    //wypisanie wyniku
    printf("2) %d\n", (a * b));
    
    //zamykamy plik
    fclose(file);
}
int main() {
    f2();
    return 0;
}
