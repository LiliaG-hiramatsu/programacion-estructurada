/*EJERCICIO 3
Realice un programa que lea de la entrada estandar
los siguientes datos de una persona:
-Edad: dato de tipo entero
-Sexo: dato de tipo caracter
-Altura en metros: dato de tipo real
Tras leer los datos, el programa debe mostrarlos en
la salida estandar.*/

#include <iostream>

using namespace std;

int main() {
    int edad;
    char sexo[10];
    float altura;
    cout<<"Ingrese la edad: "; cin>>edad;
    cout<<"Ingrese el sexo: "; cin>>sexo;
    cout<<"Ingrese la altura en metros: "; cin>>altura;

    cout<<"\nEdad: "<<edad<<endl;
    cout<<"Sexo: "<<sexo<<endl;
    cout<<"Altura en metros: "<<altura<<endl;

    return 0;
}