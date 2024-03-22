/*
Hacer un programa que determine si una palabra es polindroma
*/
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int main() {
    //strrev(cadena) --> no esta definida en la biblioteca estandar de c++
    // en su lugar, uso reverse() de la libreria algorithm
    int resultado;
    char palabra[50], palabra_copia[50];
    cout<<"Ingrese una palabra: ";
    cin.getline(palabra, 50, '\n');
    strcpy(palabra_copia, palabra);
    reverse(palabra_copia, palabra_copia + strlen(palabra_copia));
    resultado = strcmp(palabra, palabra_copia);
    if (resultado == 0) {
        cout<<"La palabra es palindroma"<<endl;
    } else {
        cout<<"La palabra no es palindroma"<<endl;
    }
    return 0;
}
