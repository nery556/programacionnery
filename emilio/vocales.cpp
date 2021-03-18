#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    system("cls");
    int numero;
    cout << "Dame un numero" << endl;
    cin >> numero;
    if ((numero>=8 && numero<=12) || (numero>=15 && numero<=18)){
        cout << "Eres adulto";
    }else{
        cout << "No eres adulto joven";
    }
    //un numero es impar si n%2==1
    //un numero es par si n%2==0
}