/*EJERCICIO 12
Hacer un programa que calcule el resultado de la siguiente
expresion: 1-2+3-4+5-6...n
*/
#include <iostream>

using namespace std;

int main() {
    int n, suma = 0;
    cout<<"Ingresa el valor de n: "; cin>>n;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            suma -= i;
        } else {
            suma += i;
        }
    }
    cout<<"El resultado es: "<<suma<<endl;
    return 0;
}