#include <iostream>
#include <string>
using namespace std;

class Carro{
    private:
    //Atributos
    string color;
    string marca;
    string modelo;
    int anio;
    public:
    //Metodos y setters y getters
    void setColor(string colorquemedan){
        color=colorquemedan;
    }
    string getColor(){
        return color;
    }

};

int main(){
    Carro micarro;
    string colorsillo;
    micarro.setColor("Azul");
    colorsillo=micarro.getColor();
    cout << colorsillo;
}