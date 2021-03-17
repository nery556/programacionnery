#include <iostream>
#include <math.h>

using namespace std;
int main (){
int calificacion;
cout << "ingresa tu calificacion" << endl,
cin >> calificacion;
if(calificacion>=0 && calificacion <=100){
    if(calificacion>=90){
        cout << "A";
    }else if(calificacion>=80){
        cout << "B";
    }else if(calificacion>=70){
        cout << "C";    
    }else if(calificacion>=60){
        cout << "D";
    }else if(calificacion>=40){
        cout <<"E";
    }else if(calificacion<40){
        cout<< "F";
    }

}else {
    cout << "pusiste un rango diferente";
    return 0;

}






}