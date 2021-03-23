#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int main(){
    char caracter;
    caracter=getchar();
    cout << caracter << endl;

    int numeroaleatorio;
    srand(time(NULL));
    numeroaleatorio=(rand() % 2) + 1;
    cout << numeroaleatorio ;
    //rand crea un numero entre 0 y 32767
}