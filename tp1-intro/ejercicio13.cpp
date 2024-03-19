/*EJERCICIO 13
Hacer un programa que simule un cajero automatico con
un saldo inicial de 1000 dolares*/

#include <iostream>

using namespace std;

int main() {
    int saldo_inicial = 1000, opcion;
    float extra, saldo=0, retiro;

    cout<<"\tBienvenido a su Cajero Virtual"<<endl;
    cout<<"1. Ingresar dinero a su cuenta"<<endl;
    cout<<"2. Retirar dinero de su cuenta"<<endl;
    cout<<"3. Salir"<<endl;
    cout<<"Opcion: "; cin>>opcion;

    switch(opcion) {
        case 1:
        cout<<"Ingrese la cantidad de dinero a ingresar a la cuenta: ";
        cin>>extra;
        saldo = saldo_inicial + extra;
        cout<<"Dinero en la cuenta: "<<saldo; break;
        case 2:
        cout<<"Ingrese la cantidad de dinero a retirar: ";
        cin>>retiro;

        if(retiro > saldo_inicial) {
            cout<<"Saldo insuficiente.";
        } else {
            saldo = saldo_inicial - retiro;
            cout<<"Dinero en la cuenta: "<<saldo;
        }
        case 3: break;
    }


    return 0;
}