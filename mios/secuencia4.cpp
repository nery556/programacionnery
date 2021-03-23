#include <iostream>
using namespace std;
int main(){
    cout << "Dame una cant de numeros";
    int cant;
    cin >> cant;
    int impresion=1, i=1;
    for (i=1, impresion=1;i<=cant;i++, impresion=impresion*10){
        cout << impresion << endl;
    }
    i=1;
    impresion=1;
    for (/*nada*/;i<=cant;/*nada*/){
        cout << impresion << endl;
        i++;
        impresion=impresion*10;
    }
    


    return 0;
}