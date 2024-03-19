/*
Realice un programa que calcule el producto de dos
matrices cuadradas de 3x3.
*/
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main() {
    int matriz1[3][3], matriz2[3][3], i, j;
    // Llenar las matrices con numeros aleatorios
    srand(time(NULL));
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            matriz1[i][j] = 1 + rand() % 50;
            matriz2[i][j] = 1 + rand() % 50;
        }
    }
    // Mostrar las matrices
    cout<<"\tMATRIZ 1:"<<endl;
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            cout<<"\t"<<matriz1[i][j];
        }
        cout<<"\n";
    }
    cout<<"\tMATRIZ 2:"<<endl;
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            cout<<"\t"<<matriz2[i][j];
        }
        cout<<"\n";
    }
    // Multiplicar matrices
    cout<<"\tMATRIZ 1 X MATRIZ 2:"<<endl;
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            cout<<"\t"<<matriz1[i][j]*matriz2[i][j];
        }
        cout<<"\n";
    }
    return 0;
}