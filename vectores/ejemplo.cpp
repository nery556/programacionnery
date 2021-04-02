#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

int main(){
    //Cuando declaramos un vector, se le puede especificar el tamaño o se le puede omitir
    vector <int> vectorenteros;
    vector <string> cadenas;
    vector <float> v2;
    vector <vector <int>> vv1;

    v2.push_back(3.5);
    //Imprimir los elementos del vector
    for (int i=0;i<v2.size();i++){
        cout << v2.at(i) << endl;
        cout << v2[i] << endl;
    }
    v2.pop_back();


}