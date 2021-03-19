#include <iostream>
#include <math.h>

using namespace std;

int main (){
    int n;
    cout << "dame una cantidad de numeros a imprimir";
    cin >> n;
    for (int i=1; i<=n; i++){
        if(i%2==0){
            cout << "-1" << endl;
        }else{ 
            cout << "0" << endl;
        }
    }
    
    
    
    
    
    
    
    return 0;
}