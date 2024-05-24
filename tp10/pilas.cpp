/*
Crear dos pilas.
Crear un menú que permita ingresar dinámicamente el llenado de las mismas.
Y siempre deben existir estructuras de tipo CLIENTE (nombre, dni, edad).
Comparar una pila con la otra y decirme si hay edades REPETIDAS.
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
void agregarPila(Nodo *&, Cliente);
void mostrarPila(Nodo *, Cliente &);
void compararPilas(Nodo *, Nodo *);
void mayorDni(Nodo *);

int main() {
    menu();
    return 0;
}

void menu() {
    int opcion, opcion_pila;
    Nodo *pila1 = NULL;
    Nodo *pila2 = NULL;
    Cliente cliente;

    do {
        cout<<"\tMENU\n";
        cout<<"1. Ingresar un cliente a la pila 1\n";
        cout<<"2. Ingresar un cliente a la pila 2\n";
        cout<<"3. Mostrar pila de clientes\n";
        cout<<"4. Comparar pilas\n";
        cout<<"5. Mostrar el mayor DNI\n";
        cout<<"0. Salir\n\n";
        cout<<"Opcion: "; cin>>opcion;
        switch(opcion) {
            case 1: cout<<"\tIngresar un cliente a la pila 1:\n";
                    ingresarCliente(cliente);
                    agregarPila(pila1, cliente);
                    cout<<"El cliente se agrego correctamente a la pila 1.\n\n";
                    system("pause");
                    break;
            case 2: cout<<"\tIngresar un cliente a la pila 2:\n";
                    ingresarCliente(cliente);
                    agregarPila(pila2, cliente);
                    cout<<"El cliente se agrego correctamente a la pila 2.\n\n";
                    system("pause");
                    break;
            case 3: cout<<"\tMostrar pila de clientes\n";
                    cout<<"Elija la pila a mostrar\n";
                    cout<<"\t1. Pila 1\n";
                    cout<<"\t2. Pila 2\n";
                    cout<<"Opcion: "; cin>>opcion_pila;
                    cout<<"\tMostrando pila "<<opcion_pila<<":\n";
                    if (opcion_pila == 1) mostrarPila(pila1, cliente);
                    if (opcion_pila == 2) mostrarPila(pila2, cliente);
                    else cout<<"No existe la opcion ingresada. Vuelva a intentarlo.\n";
                    break;
            case 4: cout<<"Comparar pilas:\n";
                    compararPilas(pila1, pila2);
                    break;
            case 5: cout<<"\tMayor DNI\n";
                    cout<<"Elija la pila de la cual quiere saber el mayor DNI\n";
                    cout<<"\t1. Pila 1\n";
                    cout<<"\t2. Pila 2\n";
                    cout<<"Opcion: "; cin>>opcion_pila;
                    cout<<"\tPila "<<opcion_pila<<":\n";
                    if (opcion_pila == 1) mayorDni(pila1);
                    if (opcion_pila == 2) mayorDni(pila2);
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

void agregarPila(Nodo *&pila, Cliente p) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo -> c = p;
    nuevo_nodo -> siguiente = pila;
    pila = nuevo_nodo;
}

void mostrarPila(Nodo *pila, Cliente &p) {
    Nodo *aux = pila;
    while (aux != NULL) {
        p = aux -> c;
        cout<<"Nombre: "<<p.nombre<<endl;
        cout<<"Edad: "<<p.edad<<endl;
        cout<<"DNI: "<<p.dni<<endl;
        cout<<"\n";
        aux = aux -> siguiente;
    }
    system("pause");
}

void compararPilas(Nodo *x1, Nodo *x2) {
    while (x1 != NULL) {
        Nodo *aux = new Nodo();
        aux = x2; // copia la pila en un nodo auxiliar para hacer la comparacion de x1 con la copia de x2
        while (aux != NULL) {
            if ((x1 -> c.edad) == (aux -> c.edad)) {
                cout<<"Si hay edades repetidas.\n";
                cout<<"La edad que se repite es: "<<aux -> c.edad<<" anios.\n";
                cout<<"Pertenecen a "<<aux -> c.nombre<<" y a "<<x1 -> c.nombre<<endl;
            }
            aux = aux -> siguiente;
        }
        x1 = x1 -> siguiente;
    }
    cout<<"\n";
    system("pause");
}

void mayorDni(Nodo *pila) {
    int mayor = 0;
    while (pila != NULL) {
        if ((pila -> c.dni) > mayor) mayor = pila -> c.dni;
        pila = pila -> siguiente;
    }
    cout<<"El DNI mas grande es: "<<mayor<<endl;
    system("pause");
}