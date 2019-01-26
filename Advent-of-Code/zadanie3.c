#include <stdio.h>

//deklaracja tablicy 1000x1000 potrzebej do zadnia nr. 3
int fabric[1000][1000];
//tablica do zliczania znalezionych liczb
int numberFound[200000];
const int letters = 'z' - 'a' + 1; //ilość liter w alfabecie angielskim

void part1();
void part2();

int main() 
part1();
part2();
}



void resetfabric() {
  //wypelnianie naszej tablicy zerami
  for (int i = 0; i < 1000; i++)
  for (int j = 0; j < 1000; j++)
  fabric[i][j] = 0;
}

void prepareData() {
  FILE *file = fopen("data3", "r"); //deklaracja oraz otwarcie pliku z danymi
  int l = 0, t = 0, w = 0, h = 0; //deklaracja zmiennych ktore pozwola nam sie 'poruszac' po dwuwymiarowej tablicy
  char currentline[50];

  //petla przechodzaca przez plik i wczytujaca wszystkie linie az do konca pliku
  while (fgets(currentline, sizeof(currentline), file) != NULL) {
    sscanf(currentline, "%d%d%d%d", &l, &t, &w, &h); //'wyciaganie' danych z linii
    for (int y = t; y < t + h; y++)
    for (int x = l; x < w + l; x++)
    fabric[y][x]++; //zliczanie ilosci punktow ktore naleza do danego elfa
  }
  fclose(file); //zamkniecie pliku
}

void part1() {
  int area = 0;

  resetfabric();
  prepareData();

  for (int i = 0;
    i < 1000; i++) //sprawdzamy wszystkie pola w tablicy, jezeli sa wieksze od 1, to do zmiennej area dodajemy 1
    for (int j = 0; j < 1000; j++)
    if (fabric[i][j] > 1)
    area++;
    printf("3) a. %d", area);
  }

  int sharedBy(int l, int t, int w, int h) {
    int shared = 0; //zliczanie ilosci punktow ktore sa wspoldzielone przez wiecej niz jednego elfa

    for (int y = t; y < t + h; y++)
    for (int x = l; x < w + l; x++)
    if (fabric[y][x] > 1) //sprawdzamy przez ilu elfow punkt jest wspoldzielony
    shared++;

    return shared;
  }

  void part2() {
    FILE *file = fopen("data3", "r"); //deklaracja oraz otwarcie pliku z danymi
    int l = 0, t = 0, w = 0, h = 0, n = 1;
    char currentline[50];

    while (fgets(currentline, sizeof(currentline), file) != NULL) {
      sscanf(currentline, "%d%d%d%d", &l, &t, &w, &h); //'wyciaganie' danych z linii
      if (sharedBy(l, t, w, h) == 0) { //jezeli zaden z punktow nie jest wspoldzielony z innym elfem to konczymy petle i wypisujemy wyniki
        printf(" b. %d\n", n);
        return;
      }
      n++;
    }
    fclose(file); //zamkniecie pliku
  }
