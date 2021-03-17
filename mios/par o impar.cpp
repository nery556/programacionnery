#include <iostream>
#include <math.h>
using namespace std;

int main(){
int numero;
cout << "ingresa un numero" << endl;
cin >> numero;
if(numero%2==1){
    cout << "es impar";
}else if(numero%2==0){
    cout << "es par";
}
return 0;

}