#include <iostream>
#include <math.h>
#include <string>

using namespace std;
struct persona{
    string apellidomaterno;
    string apellidopaterno;
    string nombre;


};
int main (){
    struct persona papa,mama,hijo;
    cout << "dame el apellido materno de la madre";
    cin >> mama.apellidomaterno;
    cout << "dame el apellido paterno de la madre";
    cin >> mama.apellidopaterno;
    cout << "dame el nombre de la madre";
    cin >> mama.nombre;
    cout << "dame el apellido materno del padre";
    cin >> papa.apellidomaterno;
    cout << "dame el apellido paterno del padre";
    cin >> papa.apellidopaterno;
    cout << "dame el nombre del padre";
    cin >> papa.nombre;
    cout << "dame el nombre del hijo";
    cin >> hijo.nombre;
    hijo.apellidomaterno=mama.apellidopaterno;
    hijo.apellidopaterno=papa.apellidopaterno;

    cout << "el papa se llama " << papa.nombre  << " "<< papa.apellidopaterno  << " "<< papa.apellidomaterno << endl;
    cout << "la mama se llama " << mama.nombre  << " "<< mama.apellidopaterno << " " << mama.apellidomaterno << endl;
    cout << "el hijo se llama " << hijo.nombre << " "<< hijo.apellidopaterno << " " << hijo.apellidomaterno << endl;



    















return 0;




}