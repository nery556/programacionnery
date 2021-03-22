#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main (){
    
    int numeroaleatorio;
    srand(time(NULL));
    numeroaleatorio=rand()%2;
    cout << numeroaleatorio;
   
   
   
   
    return 0;

}