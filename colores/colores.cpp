#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include "../milibreria.h"
using namespace std;

int main(){
    //system(color <colordefondo><colordeletra>)
    system("cls");
    system("Color 70");
    //Regresar al color normal
    system("Color 07");


    colorrojo();
    cout << "Hola como estas" << endl;
    colorazul();
    cout << "Mi nombre es Nery" << endl;
    colormorado();
    cout << "Esto es morado" << endl;
    coloramarillo();
    cout << "Esto es amarillo " << endl;
    colorblanco();
    cout << "Esto es negro"<< endl;
    colorcyan();
    cout << "que color es esto" << endl;

    int maximo;
    maximo=max(5,8);
    cout << maximo;
}