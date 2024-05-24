/*
Crear dos listas.
Crear un menú que permita ingresar dinámicamente el llenado de las mismas.
Y siempre deben existir estructuras de tipo CLIENTE (nombre, dni, edad).
Comparar una lista con la otra y decirme si hay edades REPETIDAS.
Luego de eso deben crear otra función que me permita decir el MAYOR DNI de cada estructura.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Cliente {
    char nombre[30];
    int edad;
    int dni;
};

struct Nodo {
    Cliente c;
    Nodo *siguiente;
};

void menu();
void ingresarCliente(Cliente &);
void insertarLista(Nodo *&, Cliente);
void mostrarLista(Nodo *);
void compararListas(Nodo *, Nodo *);
void mayorDni(Nodo *);

int main() {
    menu();
    return 0;
}

void menu() {
    int opcion, opcion_lista;
    Nodo *lista1 = NULL;
    Nodo *lista2 = NULL;
    Cliente cliente;

    do {
        cout<<"\tMENU\n";
        cout<<"1. Ingresar un cliente a la lista 1\n";
        cout<<"2. Ingresar un cliente a la lista 2\n";
        cout<<"3. Mostrar lista de clientes\n";
        cout<<"4. Comparar listas\n";
        cout<<"5. Mostrar el mayor DNI\n";
        cout<<"0. Salir\n\n";
        cout<<"Opcion: "; cin>>opcion;
        switch(opcion) {
            case 1: cout<<"\tIngresar un cliente a la pila 1:\n";
                    ingresarCliente(cliente);
                    insertarLista(lista1, cliente);
                    cout<<"El cliente se agrego correctamente a la lista 1.\n\n";
                    system("pause");
                    break;
            case 2: cout<<"\tIngresar un cliente a la lista 2:\n";
                    ingresarCliente(cliente);
                    insertarLista(lista2, cliente);
                    cout<<"El cliente se agrego correctamente a la lista 2.\n\n";
                    system("pause");
                    break;
            case 3: cout<<"\tMostrar lista de clientes\n";
                    cout<<"Elija la lista a mostrar\n";
                    cout<<"\t1. Lista 1\n";
                    cout<<"\t2. Lista 2\n";
                    cout<<"Opcion: "; cin>>opcion_lista;
                    cout<<"\tMostrando lista "<<opcion_lista<<":\n";
                    if (opcion_lista == 1) mostrarLista(lista1);
                    if (opcion_lista == 2) mostrarLista(lista2);
                    else cout<<"No existe la opcion ingresada. Vuelva a intentarlo.\n";
                    break;
            case 4: cout<<"Comparar listas:\n";
                    compararListas(lista1, lista2);
                    break;
            case 5: cout<<"\tMayor DNI\n";
                    cout<<"Elija la lista de la cual quiere saber el mayor DNI\n";
                    cout<<"\t1. Lista 1\n";
                    cout<<"\t2. Lista 2\n";
                    cout<<"Opcion: "; cin>>opcion_lista;
                    cout<<"\tLista "<<opcion_lista<<":\n";
                    if (opcion_lista == 1) mayorDni(lista1);
                    if (opcion_lista == 2) mayorDni(lista2);
                    else cout<<"No existe la opcion ingresada. Vuleva a intentarlo.\n";
                    break;
            case 0: break;
            default: break;
        }
        system("cls");
    } while (opcion != 0);
}

void ingresarCliente(Cliente &p) {
    fflush(stdin);
    cout<<"\tIngresar los datos del cliente:\n";
    cout<<"Nombre: "; cin.getline(p.nombre, 30, '\n');
    cout<<"Edad: "; cin>>p.edad;
    cout<<"DNI: "; cin>>p.dni;
}

// Agrego los nodos a medida que el usuario va agregando un cliente (o sea al final de la lista)
void insertarLista(Nodo *&lista, Cliente p) {
    Nodo *nuevo_nodo = new Nodo();
    Nodo *aux;

    nuevo_nodo -> c = p;
    nuevo_nodo -> siguiente = NULL;

    if (lista == NULL) {
        lista = nuevo_nodo; // primer cliente
    } else {
        aux = lista; // auxiliar apunta al inicio de la lista
        while (aux -> siguiente != NULL) { // recorre la lista
            aux = aux -> siguiente;
        }
        // cuando aux -> siguiente = NULL, entonces llegamos al final de la lista
        // y podemos agregar el nuevo nodo a la lista
        aux -> siguiente = nuevo_nodo;
    }
}

void mostrarLista(Nodo *lista) {
    while (lista != NULL) {
        cout<<"Nombre: "<<lista -> c.nombre<<endl;
        cout<<"Edad: "<<lista -> c.edad<<endl;
        cout<<"DNI: "<<lista -> c.dni<<endl;
        cout<<"\n";
        lista = lista -> siguiente;
    }
    system("pause");
}

void compararListas(Nodo *lista1, Nodo *lista2) {
    while (lista1 != NULL) {
        Nodo *aux = new Nodo();
        aux = lista2;
        while (aux != NULL) {
            if ((lista1 -> c.edad) == (aux -> c.edad)) {
                cout<<"Si hay edades repetidas.\n";
                cout<<"La edad que se repite es: "<<aux -> c.edad<<" anios.\n";
                cout<<"Pertenecen a "<<aux -> c.nombre<<" y a "<<lista1 -> c.nombre<<endl;
            }
            aux = aux -> siguiente;
        }
        lista1 = lista1 -> siguiente;
    }
    cout<<"\n";
    system("pause");
}

void mayorDni(Nodo *lista) {
    int mayor = 0;
    while (lista != NULL) {
        if ((lista -> c.dni) > mayor) mayor = lista -> c.dni;
        lista = lista -> siguiente;
    }
    cout<<"El DNI mas grande es: "<<mayor<<endl;
    system("pause");
}