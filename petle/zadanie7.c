// 7. Napisz program, który ze stdin wczyta 6 liczb rzeczywistych do tablicy,
//a następnie wypisze liczbę liczb dodatnich w niej zawartych.

#include <stdio.h>

#define size 6

int main()
{

  float tablica[size];

  printf("Podaj 6 elementow tablicy!\n");
  for (int i = 0; i < size; i++)
  {
    scanf("%f", &tablica[i]);
  }

  float dodatnie = 0;
  float niedodatnie = 0;

  for (int a = 0; a < 6; a++)
  {
    float tab = tablica[a];
    if (tab > 0)
    {
      dodatnie = dodatnie + 1;
    }
    else if (tab <= 0)
    {
      niedodatnie = niedodatnie + 1;
    }
  }
  printf("Liczba liczb dodatnich tablicy wynosi: %0.f\n", dodatnie);
  printf("Liczba liczb niedodatnich tablicy wynosi: %0.f\n", niedodatnie);
}