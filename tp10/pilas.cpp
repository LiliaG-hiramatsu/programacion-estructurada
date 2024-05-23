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
void agregarPila(Nodo *&, Cliente);
void mostrarPila(Nodo *&, Cliente &);
void sacarPila(Nodo *&, Cliente &);
bool pilaVacia(Nodo *);
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
        cout<<"3. Mostrar pila de clientes\n"; // esta opcion borra los datos por lo que hay que ejecutarla al final
        cout<<"4. Comparar pilas\n";
        cout<<"5. Mostrar el mayor DNI\n";
        cout<<"0. Salir\n\n";
        cout<<"Opcion: "; cin>>opcion;
        switch(opcion) {
            case 1: cout<<"Ingresar un cliente a la pila 1:\n";
                    ingresarCliente(cliente);
                    agregarPila(pila1, cliente);
                    cout<<"El cliente se agrego correctamente a la pila 1.\n\n";
                    system("pause");
                    break;
            case 2: cout<<"Ingresar un cliente a la pila 2:\n";
                    ingresarCliente(cliente);
                    agregarPila(pila2, cliente);
                    cout<<"El cliente se agrego correctamente a la pila 2.\n\n";
                    system("pause");
                    break;
            case 3: cout<<"Mostrar pila de clientes\n";
                    cout<<"Elija la pila a mostrar\n";
                    cout<<"1. Pila 1\n";
                    cout<<"2. Pila 2\n";
                    cout<<"Opcion: "; cin>>opcion_pila;
                    cout<<"\tMostrando pila "<<opcion_pila<<":\n";
                    if (opcion_pila == 1) mostrarPila(pila1, cliente);
                    if (opcion_pila == 2) mostrarPila(pila2, cliente);
                    else cout<<"No existe la opcion ingresada. Vuelva a intentarlo.\n";
                    break;
            case 4: cout<<"Comparar pilas:\n";
                    compararPilas(pila1, pila2);
                    break;
            case 5: cout<<"Mayor DNI\n";
                    cout<<"Elija la pila de la cual quiere saber el mayor DNI\n";
                    cout<<"1. Pila 1\n";
                    cout<<"2. Pila 2\n";
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
    cout<<"Clave: "; cin.getline(p.clave, 10, '\n');
    cout<<"Edad: "; cin>>p.edad;
    cout<<"DNI: "; cin>>p.dni;
}

void agregarPila(Nodo *&pila, Cliente p) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo -> c = p;
    nuevo_nodo -> siguiente = pila;
    pila = nuevo_nodo;
}

void sacarPila(Nodo *&pila, Cliente &p) {
    Nodo *aux = pila;
    p = aux -> c;
    if (pilaVacia(pila)) {
        pila = NULL;
    } else {
        pila = aux -> siguiente;
    }
    delete aux;
}

void mostrarPila(Nodo *&pila, Cliente &p) {
    while (pila != NULL) {
        sacarPila(pila, p);
        if (pila != NULL) {
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

bool pilaVacia(Nodo *final) {
    return (final == NULL) ? true : false;
}

void compararPilas(Nodo *x1, Nodo *x2) {
    bool flat = false;
    while (x1 != NULL) {
        Nodo *aux = new Nodo();
        aux = x2; // copia la pila en un nodo auxiliar para hacer la comparacion de x1 con la copia de x2
        while (aux != NULL) {
            if ((x1 -> c.edad) == (aux -> c.edad)) {
                flat = true;
                cout<<"La edad que se repite es: "<<aux -> c.edad<<endl;
            }
            aux = aux -> siguiente;
        }
        x1 = x1 -> siguiente;
    }
    // en el while de adentro se recorre la copia de la pila 2
    // se compara una sola estructura de la pila 1 con cada estructura de la pila 2
    // en el while de afuera se recorre la pila 1
    if (flat) cout<<"Si hay edades repetidas.\n";
    else cout<<"No hay edades repetidas.\n";
    
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