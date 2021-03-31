#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char *argv[]){
    cout << argc << endl;
    cout << argv[0] << endl;
    cout << argv[1] << endl;
    cout << argv[2] << endl;
    rename(argv[1],argv[2]);
    return 0;
}