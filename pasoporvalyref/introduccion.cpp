#include <iostream>

using namespace std;
/*YO NO LE ESTOY PASANDO LA VARIABLE, LE ESTOY PASANDO UNA COPIA POR VARIABLE
A ESTO SE LE LLAMA PASO POR VALOR
YO NO LE PASO A MI FUNCION LA VARIABLE COMO TAL, YO LE ESTOY PASANDO UNA COPIA
ESTOY CREANDO UNA COPIA Y SE LA PASO A LA FUNCION
*/
void multiplicarpor2(int x){
    x=x*2;
}
//TODAS LAS FUNCIONES AUTOMATICAMENTE SON DE PASO POR VALOR
/*

*/
//YA NO ESTOY PASANDOLE YO UNA COPIA, LE ESTOY PASANDO UNA DIRECCION QUE ES LO MISMO
//QUE UN PUNTERO
void multpor2(int *x){
    *x=*x *2;
}

int main(){
    int a=10,*p;
    p=&a;
    multiplicarpor2(a);
    cout << a << endl;
    multpor2(p);
    cout << a << endl;
    
    
}