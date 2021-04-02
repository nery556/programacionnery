#include <iostream>
using namespace std;

int max(int a, int b){
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

int main(){
    //En el main va el codigo que se va a ejecutrar
    int a, b, maximo;
    bool par;
    cout << "Dame el valor de a" << endl;
    cin >> a;
    cout << "Dame el valor de b" << endl;
    cin >> b;
    maximo=max(a,b);
    cout << "El maximo es " << maximo;
    par=esPar(a);
}