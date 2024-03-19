/*EJERCICIO 24
Escriba un programa que calcule el valor de
2^1+2^2+2^3+...+2^n
*/
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n, suma = 0;
    cout<<"Ingrese el valor de n: "; cin>>n;
    for(int i = 1; i <= n; i++) {
        suma += pow(2, i);
    }
    cout<<"El resultado de la suma es: "<<suma<<endl;
    return 0;
}