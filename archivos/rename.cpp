#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    char antiguo[50],nuevo[50];
    cout << "Dame el nombre de tu archivo" << endl;
    cin  >> antiguo;
    cout << "Dame el nombre de tu nuevo archivo" << endl;
    cin >> nuevo;
    rename(antiguo,nuevo);
    
}