#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int n1,n2;
    n1=10;
    n2=20;
    cout << n1 << n2 << endl;
    swap (n1,n2);
    cout << n1 << n2 << endl;
    min(n1,n2);
    max(n1,n2);
    cout << min(n1,n2) << endl;
    cout << max(n1,n2) << endl;
    int orden[4];
    orden [0]=1;
    orden [1]=2;
    orden [2]=3;
    orden [3]=4;
    while(next_permutation(orden,orden+4)){
    cout << orden[0] << orden [1] << orden [2] << orden [3] << endl;

    }










    return 0;
}