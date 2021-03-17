#include <iostream>
#include <math.h>

using namespace std;
int main (){
     int seleccion;
    float a,b,c,d;
    cout << "Bienvenido al menu matrematico"<< endl;
    cout << "presiona 1 si quieres hacer la expresion (a/b) +1"<< endl;
    cout << "presiona 2 si quieres hacer la expresion (a+b) / (c+d)"<< endl;
    cout << "presiona 3 si quieres hacer la expresion (a^2-3b+c)" << endl;
    cin >> seleccion;
    if (seleccion==1){
        cout << "dame 2 numeros"<< endl;
        cin >> a >> b;
        cout << (a/b) +1;
    
    }else if (seleccion==2){
        cout <<"dame 4 numeros"<< endl;
        cin >> a >> b >> c >> d;
        cout << (a+b)/(c+d);
    


    }else if(seleccion==3){
        cout << "dame 3 numeros" <<endl;
        cin >> a >> b >> c;
        cout <<pow(a,2)-3*b+c;

    }else {
        cout << "numeros incorrectos";
    }
    return 0;

}
    


       
       
       
       
       
        

    







