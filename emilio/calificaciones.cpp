#include <iostream>
using namespace std;
int main(){
    int calificacion;
    cout << "Dame una calificacion" << endl;
    cin >> calificacion;
    if (calificacion>=0 && calificacion<=100){
        if (calificacion>=40 && calificacion<=49){
            cout << "E";
        }else if (calificacion>=60 && calificacion<=69){
            cout << "D";
        }else if(calificacion>=70 && calificacion<=79){
            cout << "C";
        }else if (calificacion>=80){
            cout << "B";
        }else if (calificacion>=90){
            cout << "A";
        }else if (calificacion<40){
            cout << "F";
        }
    }


    return 0;
}