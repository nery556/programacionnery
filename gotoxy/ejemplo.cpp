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
    gotoxy(0,0);
    cout << "Empieza";
    gotoxy(0,1);
    cout << "Hola como estan";
    gotoxy(5,5);
    cout << "x";
    gotoxy(10,10);
    cout << "x";
}