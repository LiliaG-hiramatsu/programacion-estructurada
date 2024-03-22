/*
Escribe un programa que defina un vector de numeros y
muestre en la salida estandar el vector en orden
inverso (del ultimo al primer elemento).
*/

#include<iostream>

using namespace std;

int main() {
    int numeros[] = {1, 2, 3, 4};
    cout<<"El vector en orden inverso queda:"<<endl;
    for (int i=3; i>=0; i--) {
        cout<<numeros[i]<<endl;
    }
    return 0;
}