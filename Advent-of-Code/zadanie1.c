
#include <stdio.h>
void day1() {
    //deklaracja oraz otwarcie pliku z danymi
    FILE *file = fopen("data1", "r");
    //buffor ktory jest w stanie przyjÄ…Ä‡ do 1000 znakĂłw
    char currentline[1000];
    int lines[10000];
    int size = 0;
    //zmienna przechowujaca sumÄ™ liczb wejĹ›coiwych
    int a = 0;
    //zmienna przechowujaca sumÄ™ liczb wejĹ›coiwych dla 2 czÄ™Ĺ›ci z zadania
    int b = 0;
    int found = 0;
    
    //pÄ™tla przechodzÄ…ca przez plik i wczytujÄ…ca wszystkie linie aĹĽ do koĹ„ca pliku
    while (fgets(currentline, sizeof(currentline), file) != NULL) {
        int n = 0;
        //wczytanie lini z pliku do zmiennej n
        sscanf(currentline, "%d", &n);
        //dodawanie zmiennej n do zmiennej a
        a += n;
        lines[size] = n;
        //zwiÄ™kszamy wielkoĹ›Ä‡ tablicy
        size++;
    }
    printf("1) a. %d", a);
    
    
    //wypeĹ‚nienie tablicy zerami
    int i = 0;
    for (i; i < 200000; i++)
        numberFound[i] = 0;
    
    i = 0;
    //pÄ™tla dzaĹ‚ajÄ…ca do momentu znalezienia wartoĹ›ci powtarzajÄ…cej siÄ™ 2 razy
    while (!found) {
        b += lines[i];
        numberFound[b+100000]++;
        //jeĹĽeli liczba b wystÄ…piĹ‚a 2 razy tp wypisujemy jÄ… i wychodzimy z pÄ™tli przez zmianÄ™ zmiennej foun na 1
        if(numberFound[b+100000] == 2){
            printf(" b. %d\n", b);
            found = 1;
        }
        
        i = (i+1)%size;
    }
    //zamkniÄ™cie pliku
    fclose(file);
    
}
int main() {
    day1();
    return 0;
}

