#include <iostream>
#include <math.h>
#include <string>
#include <tuple>
struct sillon{
    float size;
    char color[20];
    float price;


};
using namespace std;
int main (){
    const float pi=3.1415;
    string saludo;
    auto numero=16.5;
   // cout << sizeof(sillon);
    tuple <int,int>doble;
    doble=make_tuple(20,10);
    cout << get <0>(doble) << get <1>(doble) << endl;
    
    
    
    
    
    
    
    return 0;
}