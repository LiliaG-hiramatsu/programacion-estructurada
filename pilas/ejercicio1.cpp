/*
Hacer un programa para agregar numeros enteros a una pila
hasta que el usuario lo decida, y despues mostrar todos los 
numeros introducidos en la pila.
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

void agregarPila(Nodo *&, int);
void sacarPila(Nodo *&, int &);

int main() {
    Nodo *pila = NULL;
    int dato;
    char rpt;

    do{
        cout<<"Digite un numero: ";
        cin>>dato;
        agregarPila(pila, dato);
        cout<<"\nDesea agregar otro elemento a PILA(s/n): ";
        cin>>rpt;
    } while((rpt=='S')||(rpt=='s'));

cout<<"\nSacando todos los elementos de Pila: ";
while (pila != NULL) {
    sacarPila(pila, dato);
    if (pila != NULL) {
        cout<<dato<<"  ";
    } else {
        cout<<dato<<"."<<endl;
    }
}

    return 0;
}

void agregarPila(Nodo *&pila, int n) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo -> dato = n;
    nuevo_nodo -> siguiente = pila;
    pila = nuevo_nodo;

    cout<<"Elemento "<<n<<" agregado a PILA correctamente."<<endl;
}

void sacarPila(Nodo *&pila, int &n) {
    Nodo *aux = pila;
    n = aux -> dato;
    pila = aux -> siguiente;
    delete aux;
}