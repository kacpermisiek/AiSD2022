#include<iostream>
#include<vector>
using namespace std;

/*
n = 0
W = a0 => 0 mnożen

n = 1
W = a0 + a1 x => 1 mnozenie

n = 2
W = a0 + a1 x + a2 x^2 = a0 + x(a1 + a2 x) = a0 + x(a1 + x(a2)) => 2 mnozenia

n = 3
W = a0 + a1 x + a2 x^2 + a3 x^3 = a0 + x(a1 + a2 x + a3 x^2) = a0 + x(a1 + x(a2 + a3 x)) = a0 + x(a1 + x(a2 + x (a3))) => 3 mnozenia

n = 4
W = a0 + a1 x + a2 x^2 + a3 x^3 + a4 x^4 = a0 + x(a1 + a2 x + a3 x^2 + a4 x^3) = a0 + x(a1 + x(a2 + a3 x + a4 x^2) =
= a0 + x(a1 + x(a2 + x(a3 + a4 x))) = a0 + x(a1 + x(a2 + x(a3 + x(a4)))) => 4 mnozenia

Schemat Hornera polega na wyciagnieciu wspolnego czynnika (x) przed nawias
*/

int counter = 0;

double oblicz(vector<double> a, double x) {
    int result = 0;

    for (int i = a.size()-1; i > 0; i--){
        result += a[i];
        result *= x;
        counter++;
    }
    result += a[0];
    return result;
}

int main() {
    vector<double> a = {4, 5, 3};
    
    cout << oblicz(a, 5) << endl;
    cout << "Wykonano " << counter << " mnozenia" << endl;

    return 0;
}