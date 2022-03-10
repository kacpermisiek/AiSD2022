#include <iostream>
#include <math.h>
using namespace std;



int pow_recursion(int x, int n){
    if( n==0 )
        return 1;
    if (n%2==0)
        return pow_recursion(x * x, n/2);
    
    else
        return x * pow_recursion(x * x, (n-1)/2);
    
}

int pow_non_recursion(int x, int n) {
    int w = 1;
    
    while (n > 0) {
        if (n % 2 == 1) {
            w *= x;
        }
        x *= x;
        n /= 2;
    }

    return w;
}

int main(){
    cout << pow_recursion(2, 19) << endl;
    cout << pow_non_recursion(2, 19) << endl;
    return 0;
}