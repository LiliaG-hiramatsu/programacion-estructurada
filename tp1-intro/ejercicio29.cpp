/* EJERCICIO 29
Realice un programa que calcule la descomposicion en factores primos
de un numero entero
Por ejemplo 20 = 2*2*5
*/
#include<iostream>

using namespace std;

int main() {
    int num, factor, dividendo;
    cout<<"Ingrese el numero que quiere descomponer: "; cin>>num;
    do {
        if (num % 2 == 0) {
            dividendo = num / 2;
            factor = 2;
            cout<<factor<<endl;
        }
        else if (num % 3 == 0) {
            dividendo = num / 3;
            factor = 3;
            cout<<factor<<endl;
        }
        else if (num % 5 == 0) {
            dividendo = num / 5;
            factor = 5;
            cout<<factor<<endl;
        }
        else if (num % 7 == 0) {
            dividendo = num / 7;
            factor = 7;
            cout<<factor<<endl;
        }
        num = dividendo;
    } while (num != 1);

    cout<<"Factorizacion finalizada"<<endl;

    return 0;
}