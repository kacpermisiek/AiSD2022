#include<iostream>
#include<vector>

using namespace std;

void get_max_min(vector<int> tab){

    int max, min, i;
    int n = tab.size();

    int counter = 0;
    if (n % 2 == 0) {
        counter ++;
        if (tab[0] > tab[1]) {
            max = tab[0];
            min = tab[1];
        }
        else {
            max = tab[1];
            min = tab[0];
        }
        i = 2;
        
    }

    else {
        max = tab[0];
        min = tab[0];
        i = 1;
    }
    
    while (i < n - 1)
    {
        counter ++;
        if (tab[i] > tab[i + 1])
        {
            counter += 2;
            if (tab[i] > max) max = tab[i];
            if (tab[i + 1] < min) min = tab[i + 1];
        }
        else
        {
            counter += 2;
            if (tab[i + 1] > max) max = tab[i + 1];
            if (tab[i] < min) min = tab[i];
        }
        i += 2;
    }


    

    cout <<"Liczba elementów: " << tab.size() <<  "\tMax: " << max << "\tMin: " << min << "\tLiczba porownan: " << counter << endl;
}



int main(){
    vector <int> tablica = {107, 462, 57, 540, 24, 410, 966, 205, 729, 876, 602, 314, 226, 573, 980, 797, 434, 687, 75, 497, 668, 775, 220, 91, 262, 29, 815, 134, 93, 449, 365, 601, 606, 515, 712, 523, 453, 645, 609, 22, 377, 474, 48, 105, 465, 408, 929, 451, 245, 683, 222, 200, 539, 902, 622, 256, 175, 140, 741, 384, 887, 770, 924, 444, 879, 644, 753, 635, 897, 631, 289, 487, 765, 793, 16, 313, 932, 894, 868, 49, 707, 634, 348, 971, 579, 676, 858, 818, 759, 917, 870, 706, 454, 596, 237, 994, 320, 300, 565, 918};
    

    get_max_min(tablica);
    return 0;
}