#include <vector>
#include <iostream>

using namespace std;

void wyzn_macierz() {
    // https://matrixcalc.org/en/#determinant(%7B%7B3,5,1%7D,%7B4,6,9%7D,%7B2,2,5%7D%7D)

    std::vector<std::vector<float>> macie = {{3, -5, 1, 2}, {4, 6, 9, -5}, {2, 2, 5, 5}, {2, 2, 3, 5}};
    int count = 0;

    // tworzenie macierzy górnotrójkątnej
    for (int j = 0; j < macie.size(); j++) {
        for (int i = j + 1; i < macie.size(); i++) {
            float mnoznik = macie[i][j] / macie[j][j];
            count++; // jeżeli tutaj dodajemy mnożenie to wychodzi mniej mnożeń
            for (int k = 0; k < macie.size(); k++) {
                // mnożenie całego rzędu i zerowanie pierwszego elementu
                macie[i][k] -= macie[j][k] * mnoznik;
                count++; // bez dodawania mnożeń na górze, tutaj trzeba dać count+=2
            }
        }
    }
    
    std::cout<<"\nMacierz górnotrójkątna: "<<std::endl;
    for(int i = 0; i < macie.size(); i++) {
        for(int j = 0; j < macie.size(); j++) {
            std::cout<<macie[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    
    std::cout<<"Wyznacznik macierzy: "<<macie[0][0] * macie[1][1] * macie[2][2]<<std::endl;
    std::cout<<"Ilość mnożeń: "<<count + 3<<std::endl; // +3 bo 3 dodatkowe mnozenia na gorze

}

int main(){
    wyzn_macierz();
}