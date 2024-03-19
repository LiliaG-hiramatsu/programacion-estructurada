/*
Crear una cadena que tenga la frase "Hola que tal", luego crear otra 
cadena para preguntarle al usuario su nombre, por ultimo anadir el nombre
al final de la primera cadena y mostrar el mensaje completo:
"Hola que tal (nombre de usuario)".
*/

#include<iostream>
#include<string.h>

using namespace std;

int main() {
    //strcat(cadena1, cadena2) para concatenar
    //1. strcpy(nueva_cadena, cadena1)
    //2. strcat(nueva_cadena, cadena2)
    char cadena[] = "Hola que tal ";
    char nombre[30];
    char nueva_cadena[100];
    cout<<"Ingrese su nombre: ";
    cin.getline(nombre, 30, '\n');
    strcpy(nueva_cadena, cadena);
    strcat(nueva_cadena, nombre);
    cout<<"\tMensaje completo:"<<endl;
    cout<<"\t"<<nueva_cadena<<endl;

    return 0;
}