#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main(){
    float a,b,c;
    a=45;
    b=16;
    //cout << "Dame dos numeros" << endl;
    /*cin >> a >> b;
    cout << "La suma es " << a+b << endl;
    cout << "La resta es " << a-b << endl;
    cout << "La multiplicacion es " << a*b << endl;
    cout << "La division es " << a/b << endl;
    cout << "El primer numero elevado al segundo numero es " << pow(a,b);*/

    c=a+b;
    c=a-b;
    c=a*b;
    c=a/b;
    a++; // a=a+1
    a+=10; //a=a+10
    a-=8; //a=a-8
    /*int numero1,numero2, aux;
    cin >> numero1 >> numero2;
    aux=numero1;
    numero1=numero2;
    numero2=aux;
    cout << numero1 << endl << numero2;*/

    /*string cadena="1234";
    int numero;
    numero=stoi(cadena);
    cout << numero+1;*/

    /*
    itoa = integer a string
    stoi= string a integer
    
    */

   //MODULO SOLO TRABAJA SOBRE ENTEROS

   int n1=13, n2=5;
   cout << n1%n2;
   


    return 0;

}