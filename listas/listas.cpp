/*
Listas ordenadas
Insertar elementos a una lista
1- Crear un nuevo nodo
2- Asignar a nuevo nodo el elemento (dato) que queremos incluir a la lista
3- Crear dos nodos aux y asignar lista al primero de ellos
4- Insertar el elemento a la lista

TD hacer lo mismo pero con cliente
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void buscarLista(Nodo *, int);
void eliminarNodo(Nodo *&, int);

int main() {
    Nodo *lista = NULL;

    int dato, opcion, elemento_buscado, elemento_eliminado;
    do {
        cout<<"\nElige una opcion:\n";
        cout<<"\t1- Insertar elementos a la lista\n";
        cout<<"\t2- Mostrar elementos de la lista\n";
        cout<<"\t3- Buscar un elemento en la lista\n";
        cout<<"\t4- Eliminar un elemento de la lista\n";
        cout<<"\t0- Salir\n";
        cin>>opcion;
        switch(opcion) {
            case 1: cout<<"Ingrese un entero: "; cin>>dato;
                insertarLista(lista, dato);
                break;
            case 2: cout<<"Mostrar lista"<<endl;
                mostrarLista(lista);
                break;
            case 3: cout<<"Ingrese el elemento que desea buscar: "; cin>>elemento_buscado;
                buscarLista(lista, elemento_buscado);
                break;
            case 4: cout<<"Ingrese el elemento que desea eliminar: "; cin>>elemento_eliminado;
                eliminarNodo(lista, elemento_eliminado);
                break;
            case 0: break;
            default: break;
        }
    } while (opcion != 0);

    return 0;
}

void insertarLista(Nodo *&lista, int n) {
    Nodo *nuevo_nodo = new Nodo(); // paso 1
    nuevo_nodo -> dato = n; // paso 2

    // paso 3
    Nodo *aux1 = lista;
    Nodo *aux2;

    // paso 4
    // 3 casos: lista vacia, lista con un elemento y lista con mas de un elemento
    // para insertar elementos a la lista seran 2 casos:
    // - Al principio de la lista
    // - Al medio o al final
    while ((aux1 != NULL) && (aux1 -> dato < n)) {
        aux2 = aux1;
        aux1 = aux1 -> siguiente;
    }
    if (lista == aux1) {    // siempre entra al if si el elemento va a l ppio de la lista
        lista = nuevo_nodo;
    } else {    // se ejecuta si va al medio o al final
        aux2 -> siguiente = nuevo_nodo;
    }
    nuevo_nodo -> siguiente = aux1;
}

void mostrarLista(Nodo *lista) {
    Nodo *actual = new Nodo();

    actual = lista;
    while (actual != NULL) {
        cout<<actual -> dato<<" -> ";
        actual = actual -> siguiente;
    }
}

void buscarLista(Nodo *lista, int n) {
    bool flat = false;

    Nodo *actual = new Nodo();
    actual = lista;
    while ((actual != NULL) && (actual -> dato <= n)) {
        if (actual -> dato == n) {
            flat = true;
        }
        actual = actual -> siguiente;
    }

    if (flat == true) {
        cout<<"Elemento "<<n<<" si ha sido encontrado en la lista\n";
    } else {
        cout<<"Elemento "<<n<<" no ha sido encontrado en la lista\n";
    }
}

void eliminarNodo(Nodo *&lista, int n) {
    if (lista != NULL) {
        Nodo *aux_borrar;
        Nodo *anterior = NULL;
        aux_borrar = lista;

        while ((aux_borrar != NULL) && (aux_borrar -> dato != n)) {
            anterior = aux_borrar;
            aux_borrar = aux_borrar -> siguiente;
        }

        if (aux_borrar == NULL) {
            cout<<"EL elemento no existe.\n";
        }
        else if (anterior == NULL) {
            lista = lista -> siguiente;
            delete aux_borrar;
        }
        else {
            anterior -> siguiente = aux_borrar -> siguiente;
            delete aux_borrar;
        }
    }
}