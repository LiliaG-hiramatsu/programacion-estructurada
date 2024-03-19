/* EJERCICIO 18 
Escriba un programa que lea valores enteros hasta que se introduzca
un valor en el rango [20-30] o se introduzca el valor 0.
El programa debe entregar la suma de los valores mayores a 0
introducidos.
*/

#include<iostream>


using namespace std;

int main() {
    int valor, suma = 0;

    do {
        cout<<"Ingrese un valor entero: "; cin>>valor;
        if (valor > 0) {
            suma += valor;
        }
    } while( ((valor<20) || (valor>30)) && (valor != 0));

    cout<<"La suma de los valores positivos es: "<<suma<<endl;

    return 0;
}