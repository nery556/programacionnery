#include <iostream>

using namespace std;


int main(){
    float *p,calif;
    p=&calif;
    *p=6.5;
    cout << calif << endl;

    calif=9.2;
    cout << *p << endl;

    //Que estoy imprimiendo?
    //Estoy imprimiendo la direccion del contenido de mi puntero
    //Osea la direccion de 6.2, osea la direccion de calif
    cout << &(*p) << endl;
    cout << &calif << endl;

    //Que estoy imprimiendo?
    //Estoy imprimiendo el contenido de la direccion de p
    //osea el valor de p, osea la direccion de calif
    cout << *(&p) << endl;
    cout << &calif << endl;

    //OJO , CUANDO DECLARO UN PUNTERO escribo int *a
    //CUANDO LO USO, el * significa contenido


}