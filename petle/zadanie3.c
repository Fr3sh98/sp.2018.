
//3. Napisz program, który wczyta dwie liczby całkowite a i b (a<b)
//a następnie wypisze wszystkie liczby całkowite pomiędzy a i b.

#include <stdio.h>

int main()
{

  int a, b = 15;
  for (a = 1; a < b; a++)
  {
    printf("%d\n", a);
  }
}