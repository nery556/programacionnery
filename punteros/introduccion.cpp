#include <iostream>
using namespace std;

int main(){
    /*Todas las variables tienen direcciones de memoria*/
    //Esas direcciones es como el lugar donde viven
    int a;
    a=10;
    float numflot;
    numflot=30;
    cout << "Imprime la direccion de la variable a" << endl;
    cout << &a << endl;
    cout << "Imprimiendo la direccion de la variable flotante" << endl;
    cout << &numflot << endl;
    /*
    HAY UN TIPO ESPECIAL DE VARIABLE
    SE LLAMAN LOS PUNTEROS
    LOS PUNTEROS GUARDAN DIRECCIONES DE MEMORIA DE OTRAS VARIABLES COMO VALOR    
    Se declaran asi: tipo_dato  *nombre_variable
    */
   //Estoy creando una variable de tipo puntero a entero
   int numero;
   int *ptr;
   ptr=&numero;
   //Mi variable ptr es de tipo puntero y guarda como valor la direccion de otra variable
   cout << &numero << endl;
   cout << ptr << endl;
   //Mi puntero ptr SOLO puede apunter a variables de tipo INT (entero)
   //Si yo quiero crear un puntero que apunte a flotantes
   float decimal;
   //Yo no puedo hacer algo como esto
   //ptr=&decimal;
   float *ptr2;

   //LOS PUNTEROS SON VARIABLES TAMBIEN
   //TAMBIEN TIENEN DIRECCIONES DE MEMORIA
   cout << &ptr << endl;



   

   



}