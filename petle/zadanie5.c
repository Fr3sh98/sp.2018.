
//5. Napisz program, który wczyta ze stdin 6 liczb całkowitych do tablicy,
// a następnie wypisze zawartość tej tablicy od początku i od końca.

#include <stdio.h>
#include <stdlib.h>

#define size 6

int main()
{
  int tab[size];
  int i;

  printf("Podaj 6 elementow tablicy!\n");
  for (i = 0; i < size; i++)
  {
    scanf("%d", &tab[i]);
  }
  printf("Elementy tablicy od poczatku: \n");
  for (i = 0; i < size; i++)
  {
    printf("%d\n", tab[i]);
  }
  printf("Elementy tablicy od konca: \n");
  for (i = size - 1; i >= 0; i--)
  {
    printf("%d\n", tab[i]);
  }
}