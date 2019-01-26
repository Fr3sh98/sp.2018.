#include <stdio.h>

//deklaracja tablicy 1000x1000 potrzebej do zadnia nr. 3
int fabric[1000][1000];
//tablica do zliczania znalezionych liczb
int numberFound[200000];
int lines[10000]; //linie z pliku do 1 zadania
int n1 = 0; //wielkosc tablicy do zadania 1
char lines2[10000][32]; //tablica przechowujaca linie do 2 zadania
const int letters = 'z' - 'a' + 1; //ilość liter w alfabecie angielskim
int n2 = 0; //ilosc linii w zadaniu 2


void f1();

void f2();

void f3();

int main() {
    f1();
    f2();
    f3();
    return 0;
}

void wyzerujTabliceZnalezionych() {
    for (int i = 0; i < 200000; i++)
        numberFound[i] = 0;
}

void f1a() {
    FILE *file = fopen("data1", "r");//deklaracja oraz otwarcie pliku z danymi
    int a = 0;//zmienna przechowujaca suma liczb wejścoiwych
    char currentline[1000];//buffor ktory jest w stanie przyjąć do 1000 znakków

    while (fgets(currentline, sizeof(currentline), file) !=
           NULL) { //pętla przechodząca przez plik i wczytujaca wszystkie linie az do konca pliku
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
    wyzerujTabliceZnalezionych();
    while (!found) { //petla dzialajaca do momentu znalezienia wartosci powtarzajacej sie 2 razy
        b += lines[i];
        numberFound[b + 100000]++;
        if (numberFound[b + 100000] ==
            2) { //jezeli liczba b wystapila 2 razy tp wypisujemy ja i wychodzimy z petli przez zmiana zmiennej found na 1
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

void f2load() {
    FILE *file = fopen("data2", "r"); //deklaracja oraz otwarcie pliku z danymi
    char currentline[32]; //wszystiie linie w pliku maja taka sama dlugosc wiec mozemy z gory ustalic dlugosc buffora

    while (fgets(currentline, sizeof(currentline), file) !=
           NULL) { //petla przechodzaca przez plik i wczytujaca wszystkie linie aa do konca pliku
        for (int i = 0; i < 32; i++)
            lines2[n2][i] = currentline[i];

        n2++;
    }

    fclose(file);//zamykamy plik
}

void f2Wyzeruj(int arr[letters]) {
    for (int i = 0; i < letters; i++) //wypelniamy nasza tablice zerami
        arr[i] = 0;
}

void f2a() {
    int a = 0, b = 0;
    for (int k = 0; k < n2; k++) {
        int aa = 0, bb = 0, array[letters]; //tablica zliczająca liczbę wystąpien liter
        f2Wyzeruj(array);
        for (int i = 0; i < 27; i++) //zliczanie ilosci wystapien liter w linii
            array[lines2[n2][i] - 'a']++;
        for (int i = 0; i < letters; i++) //sprawdzanie czy linia spelnia warunki zadania
            if (array[i] == 2) aa = 1;
            else if (array[i] == 3) bb = 1;

        if (aa == 1) a++;
        if (bb == 1) b++;
    }
    printf("2) a. %d ", (a * b)); //wypisanie wyniku
}

int differentCharacters(int i, int j) {
    int different = 0;
    for (int k = 0; k < 27; k++) {
        if (lines2[i][k] != lines2[j][k])
            different++; //zliczamy ilosc roznych znakow
    }
    return different;
}

void f2b() {
    //porownujemy wszystkie linie ze soba
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2; j++) {
            if (differentCharacters(i, j) ==
                1) { //jezeli liczba roznych znakow wynosi 1 to konczymy porownynwanie linii i wypisujemy wyniki
                for (int k = 0; k < 27; k++)  //tworzenie wyniku ze wspolnych liter
                    if (lines2[i][k] == lines2[j][k])
                        printf("%c", lines2[i][k]);

                printf("\n");
                return;
            }
        }
    }
}

void f2() {
    f2load();
    f2a();
    printf(" b. ");
    f2b();
}

void wyzeruj3() {
    //wypelnianie naszej tablicy zerami
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            fabric[i][j] = 0;
}

void prepareData() {
    FILE *file = fopen("data3", "r"); //deklaracja oraz otwarcie pliku z danymi
    int l = 0, t = 0, w = 0, h = 0;//deklaracja zmiennych ktore pozwola nam sie 'poruszac' po dwuwymiarowej tablicy
    char currentline[50];

    //petla przechodzaca przez plik i wczytujaca wszystkie linie az do konca pliku
    while (fgets(currentline, sizeof(currentline), file) != NULL) {
        sscanf(currentline, "%d%d%d%d", &l, &t, &w, &h);//'wyciaganie' danych z linii
        for (int y = t; y < t + h; y++)
            for (int x = l; x < w + l; x++)
                fabric[y][x]++; //zliczanie ilosci punktow ktore naleza do danego elfa
    }
    fclose(file);//zamkniecie pliku
}

void f3a() {
    int area = 0;

    wyzeruj3();
    prepareData();

    for (int i = 0;
         i < 1000; i++)//sprawdzamy wszystkie pola w tablicy, jezeli sa wieksze od 1, to do zmiennej area dodajemy 1
        for (int j = 0; j < 1000; j++)
            if (fabric[i][j] > 1)
                area++;
    printf("3) a. %d", area);
}

int sharedBy(int l, int t, int w, int h) {
    int shared = 0;//zliczanie ilosci punktow ktore sa wspoldzielone przez wiecej niz jednego elfa

    for (int y = t; y < t + h; y++)
        for (int x = l; x < w + l; x++)
            if (fabric[y][x] > 1)//sprawdzamy przez ilu elfow punkt jest wspoldzielony
                shared++;

    return shared;
}

void f3b() {
    FILE *file = fopen("data3", "r"); //deklaracja oraz otwarcie pliku z danymi
    int l = 0, t = 0, w = 0, h = 0, n = 1;
    char currentline[50];

    while (fgets(currentline, sizeof(currentline), file) != NULL) {
        sscanf(currentline, "%d%d%d%d", &l, &t, &w, &h);//'wyciaganie' danych z linii
        if (sharedBy(l, t, w, h) == 0) { //jezeli zaden z punktow nie jest wspoldzielony z innym elfem to konczymy petle i wypisujemy wyniki
            printf(" b. %d\n", n);
            return;
        }
        n++;
    }
    fclose(file); //zamkniecie pliku
}

void f3() {
    f3a();
    f3b();
}
