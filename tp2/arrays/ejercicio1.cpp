/*
Escribe un programa que defina un vector de numeros
y calcule la multiplicacion acumulada de sus
elementos.
*/

#include<iostream>

using namespace std;

int main() {
    int numeros[] = {1, 2, 3, 4, 5};
    int producto = 1;
    for (int i=0; i<5; i++) {
        producto *= numeros[i];
    }
    cout<<"El producto acumulado de los elementos del vector es: "<<producto<<endl;

    return 0;
}