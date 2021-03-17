#include <iostream>
#include <math.h>

using namespace std;

int main (){
    /*hacer un programa que te diga si un numero es positivo, negativo o cero */
    int numero;
    cout << "dame un numero" << endl;
    cin >> numero;
    if (numero>0){
        cout << "es positivo";
        
    }else if (numero<0){
        cout << "es negativo";
    }else if (numero==0){
        cout << "es cero";
    }
    return 0;



}
