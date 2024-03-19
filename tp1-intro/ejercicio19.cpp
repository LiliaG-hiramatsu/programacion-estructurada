/*EJERCICIO 19
Escriba un programa que calcule x^y,
donde tanto x como y son enteros positivos,
sin utilizar la funcion pow.*/

#include<iostream>

using namespace std;

int main() {
    int x, y, resultado = 1, contador = 1;
    cout<<"Ingrese el valor de x (entero positivo): "; cin>>x;
    cout<<"Ingrese el valor de y (entero positivo): "; cin>>y;
    do {
        resultado *= x;
        contador++;
    } while (contador <= y);
    cout<<"El resultado de la potencia es: "<<resultado<<endl;
    return 0;
}