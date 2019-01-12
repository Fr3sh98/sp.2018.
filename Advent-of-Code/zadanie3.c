#include <stdio.h>

//deklaracja tablicy 1000x1000 potrzebej do zadnia nr. 3
int fabric[1000][1000];

void f3() {
//deklaracja oraz otwarcie pliku z danymi
    FILE *file = fopen("data3", "r");
//deklaracja zmiennych które pozwolą nam się 'poruszać' po dwuwymiarowej tablicy
    int l = 0, t = 0, w = 0, h = 0;
    char currentline[50];

//wypełnianie naszej tablicy zerami
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            fabric[i][j] = 0;

//pętla przechodząca przez plik i wczytująca wszystkie linie aż do końca pliku
    while (fgets(currentline, sizeof(currentline), file) != NULL) {
//'wyciąganie' danych z linii
        sscanf(currentline, "%d%d%d%d", &l, &t, &w, &h);
//zliczanie ilości punktów które należą do danego elfa
        for (int y = t; y < t + h; y++)
            for (int x = l; x < w + l; x++)
                fabric[y][x]++;
    }

    int area = 0;

//sprawdzamy wszystkie pola w tablicy, jezeli sa wieksze od 1 do zmiennej area dodajemy 1
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            if (fabric[i][j] > 1)
                area++;

    printf("3) %d\n", area);

//zamknięcie pliku
    fclose(file);
  }


int main() {
    f3();
    return 0;
}
