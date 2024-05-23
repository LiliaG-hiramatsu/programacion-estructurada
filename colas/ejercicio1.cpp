/*
Hacer un programa que tenga el siguiente menu:
1.Insertar un caracter a una cola
2. Mostrar todos los elementos de la cola
3. Salir
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

struct Nodo {
    char dato;
    Nodo *siguiente;
};

void menu();
void insertarDato(Nodo *&, Nodo *&, char);
bool cola_vacia(Nodo *);
void suprimirDato(Nodo *&, Nodo *&, char &);

int main() {

    menu();

    return 0;
}

void menu() {
    int opc;
    char dato;

    Nodo *frente = NULL;
    Nodo *fin = NULL;

    do {
        cout<<"\t. MENU: .\n";
        cout<<"1. Insertar un caracter a una cola"<<endl;
        cout<<"2. Mostrar todos los elementos de la cola"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Opcion: "; cin>>opc;

        switch(opc) {
            case 1: cout<<"\nIngrese el caracter para ingresar a la cola: ";
                    cin>>dato;
                    insertarDato(frente, fin, dato);
                    break;
            case 2: cout<<"\nMostrando los elementos de la cola: ";
                    while (frente != NULL) {
                        suprimirDato(frente, fin, dato);
                        if (frente != NULL) {
                            cout<<dato<<", ";
                        } else {
                            cout<<dato<<"."<<endl;
                        }
                    }
                    system("pause"); // hace que haga una pausa
                    break;
            case 3: break;
            default: break;
        }
        system("cls"); //limpia la pantalla
    } while (opc != 3);
}

// Funcion para insertar elementos en la cola
void insertarDato(Nodo *&frente, Nodo *&fin, char n) {
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo -> dato = n;
    nuevo_nodo -> siguiente = NULL; // los nodos que van llegando a la cola siempre van a tener un puntero siguiente NULL ya que atras de ellos no va a haber nada (es el ultimo de la cola)

    if (cola_vacia(frente)) {
        frente = nuevo_nodo; // la primera vez frente va ser NULL asique entra aca y copia "nuevo_nodo" en "frente"
    } else {
        fin -> siguiente = nuevo_nodo; // guarda en el puntero siguiente la nueva direccion de nuevo_nodo
    }
    fin = nuevo_nodo; // esta linea siempre se ejecuta pq el puntero "fin" siempre tiene que apuntar al nuevo nodo
}

// Funcion para verificar si la cola esta vacia - se va a llamar solo la primera vez (cuando la cola esta vacia)
bool cola_vacia(Nodo *frente) {
    return (frente == NULL) ? true : false;
}

// Funcion para eliminar un nodo
void suprimirDato(Nodo *&frente, Nodo *&fin, char &n) {
    n = frente -> dato;
    Nodo *aux = frente;

    if (frente == fin) {
        frente = NULL;
        fin = NULL;
    } else {
        frente = frente -> siguiente;
    }
    delete aux;
}