
//6. Napisz program, który wczyta ze stdin 6 liczb rzeczywistych do tablicy,
//a następnie wyszuka i wypisze największą i najmniejszą liczbę umieszczoną w tej tablicy.

#include <stdio.h>
#include <stdlib.h>

#define size 6

void f1() {
  float tablica[size];

  printf("Podaj 6 elementow tablicy!\n");
  for (int i = 0; i < size; i++)
  {
    scanf("%f", &tablica[i]);
  }

  float min = tablica[0];
  float max = tablica[0];

  for (int a = 0; a < size; a++)
  {
    float tab = tablica[a];
    if (tab > max)
    {
      max = tab;
    }
    else if (tab < min)
    {
      min = tab;
    }
  }
  printf("min = %f\nmax = %f\n", min, max);
}
int main() {
    f1();
    return 0;
}
