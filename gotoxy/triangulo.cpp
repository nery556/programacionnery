#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;
void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
} 
int main(){
    system("cls");
    for (int i=0;i<20;i++){
        for (int j=0;j<20;j++){
            gotoxy(i,j);
            cout << "*";
        }
    }
}