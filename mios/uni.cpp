#include <iostream>
#include <math.h>
#include <string>
using namespace std;

typedef struct datos{
    int semestre;
    string nombre;
    string apellidomaterno;
    string apellidopaterno;
    float promedio;
    int edad;

}datos;
int main (){
    struct datos alumn1; 
    alumn1.semestre=4;
     alumn1.nombre="Juan Rodolfo";
     alumn1.apellidomaterno="Sanchez";
     alumn1.apellidopaterno="Guzman";
    alumn1.promedio=8.6;
    alumn1.edad=17;
    cout << alumn1.semestre << endl;
    cout << alumn1.nombre << endl;
    cout << alumn1.apellidomaterno << endl;
    cout << alumn1.apellidopaterno << endl;
    cout << alumn1.promedio << endl;
    cout << alumn1.edad << endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
     return 0;
}