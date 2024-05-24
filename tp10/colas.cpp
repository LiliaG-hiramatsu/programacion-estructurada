/*
Crear dos colas.
Crear un menú que permita ingresar dinámicamente el llenado de las mismas.
Y siempre deben existir estructuras de tipo CLIENTE (nombre, dni, edad).
Comparar una cola con la otra y decirme si hay edades REPETIDAS.
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
void insertarCola(Nodo *&, Nodo *&, Cliente);
bool colaVacia(Nodo *);
void mostrarCola(Nodo *, Cliente &);
void compararColas(Nodo *, Nodo *);
void mayorDni(Nodo *);

int main() {
    menu();
    return 0;
}

void menu() {
    int opcion, opcion_cola;
    Nodo *frente_cola1 = NULL;
    Nodo *fin_cola1 = NULL;
    Nodo *frente_cola2 = NULL;
    Nodo *fin_cola2 = NULL;
    Cliente cliente;

    do {
        cout<<"\tMENU\n";
        cout<<"1. Ingresar un cliente a la cola 1\n";
        cout<<"2. Ingresar un cliente a la cola 2\n";
        cout<<"3. Mostrar cola de clientes\n";
        cout<<"4. Comparar colas\n";
        cout<<"5. Mostrar el mayor DNI\n";
        cout<<"0. Salir\n\n";
        cout<<"Opcion: "; cin>>opcion;
        switch(opcion) {
            case 1: cout<<"\tIngresar un cliente a la cola 1:\n";
                    ingresarCliente(cliente);
                    insertarCola(frente_cola1, fin_cola1, cliente);
                    cout<<"El cliente se agrego correctamente a la cola 1.\n\n";
                    system("pause");
                    break;
            case 2: cout<<"\tIngresar un cliente a la cola 2:\n";
                    ingresarCliente(cliente);
                    insertarCola(frente_cola2, fin_cola2, cliente);
                    cout<<"El cliente se agrego correctamente a la cola 2.\n\n";
                    system("pause");
                    break;
            case 3: cout<<"\tMostrar cola de clientes\n";
                    cout<<"Elija la cola a mostrar\n";
                    cout<<"\t1. Cola 1\n";
                    cout<<"\t2. Cola 2\n";
                    cout<<"Opcion: "; cin>>opcion_cola;
                    cout<<"\tMostrando cola "<<opcion_cola<<":\n";
                    if (opcion_cola == 1) mostrarCola(frente_cola1, cliente);
                    if (opcion_cola == 2) mostrarCola(frente_cola2, cliente);
                    else cout<<"No existe la opcion ingresada. Vuelva a intentarlo.\n";
                    break;
            case 4: cout<<"\tComparar colas:\n";
                    compararColas(frente_cola1, frente_cola2);
                    break;
            case 5: cout<<"\tMayor DNI\n";
                    cout<<"Elija la cola de la cual quiere saber el mayor DNI\n";
                    cout<<"\t1. Cola 1\n";
                    cout<<"\t2. Cola 2\n";
                    cout<<"Opcion: "; cin>>opcion_cola;
                    cout<<"\tCola "<<opcion_cola<<":\n";
                    if (opcion_cola == 1) mayorDni(frente_cola1);
                    if (opcion_cola == 2) mayorDni(frente_cola2);
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

void insertarCola(Nodo *&frente, Nodo *&fin, Cliente p) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo -> c = p;
    nuevo_nodo -> siguiente = NULL;

    if (colaVacia(frente)) {
        frente = nuevo_nodo;
    } else {
        fin -> siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
}

bool colaVacia(Nodo *frente) {
    return (frente == NULL) ? true : false;
}

void mostrarCola(Nodo *frente, Cliente &p) {
    Nodo *aux = frente;
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

void compararColas(Nodo *frente1, Nodo *frente2) {
    while (frente1 != NULL) {
        Nodo *aux = new Nodo();
        aux = frente2;
        while (aux != NULL) {
            if ((frente1 -> c.edad)==(aux -> c.edad)) {
                cout<<"Si hay edades repetidas.\n";
                cout<<"La edad que se repite es: "<<aux -> c.edad<<" anios.\n";
                cout<<"Pertenecen a "<<aux -> c.nombre<<" y a "<<frente1 -> c.nombre<<endl;
            }
            aux = aux -> siguiente;
        }
        frente1 = frente1 -> siguiente;
    }
    cout<<"\n";
    system("pause");
}

void mayorDni(Nodo *frente) {
    int mayor = 0;
    while (frente != NULL) {
        if ((frente -> c.dni) > mayor) mayor = frente -> c.dni;
        frente = frente -> siguiente;
    }
    cout<<"El DNI mas grande es: "<<mayor<<endl;
    system("pause");
}