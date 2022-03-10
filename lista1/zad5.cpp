#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

void zapisz(string file, vector<int> c){
    ofstream plik(file);

    for(auto x: c){
        plik << x << " ";
    }

    cout << "Plik c.txt został stworzony" << endl;
}

vector<int> iloczyn(vector<int> a, vector<int> b){
    int count = 0;

    int vector_size = a.size() + b.size() - 1;
    vector<int> c(vector_size, 0);

    for (size_t i = 0; i < a.size(); i++)
    {
        for (size_t j = 0; j < b.size(); j++)
        {
            c[i + j] += a[i] * b[j];
            count ++;
        }
        
    }
    c.insert(c.begin(),vector_size-1);
    cout << count << endl;
    return c;
}


vector<int> wczytaj(string file)
{
    std::vector<int> v;
    std::ifstream plik(file);
    int wartosc;

    while (plik >> wartosc)
    {
        v.push_back(wartosc);
    }
    v.erase(v.begin());
    return v;
}



int main(){
    zapisz("c.txt",iloczyn(wczytaj("a.txt"),wczytaj("b.txt")));
}