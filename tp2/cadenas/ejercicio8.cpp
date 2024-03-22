/*
Pedir al usuario 2 cadenas de caracteres de numeros,
uno entero y el otro real, convertirlos a sus respectivos
valores y por ultimo, sumarlos.
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

int main() {
    char numero1[10], numero2[10];
    int numero_entero;
    float numero_real, suma;
    cout<<"Ingresar el numero 1 (entero): ";
    cin.getline(numero1, 10, '\n');
    cout<<"Ingresar el numero 2 (real): ";
    cin.getline(numero2, 10, '\n');
    numero_entero = atoi(numero1);
    numero_real = atof(numero2);
    suma = numero_entero + numero_real;
    cout<<"El resultado de la suma es: "<<suma<<endl;
    return 0;
}