#include <iostream>

using namespace std;


double find_element(double t[], int n, double x){
    int num = 0;

    int poczatek = 0;
    int koniec = n;
    int mid;

    while (poczatek <= koniec){
        num++;
        mid = (poczatek + koniec)/2;

        if (t[mid] == x){
            cout << "Liczba porównań: " << num;
            return mid;
        }
        else if (t[mid] < x)
            poczatek = mid + 1;
        else
            koniec = mid - 1;
    }

    return -1;
}

int main(){
    double t[20];

    for (int i = 0; i < 20; i++){
        t[i] = i;
        cout << i + 1 << '\n';
        find_element(t, i, i);

        cout << endl;
    }

    return 0;
}

// W zadaniu wykorzystac mozna bisekcje - przy kazdej iteracji liczba potencjalnych rozwiazan maleje o polowe

// Dzieki bisekcji mozemy ustalic, ze wystarczy sufit(log2(n)) iteracji, aby znalezc szukana liczbe


// W przykladzie szukam za kazdym razem ostatniego elementu, poniewaz jest on elementem ktory
// w tym algorytmie szukany jest najdluzsza droga (poniewaz srodek przedzialu = floor((poczatek + koniec) / 2))


//ALGORYTM:
// 1. wybieramy srodkowa liczbe z przedzialu -> mid
// 2. sprawdzamy czy mid jest rowna szukanej, jesli tak, konczymy program
// 3. dzielimy tablice na dwie, odrzucajac mid
// 4. jesli szukana liczba byla mniejsza od mid, to wybieramy 1 przedzial, jesli wieksza to 2 przedzial
// 5. mid jest od teraz srodkowa liczba nowego przedzialu
// 6. Wracamy od 1 kroku

