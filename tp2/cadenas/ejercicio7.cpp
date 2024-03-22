/*
Pedir su nombre al usuario en mayuscula, si su nombre
comienza por la letra A, convertir su nombre a minusculas,
caso contrario, no convertirlo.
*/
#include<iostream>
#include<string.h>
#include<algorithm>
#include<cctype>

using namespace std;

int main() {
    char nombre[30];
    cout<<"Ingrese su nombre en mayusculas: ";
    cin.getline(nombre, 30, '\n');
    if (nombre[0] == 'A') {
        transform(nombre, nombre + strlen(nombre), nombre,
        [](unsigned char c) {
            return tolower(c);
        });
        cout<<"Tu nombre en minusculas: "<<nombre<<endl;
    } else {
        cout<<"Como tu nombre no empieza con A, queda en mayusculas: "<<nombre<<endl;
    }
    return 0;
}