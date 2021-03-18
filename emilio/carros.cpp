#include <iostream>
#include <string>

using namespace std;

typedef struct Carro{
    string modelo;
    string marca;
    string color;
    int numpuertas;
    int precio;
    string tipoMotor;
    double velocidadmaxima;
}Carro;

int main(){

    
    Carro carro1;
    carro1.marca="Koenigsseg";
    carro1.modelo="Special One";
    carro1.color="Turquesa";
    carro1.numpuertas=2;
    carro1.precio=100000000;
    cout << carro1.marca;
    Carro carro2;


    return 0;
}