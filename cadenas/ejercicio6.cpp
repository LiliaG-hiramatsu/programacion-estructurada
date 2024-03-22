/*
Convertir dos cadenas de minusculas a mayusculas.
Compararlas y decir si son iguales o no.
*/
#include<iostream>
#include<string.h>
#include<algorithm>
#include<cctype>

using namespace std;

int main() {
    // La funcion strupr() tambien esta obsoleta, 
    // por lo que utilizo toupper y transform de las bibliotecas
    // cctype y algorithm respectivamente.
    int resultado;
    char cadena1[40], cadena2[40];
    cout<<"Ingresar la cadena 1: ";
    cin.getline(cadena1, 40, '\n');
    cout<<"Ingresar la cadena 2: ";
    cin.getline(cadena2, 40, '\n');
    transform(cadena1, cadena1 + strlen(cadena1), cadena1,
    [](unsigned char c) {
        return toupper(c);
    });
    cout<<cadena1<<endl;
    transform(cadena2, cadena2 + strlen(cadena2), cadena2,
    [](unsigned char c) {
        return toupper(c);
    });
    cout<<cadena2<<endl;
    resultado = strcmp(cadena1, cadena2);
    if (resultado == 0) {
        cout<<"Las cadenas ingresadas son iguales."<<endl;
    } else {
        cout<<"Las cadenas ingresadas no son iguales."<<endl;
    }
    return 0;
}