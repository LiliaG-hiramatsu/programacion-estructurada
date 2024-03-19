/*EJERCICIO 14
Realice un programa que solicite un numero enter del 1 al 10
y muestre en la salida su tabla de multiplicar.*/

#include <iostream>

using namespace std;

int main() {
    int numero;
    cout<<"Ingrese un numero del 1 al 10: "; cin>>numero;

    for (int i=0; i<10; i++) {
        cout<<numero<<" X "<<(i+1)<<" = "<<numero*(i+1)<<endl;
    }
    return 0;
}