#include <iostream>
#include <string>
using namespace std;
//EXISTE UN METODO ESPECIAL QUE SE LLAMA CONSTRUCTOR
//ESE CONSTRUCTOR SE LLAMA CUANDO SE CREA UN OBJETO
//SIRVE PARA DARLE VALOR INICIAL A LOS ATRIBUTOS
class audifono{
    private:
    string resistencia;
    string color;
    bool manoslibres;
    public:
    //CONSTRUCTOR
    audifono(string res, string col, bool mali){
        resistencia=res;
        color=col;
        manoslibres=mali;
    }
       
};
int main(){
    
    audifono airpod("alta","blanco","true");

}