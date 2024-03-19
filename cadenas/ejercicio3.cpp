/*
Pedir al usuario que digite 2 cadenas de caracteres, e indicar si ambas cadenas
son iguales, en caso de no serlo, indicar cual es mayor alfabeticamente.
*/

#include<iostream>
#include<string.h>

using namespace std;

int main() {
    //comparar cadenas - funcion strcmp()
    //strcmp(cadena1, cadena2) devuelve 0 si son iguales y 1 si son diferentes
    //tambien compara cual es mayor alfabeticamente
    char cadena1[30], cadena2[30];
    cout<<"Digite la cadena 1: ";
    cin.getline(cadena1, 30, '\n');
    cout<<"Digite la cadena 2: ";
    cin.getline(cadena2, 30, '\n');
    if (strcmp(cadena1, cadena2) > 0) {
        cout<<"La cadena "<<cadena1<<" es mayor alfabeticamente que la cadena "<<cadena2<<endl;
    }
    else if (strcmp(cadena1, cadena2) < 0) {
        cout<<"La cadena "<<cadena2<<" es mayor alfabeticamente que la cadena "<<cadena1<<endl;
    } else {
        cout<<"Las cadenas son iguales."<<endl;
    }

    return 0;
}