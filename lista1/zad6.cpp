#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

map<char, int> count_signs(string name) {
    fstream file(name);
    string line;

    map<char, int> result;

    while (file.is_open() && !file.eof())
    {
        getline(file, line);
        for(auto sign : line)
            result[sign] += 1;
    }
    file.close();
    return result;
}



int main(int argc, char *argv[]){



    if (argv[1])
    {
        string file_name = argv[1];

        map<char, int> result = count_signs(argv[1]);

        for (auto sign : result)
            cout << sign.first << " : " << sign.second << endl;
    }
    return 0;
}