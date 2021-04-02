#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
int main (){
    int n,numer,i,min,actual;
    cout << "dame una cantidad de numeros";
    cin >> n;
    cout << "dame los numero";
    vector<int>prom;
    for(i=1; i<=n; i++){
        cin >> numer;
        prom.push_back(numer);
    }
    for(i=0; i<n; i++){
        actual=prom.at(i);
        if(i==0){
            min=actual;
        }
        if(actual<min){
            min=actual;
        }
    }
    cout << "el menor es" << min;
    
   
   
   
    return 0;
}