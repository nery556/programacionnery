#include <iostream>
#include <math.h>
#include <tuple>
#include <string>

using namespace std;

int main(){
     tuple <int,int>doble;
    doble=make_tuple(20,10);
    cout << get <0>(doble) << get <1>(doble) << endl;
    tuple <string,string>nobios;
    nobios=make_tuple("emilio","pau");
    tuple <string,string>nobios2;
    nobios2=make_tuple("juan","rodrigo");
    swap(nobios,nobios2);
    cout << get <0> (nobios);
    


    
    


    return 0;
}