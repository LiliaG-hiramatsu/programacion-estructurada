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
void agregarCliente(Nodo *&, Cliente);
void mostrarClientes(Nodo *);
void buscarCliente(Nodo *, int);
void eliminarCliente(Nodo *&, int);

int main() {
    menu();
    return 0;
}

void menu() {
    int opcion;
    Nodo *lista = NULL;
    Cliente c;

    do {
        cout<<"\tMENU:\n";
        cout<<"1- Ingresar un cliente\n";
        cout<<"2- Mostrar todos los clientes\n";
        cout<<"3- Buscar un cliente\n";
        cout<<"4- Eliminar un cliente\n";
        cout<<"0- Salir\n";
        cout<<"Opcion: ";

        cin>>opcion;
        switch(opcion) {
            case 1: cargarCliente(c);
                    cout<<"Agregar cliente a la lista\n";
                    agregarCliente(lista, c);
                    break;
            case 2: cout<<"\tMostrar lista de clientes:"<<endl;
                    mostrarClientes(lista);
                    cout<<"\n";
                    system("pause");
                    break;
            case 3: cout<<"Ingrese la edad del cliente que desea buscar: "; cin>>c.edad;
                    buscarCliente(lista, c.edad);
                    system("pause");
                    break;
            case 4: cout<<"Ingrese la edad del cliente que desea eliminar: "; cin>>c.edad;
                    eliminarCliente(lista, c.edad);
                    system("pause");
                    break;
            case 0: break;
            default: break;
        }
        system("cls");
    } while (opcion != 0);
}

void cargarCliente(Cliente &c) {
    fflush(stdin);
    cout<<"\tAgregando un nuevo cliente"<<endl;
    cout<<"Nombre: "; cin.getline(c.nombre, 30, '\n');
    cout<<"Clave: "; cin.getline(c.clave, 10, '\n');
    cout<<"Edad: "; cin>>c.edad;
    cout<<"DNI: "; cin>>c.dni;
}

void agregarCliente(Nodo *&lista, Cliente c) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo -> c = c;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while ((aux1 != NULL) && (aux1 -> c.edad < c.edad)) {
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

void mostrarClientes(Nodo *lista) {
    Nodo *actual = new Nodo();

    actual = lista;
    while (actual != NULL) {
        cout<<"Nombre de cliente: "<<actual -> c.nombre<<endl;
        cout<<"Clave: "<<actual ->c.clave<<endl;
        cout<<"Edad del cliente: "<<actual -> c.edad<<endl;
        cout<<"DNI del cliente: "<<actual -> c.dni<<endl;
        cout<<"\n";
        actual = actual -> siguiente;
    }
}

void buscarCliente(Nodo *lista, int edad) {
    bool flat = false;

    Nodo *actual = new Nodo();
    actual = lista;
    while ((actual != NULL) && (actual -> c.edad <= edad)) {
        if (actual -> c.edad == edad) {
            flat = true;
        }
        actual = actual -> siguiente;
    }

    if (flat == true) {
        cout<<"El cliente de edad "<<edad<<" ha sido encontrado.\n";
        cout<<"\n";
    } else {
        cout<<"El cliente de edad "<<edad<<" no ha sido encontrado.\n";
        cout<<"\n";
    }
}

void eliminarCliente(Nodo *&lista, int edad) {
    if (lista != NULL) {
        Nodo *aux_borrar;
        Nodo *anterior = NULL;
        aux_borrar = lista;

        while ((aux_borrar != NULL) && (aux_borrar -> c.edad != edad)) {
            anterior = aux_borrar;
            aux_borrar = aux_borrar -> siguiente;
        }

        if (aux_borrar == NULL) {
            cout<<"El cliente no existe.\n";
        }
        else if (anterior == NULL) {
            lista = lista -> siguiente;
            delete aux_borrar;
            cout<<"Cliente eliminado con exito"<<endl;
        }
        else {
            anterior -> siguiente = aux_borrar -> siguiente;
            delete aux_borrar;
            cout<<"Cliente eliminado con exito"<<endl;
        }
    }
}