/*
Pedir al usuario una cadena de caracteres, almacenarla en un arreglo
y copiar todo su contenido hacia otro arreglo de caracteres.
*/

#include<iostream>
#include<string.h>

using namespace std;

int main() {
    //strcpy(cadena_vacia, cadena_info);
    char cadena[50], cadena_copy[50];
    cout<<"Ingresar una cadena de caracteres: ";
    cin.getline(cadena, 50, '\n');
    strcpy(cadena_copy, cadena);
    cout<<"Cadena original: "<<cadena<<endl;
    cout<<"Cadena copia: "<<cadena_copy<<endl;
    return 0;
}