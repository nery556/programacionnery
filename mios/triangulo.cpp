#include <iostream>
#include <math.h>

using namespace std;
int main (){
    int filas;
    cout << "dame un cantidad de filas";
    cin >> filas;
    for(int fila_actual=1; fila_actual<=filas ; fila_actual++){
        cout << "estas en la fila" << fila_actual;
        for(int j=1; j<=fila_actual; j++){
            cout << "*";
        }
       cout << endl;
    }

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}