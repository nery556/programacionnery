#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
void colorrojo(){
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
}
void colorblanco(){
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);   
}
void colormorado(){
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED |FOREGROUND_BLUE);
}
void coloramarillo(){
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED |FOREGROUND_GREEN);
}
void colorazul(){
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
}
void colorcyan(){
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN |FOREGROUND_BLUE);
}
int max(int a, int b){
    if (a>b){
        return a;
    }else{
        return b;
    }
}