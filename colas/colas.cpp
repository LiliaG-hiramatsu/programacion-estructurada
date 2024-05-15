/*
COLAS: Estructura FIFO (first in first out)
Se insertan por un extremo (final) y se extraen por el otro extremo (frente)
Frente y final son los punteros

Insertar elementos:
1- Crear espacio en memoria para almacena un nodo
2- Asignar ese nuevo nocdo al dato que queremos insertar
3- Asignar los punteros frente y fin hacia el nuevo nodo

Eliminar elementos:
1- Obtener el valor del nodo.
2- Crear un nodo aux y asignarle el frente de la cola.
3- Eliminar el nodo del frente de la cola.

TAREA insertar datos con un menu (si no)
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

void insertarCola(Nodo *&, Nodo *&, int);
bool cola_vacia(Nodo *);
void eliminarCola(Nodo *&, Nodo *&, int &);

int main() {
    Nodo *frente = NULL;
    Nodo *fin = NULL;

    int dato;
    cout<<"Ingresar un numero entero: "; cin>>dato;
    insertarCola(frente, fin, dato);

    cout<<"Ingresar un numero entero: "; cin>>dato;
    insertarCola(frente, fin, dato);

    cout<<"Ingresar un numero entero: "; cin>>dato;
    insertarCola(frente, fin, dato);

    // Eliminando los elementos de la cola
    cout<<"\nEliminando los nodos de la cola: "<<endl;
    while (frente != NULL) {    // si frente no es NULL, significa que hay mas nodos en la cola
        eliminarCola(frente, fin, dato);
        if (frente != NULL) {
            cout<<dato<<", ";
        } else {    // cuando ya no hayan mas nodos, significa que es el ultimo dato
            cout<<dato<<".";
        }
    }
    return 0;
}

void insertarCola(Nodo *&frente, Nodo *&fin, int n) {
    // paso 1
    Nodo *nuevo_nodo = new Nodo();

    // paso 2
    nuevo_nodo -> dato = n;
    nuevo_nodo -> siguiente = NULL;

    // paso 3
    if(cola_vacia(frente)) {
        frente = nuevo_nodo;
    } else {
        fin -> siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;

    cout<<"Elemento "<<n<<" insertado a la cola correctamente."<<endl;
}

// funcion para determinar si la cola esta vacia o no
bool cola_vacia(Nodo *frente) { //pq no pasa con un &
    return (frente == NULL) ? true : false;
    /*
    if(frente == NULL) {
        return true;
    } else {
        return false;
    }
    */
}

void eliminarCola(Nodo *&frente, Nodo *&fin, int &n) {
    // paso 1
    n = frente -> dato;

    // paso 2
    Nodo *aux = frente;

    // paso 3 - hay que ver si hay un nodo o mas de un nodo
    if (frente == fin) {
        frente = NULL;
        fin = NULL;
    } else {
        frente = frente -> siguiente;
    }
    delete aux;
}