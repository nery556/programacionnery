#include <iostream>
#include <math.h>
using namespace std;
//Estamos creando una funcion que se llama maximo
//Esta funcion recibe dos argumentos (parametros) que son dos enteros
//un entero que se llama a y otro entero que se llama b
//esta funcion va a retornar un numero entero, que correspondera
//al mayor de esos dos numeros
int maximo(int a, int b){
    if (a>b){
        return a;
    }else{
        return b;
    }
}
bool esPar(int x){
    if (x%2==0){
        return true;
    }else{
        return false;
    }
}
float suma(float num1,float num2){
    float resultado;
    resultado=num1+num2;
    return resultado;
}
float promedio(float num1, float num2,float num3, float num4,float num5){
    float res;
    res=(num1+num2+num3+num4+num5)/5;
    return res;
}
float multiplicacion(float x,float y,float z){
    float resultado;
    resultado=x*y*z;
    return resultado;
}
void imprimirhola(){
    cout << "Hola mundo" << endl;
}
void imprimirnombre(string nombre){
    cout << "Hola " << nombre << " como estas" << endl;
}
float raiz(float x){
    float resultado;
    resultado=pow(x,0.5);
    return resultado;
}
bool tellamasPedro(string nom){
    if (nom=="Pedro"){
        return true;
    }else{
        return false;
    }
}
void impnombrecompleto(string nom, string appat, string apmat){
    cout << nom << " " << appat << " " << apmat << endl;
    
}
bool esPrimo(int numero1){
    
}
int main(){
    int a, b;
    cout << "Dame los numeros" << endl;
    cin >> a >> b;
    int c;
    c=maximo(a,b);
    cout << c << endl;
    c=maximo(15,12);
    cout << c << endl;
    c=maximo(20,25);
    cout << c << endl;
    imprimirhola();
    /*if (esPar(28)){
        cout << "Hola mundo";
    }*/
    c=multiplicacion(a,b,288);
    int numero=3943;
    int otronumero=349584;
    int res;
    res=suma(numero,otronumero);
    int resultado;
    resultado=promedio(24,34.6,256.7,245.2,9.5);
    /*imprimirnombre("Juan");
    imprimirnombre("Marco");
    imprimirnombre("Jesus");*/
    float operacion;
    operacion=raiz(10);
    resultado=pow(10,2);


    impnombrecompleto("Ramiro","Vazquez","Juarez");

    return 0;
}