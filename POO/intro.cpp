#include <iostream>
#include <string>
using namespace std;
//TODO ESTO EXISTE EN EL PARADIGMA ESTRUCTURADO
/*EXISTEN LOS STRUCTS Y LAS FUNCIONES*/
typedef struct Perro{
    string nombre;
    int edad;
    float peso;
    string raza;
    string color;
}Perro;

void ladrar(Perro p1){
    cout << "Hola soy " << p1.nombre << " guaf guaf" << endl;
}
int main(){
    Perro tofu;
    tofu.edad=1;
    tofu.nombre="Tofu";
    tofu.peso=5.2;
    tofu.raza="Chihuahua";
    tofu.color="Crema";
    cout << tofu.edad << endl;
    cout << tofu.nombre << endl;
    cout << tofu.peso << endl;
    cout << tofu.raza << endl;
    cout << tofu.color << endl;
    ladrar(tofu);
}