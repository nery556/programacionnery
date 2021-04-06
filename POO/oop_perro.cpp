#include <iostream>
#include <string>
using namespace std;
class Perro{
    //atributos
    private:
    string nombre;
    int edad;
    float peso;
    string raza;
    string color;
    public:
    //setters
    void setNombre(string nom){
        nombre=nom;
    }
    void setEdad(int ed){
        edad=ed;
    }
    void setPeso(int pe){
        peso=pe;
    }
    void setRaza(int ra){
        raza=ra;
    }
    void setColor(int abc){
        color=abc;
    }
    //getters
    string getNombre(){
        return nombre;
    }
    //metodos normales
    void ladrar(){
        cout << "WOOF WOOF";
    }
    void saltar(){
        cout << "ESTOY SALTANDO ";
    }

};



int main(){
    Perro firu;
    firu.setNombre("Firulais");
    cout << firu.getNombre() << endl;

    firu.ladrar();
    firu.saltar();
}
