#include <iostream>
#include <windows.h>
#include <cstdio>
using namespace std;
struct nodo{
	char info;
	struct nodo *izq;
	struct nodo *der;
};
typedef struct nodo arbol;
void ins_izq(arbol*,char);
void ins_der(arbol*, char);
void inOrden(arbol*);
void preOrden(arbol*);
void postOrden(arbol*);
void gotoxy(int x, int y);
void imp_arbol(arbol*,int,int);
int main(int argc, char *argv[]) {
	struct nodo *raiz,*q;
	int x,y;
	raiz=new arbol;
	
	raiz->info='A';
	raiz->izq=NULL;
	raiz->der=NULL;
	
	ins_izq(raiz,'B');
	ins_der(raiz,'C');
	
	q=raiz->der;
	ins_izq(q,'D');
	ins_der(q,'E');
	
	q=raiz->der->izq;
	ins_izq(q,'F');
	ins_der(q,'G');
	
	q=raiz->der->der;
	ins_izq(q,'I');
	ins_der(q,'J');
	
	cout<<"Pre Orden"<<endl;
	preOrden(raiz);
	cout<<endl<<endl;
	cout<<"In Orden"<<endl;
	inOrden(raiz);
	cout<<endl<<endl;
	cout<<"Post Orden"<<endl;
	cout<<endl;
	postOrden(raiz);
	x=40;
	y=5;
	imp_arbol(raiz,x,y);
	getchar();
}
void ins_izq(struct nodo *p,char n){
	arbol *nuevo;
	nuevo=new arbol;
	nuevo->info=n;
	nuevo->izq=NULL;
	nuevo->der=NULL;
	p->izq=nuevo;
}
void ins_der(struct nodo *p,char n){
	arbol *nuevo;
	nuevo=new arbol;
	nuevo->info=n;
	nuevo->izq=NULL;
	nuevo->der=NULL;
	p->der=nuevo;
}
void inOrden(arbol*ptrArbol){
	if(ptrArbol!=NULL){
		inOrden(ptrArbol->izq);
		cout<<" "<<ptrArbol->info;
		inOrden(ptrArbol->der);
	}
}
void preOrden(arbol *ptrArbol){
	if(ptrArbol!=NULL){
		cout<<" "<<ptrArbol->info;
		preOrden(ptrArbol->izq);
		preOrden(ptrArbol->der);
	}
}
void postOrden(arbol *ptrArbol){
	if(ptrArbol!=NULL){
		postOrden(ptrArbol->izq);
		postOrden(ptrArbol->der);
		cout<<" "<<ptrArbol->info;
	}
}
void imp_arbol(arbol *ptrArbol,int x, int y){
	if(ptrArbol!=NULL){
		gotoxy(x,y);
		cout<<ptrArbol->info;
		x=x-3;
		y=y+3;
		imp_arbol(ptrArbol->izq,x,y);
		x=x+6;
		imp_arbol(ptrArbol->der,x,y);
		y=y-3;
	}
}
void gotoxy(int x,int y){  
	HANDLE hcon;  
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}