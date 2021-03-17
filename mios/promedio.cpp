#include <iostream>


using namespace std;

//hacer un programa que te pida "n" numeros y te de como resultado tu promedio de los "n" numeros
int main (){
    int n, calif, suma=0;
    
    cout << "dame una cantidad de numeros";
    cin >> n;
    for (int i=1; i<=n; i++){
        cout << "dame una calificacion";
        cin >> calif;
        suma=suma+calif;
        
    }
    cout << suma/n;
    return 0;





}