/*EJERCICIO 20
Escriba un programa que calcule el calor de 1+2+3+...+n
*/

#include <iostream>

using namespace std;

int main() {
    int n, suma = 0;
    cout<<"Ingrese el valor de n: "; cin>>n;
    for(int i=1; i<=n; i++) {
        suma += i;
    }
    cout<<"La sumatoria de "<<n<<" es: "<<suma<<endl;
    return 0;
}