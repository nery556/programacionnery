/*
Vamos a crear una pequeña base de datos
vamos a guardar la informacion de las personas
en un archivo .txt
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct Persona{
    int edad;
    char sexo;
    float altura;
    float peso;
    string nacionalidad;
};

int main(){
    struct Persona p1;
    cout << "Dame los siguientes datos para guardarlos en un archivo de textos" << endl;
    cout << "Dame la edad" << endl;
    cin >> p1.edad;
    cout << "Dame su sexo" << endl;
    cin >> p1.sexo;
    cout << "Dame su altura" << endl;
    cin >> p1.altura;
    cout << "Dame su peso" << endl,
    cin >> p1.peso;
    cout << "Dame su nacionalidad" << endl;
    cin >> p1.nacionalidad;

    cout << "Dame el nombre de donde quieres guardar el archivo " << endl;
    string nombre_archivo;
    cin >> nombre_archivo;
    ofstream Miarchivo;
    Miarchivo.open(nombre_archivo);

    Miarchivo << "Su edad es " << p1.edad << endl;
    Miarchivo << "Su sexo es " << p1.sexo << endl;
    Miarchivo << "Su altura es " << p1.altura << endl;
    Miarchivo << "Su peso es " << p1.peso << endl;
    Miarchivo << "Su nacionalidad es " << p1.nacionalidad << endl;



    Miarchivo.close();




    return 0;
}