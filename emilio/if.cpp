#include <iostream>
#include <math.h>
using namespace std;

int main(){
    //HACER UN MENU DE RESTAURANTE
    int numero;
    cout << "Bienvenido al Restaurante El Ranchito" << endl;
    cout << "Escribe el numero que desees para ir a algun lugar" << endl;
    cout << "1. Irse a las bebidas" << endl;
    cout << "2. Irse a las entradas" << endl;
    cout << "3. Irse a las comidas" << endl;
    cout << "4. Irse a los postres" << endl;
    cout << "Presiona cualquier otra cosa para salir" << endl;
    cin >> numero;
    /*if (numero==1){
        cout <<"Bebidas";
    }else if(numero==2){
        cout << "Entradas";
    }else if(numero==3){
        cout << "Comidas";
    }else if(numero==4){
        cout << "Postres";
    }else{
        cout << "Has salido!";
    }*/
    switch(numero){
        case 1:
            cout << "Bebidas";
            break;
        case 2:
            cout << "Entradas";
            break;
        case 3:
            cout << "Comidas";
            break;
        case 4: 
            cout << "Postres";
            break;
        default:
            cout << "Has salido exitosamente";
            break;
    }
    return 0;
    
}