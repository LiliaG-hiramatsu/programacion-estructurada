/*
Realiza un programa que defina una matriz de 3x3
y escriba un ciclo para que muestre la diagonal
principal de la matriz.
*/

#include<iostream>

using namespace std;

int main() {
    int matriz[3][3], i, j;
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            cout<<"matriz["<<i+1<<","<<j+1<<"] = "; cin>>matriz[i][j];
        }
    }
    cout<<"La diagonal de la matriz es: "<<endl;
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (i==j) {
                cout<<matriz[i][j]<<endl;
            }
        }
    }
    return 0;
}