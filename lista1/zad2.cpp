#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x){
    return 3 * x - 1;
}

double bisection(double a, double b, double epsilon){
    double f_a = f(a);
    double f_b = f(b);
    double f_x0;
    double x0;

    float range1;
    float range2;

    if (f_a * f_b >= 0) {
        cout << "Funkcja nie spelnia wymogow: f(0) < 0 < f(1)" << endl; 
        return -1;
    }

    for (int i = 1 ; ; i++) {
        range1 = range2;

        x0 = (a + b) / 2;
        f_x0 = f(x0);
        if (f_a * f_x0 < 0) b = x0;
        else {
            a = x0;
            f_a = f(a);
        }
        range2 = fabs(a - b);
    
        cout << "Krok: " << setw(2)  << i << "\tx0: " << setw(10) << x0 << "\trange1: " << setw(13) << range1 <<  "\trange2: " << setw(13) << range2 << endl;

        // // Wersja bez epsilonu
        // if (range1 == range2){
        //     cout << "KONIEC" << endl;
        //     break;
        // }

        // Wersja z epsilonem
        if (fabs(range1 - range2) < epsilon){
            cout << "KONIEC" << endl;
            break;
        }
    }
    return x0;
}


int main(){
    double epsilon = 1e-04;
    cout << bisection(0, 10, epsilon) << endl;
    return 0;
}