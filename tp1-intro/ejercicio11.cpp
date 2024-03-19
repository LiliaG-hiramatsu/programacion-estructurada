/*EJERCICIO 11
Escriba un programa que solicite una edad (un entero)
e indique en la salida estandar si la edad introducida
esta en el rango [18-25].*/

#include <iostream>

using namespace std;

int main(){
    int edad;
    cout<<"Ingrese una edad: "; cin>>edad;
    if (edad>=18 && edad<=25) {
        cout<<"La edad esta en el rango [18-25]"<<endl;
    } else {
        cout<<"La edad introducida no esta en el rango [18-25]"<<endl;
    }

    return 0;
}