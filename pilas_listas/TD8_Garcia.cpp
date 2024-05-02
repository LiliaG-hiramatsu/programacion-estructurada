/*
Hacer un programa en C++, utilizando Pilas que contenga el 
siguiente menu:
1. Insertar un caracter a la pila
2. Mostrar todos los elementos de la pila
3. Salir
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

struct Nodo {
    char dato;
    Nodo *siguiente;
};

void agregarPila(Nodo *&, char);
void sacarPila(Nodo *&, char &);

int main() {
    Nodo *pila = NULL;
    char dato;
    int opcion;
    bool flat = true;

    while (flat) {
        cout<<"1. Pulse 1 para insertar un caracter a la pila."<<endl;
        cout<<"2. Pulse 2 para mostrar los elementos de la pila."<<endl;
        cout<<"3. Pulse 3 para salir."<<endl;
        cin>>opcion;
        if (opcion == 1) {
            cout<<"Digite un caracter: ";
            cin>>dato;
            agregarPila(pila, dato);
        }
        else if (opcion == 2) {
            cout<<"\nSacando todos los elementos de Pila: ";
            while (pila != NULL) {
                sacarPila(pila, dato);
                if (pila != NULL) {
                    cout<<dato<<"  ";
                } else {
                    cout<<dato<<"."<<endl;
                }
            }
        }
        else if (opcion == 3) {
            flat = false;
        } else {
            cout<<"Debe ingresar una opcion valida."<<endl;
            flat = false;
        }
    }
    cout<<"Ha salido del programa con exito."<<endl;
    return 0;
}

void agregarPila(Nodo *&pila, char n) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo -> dato = n;
    nuevo_nodo -> siguiente = pila;
    pila = nuevo_nodo;

    cout<<"Elemento "<<n<<" agregado a PILA correctamente."<<endl;
}

void sacarPila(Nodo *&pila, char &n) {
    Nodo *aux = pila;
    n = aux -> dato;
    pila = aux -> siguiente;
    delete aux;
}