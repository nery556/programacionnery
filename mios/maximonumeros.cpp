#include <iostream>
#include <math.h>

using namespace std;

int main (){
    float num1,num2,num3;
    cout << "DAME TRES NUMEROS";
    cin >> num1 >> num2 >> num3;
    if(num1>=num2 && num1>=num3){
        cout << "es mayor el" << num1;
    }else if (num2>=num1 && num2>=num3){
        cout << "es mayor el" << num2;
    } else if (num3>=num1 && num3>=num2){
        cout << "es mayot el" << num3;
    }
    return 0;








}