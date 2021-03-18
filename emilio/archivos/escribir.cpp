#include <fstream>
#include <iostream>
#include <string>


using namespace std;

int main(){
    //Crea y abre un archivo de textos llamado prueba.txt
    ofstream Miarchivo("prueba.txt");

    int num=5;
    Miarchivo << num;



    //Cierra el archivo
    Miarchivo.close();

    
    return 0;
}
