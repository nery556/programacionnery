#include <iostream>
#include <time.h>
#include <stdlib.h>
/*
----------JUEGUITO--------------
HACER UN JUEGO EN DONDE YO TENGO QUE ADIVINAR UN NUMERO DEL 1 AL 10
LA COMPU ME VA A DAR UN NUMERO Y YO TENGO QUE ADIVINAR CUAL ES
SI ADIVINO, ME DICE QUE GANE, SI PIERDO ME DICE QUE PERDI
*/
using namespace std;
int main(){
    int num_aleatorio, mi_numero;
    srand(time(NULL));
    num_aleatorio=(rand()%10)+1;
    cout << "Adivina el numero" << endl;
    cin >> mi_numero;
    if (mi_numero==num_aleatorio){
        cout << "ADIVINASTE" << endl;
    }else{
        cout << "PERDISTE" << endl;
    }
    cout << "El numero era " << num_aleatorio;


    return 0;
}