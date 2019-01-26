
#include <stdio.h>

//deklaracja tablicy 1000x1000 potrzebej do zadnia nr. 3
int fabric[1000][1000];
//tablica do zliczania znalezionych liczb
int numberFound[200000];
int lines[10000]; //linie z pliku do 1 zadania
int n1 = 0; //wielkosc tablicy do zadania 1
char lines2[10000][32]; //tablica przechowujaca linie do 2 zadania
const int letters = 'z' - 'a' + 1; //ilość liter w alfabecie angielskim
int n2 = 0; //ilosc linii w zadaniu 2

void f2();

int main() {
    f2();
    return 0;
}

void f2load() {
    FILE *file = fopen("data2", "r"); //deklaracja oraz otwarcie pliku z danymi
    char currentline[32]; //wszystiie linie w pliku maja taka sama dlugosc wiec mozemy z gory ustalic dlugosc buffora

    while (fgets(currentline, sizeof(currentline), file) !=
           NULL) { //petla przechodzaca przez plik i wczytujaca wszystkie linie aa do konca pliku
        for (int i = 0; i < 32; i++)
            lines2[n2][i] = currentline[i];

        n2++;
    }

    fclose(file);//zamykamy plik
}

void reset(int arr[letters]) {
    for (int i = 0; i < letters; i++) //wypelniamy nasza tablice zerami
        arr[i] = 0;
}

void f2a() {
    int a = 0, b = 0;
    for (int k = 0; k < n2; k++) {
        int aa = 0, bb = 0, array[letters]; //tablica zliczająca liczbę wystąpien liter
        reset(array);
        for (int i = 0; i < 27; i++) //zliczanie ilosci wystapien liter w linii
            array[lines2[n2][i] - 'a']++;
        for (int i = 0; i < letters; i++) //sprawdzanie czy linia spelnia warunki zadania
            if (array[i] == 2) aa = 1;
            else if (array[i] == 3) bb = 1;

        if (aa == 1) a++;
        if (bb == 1) b++;
    }
    printf("2) a. %d ", (a * b)); //wypisanie wyniku
}

int differentCharacters(int i, int j) {
    int different = 0;
    for (int k = 0; k < 27; k++) {
        if (lines2[i][k] != lines2[j][k])
            different++; //zliczamy ilosc roznych znakow
    }
    return different;
}

void f2b() {
    //porownujemy wszystkie linie ze soba
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2; j++) {
            if (differentCharacters(i, j) ==
                1) { //jezeli liczba roznych znakow wynosi 1 to konczymy porownynwanie linii i wypisujemy wyniki
                for (int k = 0; k < 27; k++)  //tworzenie wyniku ze wspolnych liter
                    if (lines2[i][k] == lines2[j][k])
                        printf("%c", lines2[i][k]);

                printf("\n");
                return;
            }
        }
    }
}

void f2() {
    f2load();
    f2a();
    printf(" b. ");
    f2b();
}
