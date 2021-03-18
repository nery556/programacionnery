#include  <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    //Hacer un programa en donde pidas una cantidad de calificaciones y las metas uhna por una en un vector
    vector <int> calificaciones;
    int cant, i=1, calif;
    cout << "Dame el numero de calificaciones";
    cin >> cant;
    while (i<=cant){
        i++;
        cout << "Dame una calificacion" << endl;
        cin >> calif;
        calificaciones.push_back(calif);   
    }
    

    return 0;
}