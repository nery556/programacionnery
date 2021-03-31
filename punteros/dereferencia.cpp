#include <iostream>
using namespace std;

int main(){

    // ES DIFERENTE EL OPERADOR & y el operador &&

    //Creamos un puntero a entero llamado p
    int *p, edad;
    //A ese p le asignamos la direccion de memoria de la variable edad
    p=&edad;
    edad=15;
    cout << "La edad es " << edad << endl;
    //Hay un operador que se llama el operador de DEREFERENCIA
    // ES ESTE *
    //Este operador me dice el CONTENIDO de la direccion a la que apunta mi puntero
    cout << *p << endl;
    //Yo puedo cambiar el valor de la variable a la que esta apuntando mi puntero
    *p=8;
    cout << edad << endl;
    
    float juanito;
    juanito=3.5;
}