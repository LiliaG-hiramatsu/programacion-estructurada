/*EJERCICIO 23
Escriba un programa que calcule el valor de:
1!+2!+3!+...+n! (suma de factoriales)
*/
#include<iostream>

using namespace std;

int main() {
    int n, suma = 0;
    cout<<"Ingrese el valor de n: "; cin>>n;
    for(int i=1; i<=n; i++){
        int factorial = 1;
        for(int j=1; j<=i; j++) {
            factorial *= j;
        }
        suma += factorial;
    }
    cout<<"La suma de los factoriales de 1 hasta "<<n<<" es: "<<suma<<endl;
    return 0;
}