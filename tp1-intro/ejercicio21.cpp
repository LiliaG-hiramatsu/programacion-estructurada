/*EJERCICIO 21
Escriba un programa que calcule el valor de
1+3+5+...+2n-1*/
#include<iostream>

using namespace std;

int main() {
    int n, suma = 0;
    cout<<"Ingrese en valor de n: "; cin>>n;
    for (int i = 1; i <= n; i++) {
        suma += (2*i-1);
    }
    cout<<"El resultado de la sumatoria de los numeros impares de "<<n<<" es: "<<suma<<endl;
    return 0;
}