/*EJERCICIO 9
Realice un programa que lea un valor entero y determine
si se trata de un numero par o impar.*/
#include <iostream>

using namespace std;

int main() {
    int n;
    cout<<"Ingresa un numero"<<endl;
    cin>>n;
    if (n == 0) {
        cout<<"\nEL numero es cero."<<endl;
    }
    else if (n % 2 == 0) {
        cout<<"\nEl numero es par."<<endl;
    } else {
        cout<<"\nEl numero es impar."<<endl;
    }

    return 0;
}