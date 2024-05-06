/*
PILAS: Estructura LIFO (last in first out) introducir o eliminar por el mismo extremo "cima"
insertar (push)
quitar (pop)
La salida es inversa a la entrada. Ej. si entra M-A-C sale C-A-M

Insertar elementos en una pila:
1- Crear el espacio en memoria para almacenar el nodo
2- Cargar el valor dentro del nodo (dato)
3- Cargar el puntero pila dentro del nodo (*siguiente)
4- Asignar el nuevo nodo a pila

Quitar elementos de una pila:
1- Crear una variable auxiliar de tipo Nodo e igualarlo a pila: Nodo *aux = pila;
SUPER IMPORTANTE LO DEL AUX COPIA DE LA PILA (los originales no los tocas)
2- n = aux->dato
3- Pasar pila a siguiente nodo: pila = aux -> siguiente;
4- Eliminar el nodo aux: delete aux;
*/
#include<iostream>
#include<stdlib.h>

using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

void agregarPila(Nodo *&, int); // prototipo --- firma del metodo
void sacarPila(Nodo *&, int &);

int main() {
    Nodo *pila = NULL; // el puntero esta vacio
    int dato;
    cout<<"Ingresar un numero: "; cin>>dato;
    agregarPila(pila, dato);

    cout<<"Ingresar otro numero: "; cin>>dato;
    agregarPila(pila, dato);

    cout<<"\nSacando los elemntos de la pila: ";
    while (pila != NULL) { // mientras no sea el final de la pila
        sacarPila(pila, dato);
        if (pila != NULL) {
            cout<<dato<<", ";
        } else {
            cout<<dato<<".";
        }
    }

    return 0;
}

void agregarPila(Nodo *&pila, int n) {
    Nodo *nuevo_nodo = new Nodo(); // paso 1
    nuevo_nodo -> dato = n; // paso 2
    nuevo_nodo -> siguiente = pila; // paso 3
    pila = nuevo_nodo; // paso 4

    cout<<"\nElemento "<<n<<" agregado a pila correctamente."<<endl;
}

void sacarPila(Nodo *&pila, int &n) {
    Nodo *aux = pila; // paso 1
    n = aux -> dato; // paso 2
    pila = aux -> siguiente; // paso 3
    delete aux; // paso 4
}