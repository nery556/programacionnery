#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(){
    //Abriendo el archivo para leerlo, eso significa ifstream
    string nombre_archivo;
    cout << "Dame el nombre del archivo" << endl;
    cin >> nombre_archivo;
    ifstream Miarchivo;
    Miarchivo.open(nombre_archivo);

    //Si no se puede abrir el archivo
    if (!Miarchivo){
        cout << "No se pudo abrir el archivo, puede que no exista" << endl;
        exit(0);
    }
    //Crear un string donde vamos a almacenar los datos
    string datos;
    //La unica manera de recibir los datos es con getline()


    /* //getline lee linea por linea
    getline(Miarchivo,datos);
    //Imprimir los datos que recibio
    cout << datos << endl;*/

    while(getline(Miarchivo,datos)){
        cout << datos << endl;
    }

    //Cerramos el archivo
    Miarchivo.close();

    return 0;
}