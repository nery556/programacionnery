#include <iostream>
#include <math.h>
using namespace std;

typedef struct Punto{
    int x;
    int y;
}Punto;

typedef struct Paralelogramo{
    Punto punto1;
    Punto punto2;
    Punto punto3;
    Punto punto4;
}Paralelogramo;

int main(){
    /*struct Punto puntoejemplo;
    puntoejemplo.x=4;
    puntoejemplo.y=3;
    cout << "(" << puntoejemplo.x << "," << puntoejemplo.y << ")" << endl;
    struct Punto punto2;
    punto2.x=5;
    punto2.y=18;
    float distancia;
    distancia=sqrt( pow(puntoejemplo.x-punto2.x,2) + pow(puntoejemplo.y-punto2.y,2)  );
    cout << distancia;*/
    //Hacer un programa que pida las coordenadas de un punto y que imprima su cuadrante
    int coord1,coord2;
    cout << "Dame una coordenada";
    cin >> coord1 >> coord2;
    struct Punto punto1;
    punto1.x=coord1;
    punto1.y=coord2;
    if (punto1.x>0 && punto1.y>0){
        cout << "Esta en el cuadrante 1";
    }else if (punto1.x<=0 && punto1.y>0){
        cout << "Estas en el cuadrante 2";
    }else if (punto1.x<0 && punto1.y<0){
        cout << "Estas en el cuadrante 3";
    }else{
        cout << "estas en el cuadrante 4";
    }
    Paralelogramo p1;
    p1.punto1.x=10;
    p1.punto2.y=15;
    p1.punto2.x=20;
    p1.punto2.y=35;
    p1.punto3.x=18;
    p1.punto3.y=24;
    p1.punto4.x=1;
    p1.punto4.y=0;
    cout << "Dame el primer paralelogramo";
    Paralelogramo pal1;
    cin >> pal1.punto1.x; 


    return 0;
}