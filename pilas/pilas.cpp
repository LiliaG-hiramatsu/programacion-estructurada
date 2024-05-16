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
    Nodo *siguiente;    // siguiente solo puede apuntar a una estructura de tipo Nodo.
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
    Nodo *nuevo_nodo = new Nodo(); // paso 1: Crear el espacio en memoria para almacenar el nodo
    nuevo_nodo -> dato = n; // paso 2: Cargar el valor dentro del nodo (dato)
    nuevo_nodo -> siguiente = pila; // paso 3: Cargar el puntero pila dentro del nodo *siguiente (en la primera iteracion sera NULL, pero en la proximas llamadas seran direcciones de memoria)
    pila = nuevo_nodo; // paso 4: Asignar el nuevo nodo a pila - se copia la estructura en pila. En la primera llamada no hace nada ya que pila es NULL.
    // en la segunda llamada pila va a tener el dato (por ej un 7) y una direccion de memoria

    cout<<"\nElemento "<<n<<" agregado a pila correctamente."<<endl;
}

void sacarPila(Nodo *&pila, int &n) {
    Nodo *aux = pila; // paso 1: Crear una variable auxiliar de tipo Nodo e igualarlo a pila. Se hace una copia del ultimo nodo de la pila (tiene el dato y la direccion de memoria del siguiente nodo)
    n = aux -> dato; // paso 2: almacena el dato sacado de aux (que tiene la estructura) en n.
    pila = aux -> siguiente; // paso 3: guarda el puntero siguiente de la estructura aux en la pila.
    delete aux; // paso 4: Eliminar el nodo aux
}