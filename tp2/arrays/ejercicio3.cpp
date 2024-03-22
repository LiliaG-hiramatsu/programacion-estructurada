/*
Escribe un programa que defina un vector de numeros y
calcule si existe algun numero en el vector cuyo valor
equivale a la suma del resto de numeros del vector.
*/

#include<iostream>

using namespace std;

int main() {
    int vector[30], n, suma = 0, mayor = 0, pos_mayor, aux;
    char flag;
    cout<<"Ingrese la cantidad de elementos del vector: "; cin>>n;
    for (int i=0; i<n; i++) {
        cout<<i+1<<". "; cin>>vector[i];
    }
    for (int i=0; i<n; i++) {
        if (vector[i] > mayor) {
            mayor = vector[i];
            pos_mayor = i;
        }
    }
    for (int i=0; i<n; i++) {
        if (i != pos_mayor) {
            suma += vector[i];
        }
    }
    for (int i=0; i<n; i++) {
        if (vector[i] == suma) {
            aux = vector[i];
            flag = 'T';
        }
    }
    if (flag == 'T') {
        cout<<"Existe tal numero y es: "<<aux<<endl;
    } else {
        cout<<"No existe tal numero."<<endl;
    }
    return 0;
}