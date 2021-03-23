#include <iostream>
using namespace std;

int main(){
    cout << "Dame una cantidad de numeros" << endl;
    int cant;
    cin >> cant;
    int primero=0, segundo=1, tercero;
    for (int i=1;i<=cant;i++){
        tercero=primero+segundo;
        cout << primero << endl;
        primero=segundo;
        segundo=tercero;
    }



    return 0;
}