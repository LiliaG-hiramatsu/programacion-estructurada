/*
Hacer un programa que lea 5 numeros en un arreglo,
los copie a otro arreglo multiplicados por 2
y muestre el segundo arreglo.
*/

#include<iostream>

using namespace std;

int main() {
    int vector[5], vectorDoble[5];
    for (int i=0; i<5; i++) {
        cout<<i+1<<". "; cin>>vector[i];
        vectorDoble[i] = vector[i]*2;
    }
    cout<<"El segundo arreglo es:"<<endl;
    for (int i=0; i<5; i++) {
        cout<<i+1<<". "<<vectorDoble[i]<<endl;
    }
    return 0;
}