#include <iostream>
#include <vector>
#include <string>


using namespace std;
int main(){
    //Vector
    vector <int> calificaciones;
    calificaciones.push_back(10);
    calificaciones.push_back(8.5);
    //Arreglo
    int calif[10];
    calif[0]=10;
    //String
    string saludo="Hola buenas noches";

    cout << calificaciones.at(0) << endl;
    cout << calificaciones.size();
    

    return 0;

}