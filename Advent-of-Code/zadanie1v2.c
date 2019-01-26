#include <stdio.h>

//deklaracja tablicy 1000x1000 potrzebej do zadnia
int fabric[1000][1000];
//tablica do zliczania znalezionych liczb
int numberFound[200000];
int lines[10000]; //linie z pliku do 1 zadania
int n1 = 0; //wielkosc tablicy do zadania 1


void f1();

int main() {
  f1();
  return 0;
}

void resetTable() {
  for (int i = 0; i < 200000; i++)
     numberFound[i] = 0;
}

void f1a() {
  FILE *file = fopen("data1", "r");//deklaracja oraz otwarcie pliku z danymi
  int a = 0;//zmienna przechowujaca suma liczb wejścoiwych
  char currentline[1000];//buffor ktory jest w stanie przyjąć do 1000 znakków

  while (fgets(currentline, sizeof(currentline), file) !=NULL) { //pętla przechodząca przez plik i wczytujaca wszystkie linie az do konca pliku
     int n = 0;
     sscanf(currentline, "%d", &n);//wczytanie lini z pliku do zmiennej n
     a += n; //dodawanie zmiennej n do zmiennej a
     lines[n1] = n;
     n1++; //zwiekszamy wielkosc tablicy
  }
  fclose(file); //zamkniecie pliku
  printf("1) a. %d", a);
}

void f1b() {
  int b = 0;//zmienna przechowujaca suma liczb wejścoiwych dla 2 całości z zadania
  int found = 0;
  int i = 0;
  resetTable();
  while (!found) { //petla dzialajaca do momentu znalezienia wartosci powtarzajacej sie 2 razy
     b += lines[i];
     numberFound[b + 100000]++;
     if (numberFound[b + 100000] == 2) { //jezeli liczba b wystapila 2 razy tp wypisujemy ja i wychodzimy z petli przez zmiana zmiennej found na 1
       printf(" b. %d\n", b);
       found = 1;
        }
     i = (i + 1) % n1;
    }
}

void f1() {
  f1a();
  f1b();
}
