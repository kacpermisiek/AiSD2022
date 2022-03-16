#include <iostream>

using namespace std;

int compares_A = 0;
int compares_B = 0;
int compares_C = 0;

int glebokosc_B = 0;
int glebokosc_C = 0;

int max_A(int t[], int n){
    int x = t[--n];
    while  (n--) {
        compares_A ++;
        if (t[n] > x){
            x = t[n];
        }
    }
    return x;
}

int max_B(int t[], int n) {
    glebokosc_B ++;
    if (n == 1) {
        return t[0];
    } else {
        int tmp = max_B(t, n-1);
        compares_B++;
        if (tmp > t[n-1]) {
            return tmp;
        } else {
            return t[n-1];
        }
    }
}

int max_C(int t[], int start, int koniec) {
    glebokosc_C ++;
    if (koniec - start == 0) {
        return t[start];
    } else {
        int mid = (start + koniec)/2;
        int p1 = max_C(t, start, mid);
        int p2 = max_C(t, mid+1, koniec);
        compares_C ++;
        if (p1 > p2) 
            return p1;
        else 
            return p2;
    }
}

int main(){
    int tab[] = {100, 39, 65, 29, 97, 30, 56, 88};

    cout << max_A(tab, 8) << endl;
    cout << max_B(tab, 8) << endl;
    cout << max_C(tab, 0, 7) << endl;


    cout << "Wersja iteracyjna: " << compares_A << " porownan" << endl;
    // wersja iteracyjna wykonuje n-1 porownan
    // pamiec - potrzebujemy:
    // pamiec na tablice o n elementach => n
    // pamiec na zmienna n 
    // pamiec na wynik
    // razem: n+2 (dla 10-elementowej tablicy intow bedzie to 44 bajty) 


    cout << "Wersja rekurencyjna nr1.: " << compares_B << " porownan" << endl;
    cout << "glebokosc: " << glebokosc_B << endl;
    // wersja rekurencyjna 1 wykonuje rowniez n-1 porownan
    // pamiec:
    // za kazdym razem do funkcji podajemy tablice (mniejsza o 1) oraz liczbe n(mniejsza o 1)
    // konczymy podajac tablice z 1 elementem oraz liczbe n
    // calkowita liczba elementow podawanych w tablicy: ((1+n)/2) * n
    // calkowita liczba elementow podawanych jako liczba n: n
    // razem: (n(3+n)) / 2 = n^2 / 2 + 3/2 n

    cout << "Wersja rekurencyjna nr2.: " << compares_C << " porownan" << endl;
    cout << "glebokosc: " << (float)glebokosc_C / 2  << endl; //glebokosc dziele przez 2, poniewaz przy kazdej iteracji tworzymy dwie tablice
    // wersja rekurencyjna 2 wykonuje rowniez n-1 porownan
    // pamiec:
    // glebokosc 3 sposobu jest o 1 mniejsza niz 2 sposobu
    // natomiast powoduje stworzenie 2 razy wiecej tablic
    // maksymalna laczna ilosc elementow w tablicach: n * m - 
    // gdzie n = liczba elementow w tablicy poczatkowej
    // m = glebokosc listy
    // dodatkowo przy kazdej iteracji wykorzystujemy dwie zmienne - start i koniec
    // maksymalna ilosc takich zmiennych = 2 * 2^m, gdzie m = glebokosc listy:
    // calkowita maksymalna ilosc zmiennych: n*m + 2* 2^m
}