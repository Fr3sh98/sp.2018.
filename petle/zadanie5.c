
//5. Napisz program, który wczyta ze stdin 6 liczb całkowitych do tablicy,
// a następnie wypisze zawartość tej tablicy od początku i od końca.

#include <stdio.h>

int main() {
  int n = 8;
  int t[n];

  printf("Podaj %d liczb całkowitych:\n", n);
  scanf("%d, %d, %d, %d, %d, %d", &t[0], &t[1], &t[2], &t[3], &t[4], &t[5]);

  printf("Od końca: %d, %d, %d, %d, %d, %d\n", t[5], t[4], t[3], t[2], t[1], t[0]);
}
