#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]){
    ifstream archivo;
    archivo.open(argv[1]);
    string linea;
    while (getline(archivo,linea)){
        cout << linea << endl;
    }
}