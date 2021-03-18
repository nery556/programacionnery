#include <iostream>

using namespace std;


int main(){
    //Hacer un programa que me de un numero y me imprima CUANTOS factores tiene ese numero
    // 10 -> 2,5  =2
    // 8 -> 2,4  =2
    // 20 -> 2,5,10 = 3
    int numero, cuenta_factores=0;
    cout << "Dame un numero para ver cuantos factores tiene" << endl;
    cin >> numero;
    for (int factor=1;factor<=numero;factor=factor+1){
        if (numero%factor==0){
            cuenta_factores=cuenta_factores+1;
        }
    }
    cout << cuenta_factores;
    return 0;
}