#include <iostream>
#include <string>

#define pi 3.1415
#define true 1
#define false 0
#define MAX 50
using namespace std;


typedef struct Libro{
    int numpags;
    string autor;
    string genero;
    string titulo;
    int ID;
}Libro;
int main(){
    Libro libro1;
    libro1.numpags=550;
    libro1.titulo="Don Quijote de la Mancha";
    libro1.genero="Historia";
    libro1.ID=12345789;
    libro1.autor="Miguel de Cervantes Saavedra";
    cout << libro1.autor << endl;
    cout << libro1.genero << endl;
    Libro libro2;



    return 0;
}