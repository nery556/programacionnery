#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
int main(){
    int num,i;
    vector<int>conjunto;
    cout << "dame 5 numeros";
    for(i=1; i<=5; i++){
        cin >> num;
        conjunto.push_back(num);
    }
    cout << conjunto.size();
    conjunto.pop_back();
    cout << conjunto.size();

   
    return 0;
}