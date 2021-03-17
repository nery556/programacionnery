#include <iostream>
#include <math.h>

using namespace std;

int main (){
    int edad;
    cout << "dame tu edad";
    cin >> edad;
    if (edad<17){
        cout <<"invalido";
    }else if(edad>=17 && edad<=20){
        cout << "su salario es $300";
    }else if(edad>=21 && edad<=25){
        cout << "su salario es $1000";
    }else if(edad>=26 && edad<=35){
        cout << "su salario es $4000";
    }else if (edad>=35){
        cout << "su salario es $10000";
    }

return 0;




}