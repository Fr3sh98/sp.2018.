
//4. Napisz program, który wyliczy sumę liczb naturalnych od 1 do liczby n podanej przez użytkownika.
//Kiedy użytkownik poda liczbę mniejszą niż 1, to program powinien wypisać stosowny komunikat o błędzie.
#include <stdio.h>
#include <stdlib.h>

void wczytaj_liczbe_calkowita(int *n_p){
  printf("Podaj liczbę całkowitą większą od 0: ");
  scanf("%d", n_p);

if (*n_p <= 0) {
  printf("Liczba musi być większa od 0.\n");
  exit(1);
  }
}

int main() {
int n, suma = 0;
int i; //kolejne liczby od 1

wczytaj_liczbe_calkowita(&n);

i = 1;
while (i <= n) {
  suma += i;
  i++;
  }

  printf("Suma: %d\n", suma);
}
