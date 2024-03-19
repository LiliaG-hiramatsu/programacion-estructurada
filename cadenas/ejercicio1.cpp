/*
Hacer un programa que pida al usuario que digite una cadena de caracteres,
luego verificar la longitud de la cadena, y si esta supera a 10 caracteres
mostrarla en pantalla, caso contrario no mostrarla.
*/

#include<iostream>
#include<string.h>

using namespace std;

int main() {
    //char palabra[] = "Desarrollo";
    //char palabra2[] = {'S', 'O', 'F', 'T', 'W', 'A', 'R', 'E'};
    //char nombre[30]; //cuando no sabemos cuantos caracteres puede tener exactamente
    //no debemos usar cin para almacenar cadenas cuando queremos insertar un espacio
    //gets(nombre);
    //gets almacena cualquier cosa que ingresemos ignorando el espacio que se habia reservado al principio
    //ocupa un espacio de memoria que no le pertenece
    //cin.getline(nombre, 30, '\n');
    //int longitud = 0;
    //longitud = strlen(nombre);
    char cadena[50];
    int longitud = 0;
    cout<<"Digite una cadena de caracteres: ";
    cin.getline(cadena, 50, '\n');
    longitud = strlen(cadena);
    if (longitud > 10) {
        cout<<cadena<<endl;
    } else {
        cout<<"La cadena es menor o igual a 10 caracteres."<<endl;
    }
    return 0;
}