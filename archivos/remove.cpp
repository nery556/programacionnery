#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    char nombre[100];
    cout << "Dame el nombre de un archivo para eliminarlo" << endl;
    gets(nombre);
    if (remove(nombre)==0){
        cout << "Se removio exitosamente";
    }else{
        cout << "No se pudo remover"<< endl;
    }
    cout << nombre;
}