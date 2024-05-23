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
    char clave[10];
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
void sacarCola(Nodo *&, Nodo *&, Cliente &);
void mostrarCola(Nodo *&, Nodo *&, Cliente &);
void compararColas(Nodo *, Nodo *, Nodo *, Nodo *);
void mayorDni(Nodo *, Nodo *);

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
        cout<<"3. Mostrar cola de clientes\n"; // esta opcion borra los datos por lo que hay que ejecutarla al final
        cout<<"4. Comparar colas\n";
        cout<<"5. Mostrar el mayor DNI\n";
        cout<<"0. Salir\n\n";
        cout<<"Opcion: "; cin>>opcion;
        switch(opcion) {
            case 1: cout<<"Ingresar un cliente a la cola 1:\n";
                    ingresarCliente(cliente);
                    insertarCola(frente_cola1, fin_cola1, cliente);
                    cout<<"El cliente se agrego correctamente a la cola 1.\n\n";
                    system("pause");
                    break;
            case 2: cout<<"Ingresar un cliente a la cola 2:\n";
                    ingresarCliente(cliente);
                    insertarCola(frente_cola2, fin_cola2, cliente);
                    cout<<"El cliente se agrego correctamente a la cola 2.\n\n";
                    system("pause");
                    break;
            case 3: cout<<"Mostrar cola de clientes\n";
                    cout<<"Elija la cola a mostrar\n";
                    cout<<"1. Cola 1\n";
                    cout<<"2. Cola 2\n";
                    cout<<"Opcion: "; cin>>opcion_cola;
                    cout<<"\tMostrando cola "<<opcion_cola<<":\n";
                    if (opcion_cola == 1) mostrarCola(frente_cola1, fin_cola1, cliente);
                    if (opcion_cola == 2) mostrarCola(frente_cola2, fin_cola2, cliente);
                    else cout<<"No existe la opcion ingresada. Vuelva a intentarlo.\n";
                    break;
            case 4: cout<<"Comparar colas:\n";
                    compararColas(frente_cola1, fin_cola1, frente_cola2, fin_cola2);
                    break;
            case 5: cout<<"Mayor DNI\n";
                    cout<<"Elija la cola de la cual quiere saber el mayor DNI\n";
                    cout<<"1. cola 1\n";
                    cout<<"2. cola 2\n";
                    cout<<"Opcion: "; cin>>opcion_cola;
                    cout<<"\tcola "<<opcion_cola<<":\n";
                    if (opcion_cola == 1) mayorDni(frente_cola1, fin_cola1);
                    if (opcion_cola == 2) mayorDni(frente_cola2, fin_cola2);
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
    cout<<"Clave: "; cin.getline(p.clave, 10, '\n');
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

void sacarCola(Nodo *&frente, Nodo *&fin, Cliente &p) {
    p = frente -> c;
    Nodo *aux = frente;
    if (frente == fin) {
        frente = NULL;
        fin = NULL;
    } else {
        frente = frente -> siguiente;
    }
    delete aux;
}

void mostrarCola(Nodo *&frente, Nodo *&fin, Cliente &p) {
    while (frente != NULL) {
        sacarCola(frente, fin, p);
        if (frente != NULL) {
            cout<<"Nombre: "<<p.nombre<<endl;
            cout<<"Clave: "<<p.clave<<endl;
            cout<<"Edad: "<<p.edad<<endl;
            cout<<"DNI: "<<p.dni<<endl;
            cout<<"\t*************\n";
        } else {
            cout<<"Nombre: "<<p.nombre<<endl;
            cout<<"Clave: "<<p.clave<<endl;
            cout<<"Edad: "<<p.edad<<endl;
            cout<<"DNI: "<<p.dni<<endl;
            cout<<"\n\n";
        }
    }
    system("pause");
}