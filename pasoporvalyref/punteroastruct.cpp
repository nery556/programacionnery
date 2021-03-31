#include <iostream>
#include <string>

using namespace std;
typedef struct Pajaro{
    string color;
    string especie;
    int edad;
    string tamano;

}Pajaro;
int main(){
    //PTR TIENE COMO VALOR LA DIRECCION DE UNA VARIABLE
    //*PTR TIENE COMO VALOR EL CONTENIDO DE ESA VARIABLE
    Pajaro colibri;
    colibri.color="Amarillo";
    colibri.edad=2;
    colibri.tamano="Mediano";
    int *ptr, a;
    ptr=&a;
    *ptr=10;
    cout << a << endl;
    *ptr=5;
    /*TAMBIEN PUEDO CREAR PUNTEROS DE STRUCT
    PUEDO CREAR UN PUNTERO DE TIPO STRUCT PAJARO
    LE ESTOY ASIGNANDO LA DIRECCION DE UN PAJARO
    */
    Pajaro *p;
    p=&colibri;
    (*p).color="Azul"; //el parentesis se ve feo
    p->color="Azul"; //ES EXACTAMENTE IGUAL A (*p).color="Azul"
    p->edad=3;
    cout << p->color << p->edad << colibri.color << colibri.edad << endl;

    


}