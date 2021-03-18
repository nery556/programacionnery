#include <iostream>


using namespace std;
struct Bloque{
    string nombre;
    string material;
    float dureza;
    float grosor;



};

int main(){
    struct Bloque madera;
    madera.nombre="Madera";
    madera.dureza=15.5;
    
    return 0;
}