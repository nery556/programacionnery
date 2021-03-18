#include <iostream>

using namespace std;

// endl es exactamente igual a '\n'
int main(){
    string nombre;
    int edad;
    float promedio;
    char car ='t';
    cout << "Escribe tu nombre ";
    cin >> nombre;
    cout << "Dime tu edad " << endl <<"Debes tener entre 14 y 80 anios ";
    cin >> edad;
    cout << "Dame tu promedio ";
    cin >> promedio;
    cout << "Mi nombre es " << nombre << " tengo " << edad << " anios y mi promedio es " << promedio;
    return 0;
}