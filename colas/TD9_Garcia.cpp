/*
Hacer un programa que guarde datos de clientes de un
banco, los almacene en cola, y por ultimo muestre
los clientes en el orden correcto.
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

struct Cliente {
    char nombre[30];
    char clave[10];
    int edad;
    long dni;
};

struct Nodo {
    Cliente c;
    Nodo *siguiente;
};

void menu();
void cargarCliente(Cliente &);
void agregarCliente(Nodo *&, Nodo *&, Cliente);
bool cola_vacia(Nodo *);
void eliminarCliente(Nodo *&, Nodo *&, Cliente &);

int main() {
    menu();
    return 0;
}

void menu() {
    int opc;
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    Cliente c;

    do {
        cout<<"\t. MENU: .\n";
        cout<<"1. Agregar un cliente a la cola"<<endl;
        cout<<"2. Mostrar todos los clientes de la cola"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Opcion: "; cin>>opc;

        switch(opc) {
            case 1: cargarCliente(c);
                    agregarCliente(frente, fin, c);
                    break;
            case 2: cout<<"\tMostrando los elementos de la cola\n"<<endl;
                    while (frente != NULL) {
                        eliminarCliente(frente, fin, c);
                        cout<<"Nombre: "<<c.nombre<<endl;
                        cout<<"Clave: "<<c.clave<<endl;
                        cout<<"Edad: "<<c.edad<<endl;
                        cout<<"DNI: "<<c.dni<<endl;
                        cout<<"\n";
                    }
                    system("pause"); // hace que haga una pausa
                    break;
            case 3: break;
            default: break;
        }
        system("cls"); //limpia la pantalla
    } while (opc != 3);
}

void cargarCliente(Cliente &c) {
    fflush(stdin);
    cout<<"\tAgregando un nuevo cliente"<<endl;
    cout<<"Nombre: "; cin.getline(c.nombre, 30, '\n');
    cout<<"Clave: "; cin.getline(c.clave, 10, '\n');
    cout<<"Edad: "; cin>>c.edad;
    cout<<"DNI: "; cin>>c.dni;
}

// Funcion para insertar clientes a la cola
void agregarCliente(Nodo *&frente, Nodo *&fin, Cliente c) {
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo -> c = c;
    nuevo_nodo -> siguiente = NULL;

    if (cola_vacia(frente)) {
        frente = nuevo_nodo;
    } else {
        fin -> siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;

    cout<<"Carga exitosa"<<endl;
}

// Funcion para verificar si la cola esta vacia
bool cola_vacia(Nodo *frente) {
    return (frente == NULL) ? true : false;
}

// Funcion para eliminar un nodo
void eliminarCliente(Nodo *&frente, Nodo *&fin, Cliente &c) {
    c = frente -> c;
    Nodo *aux = frente;

    if (frente == fin) {
        frente = NULL;
        fin = NULL;
    } else {
        frente = frente -> siguiente;
    }
    delete aux;
}