/*
Hacer una matriz preguntando al usuarios el numero 
de filas y columnas, llenarla de numeros aleatorios,
copiar el contenido a otra matriz y, por ultimo,
mostrarla en pantalla.
*/

#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main() {
    int n, m;
    cout<<"Ingrese el numero de filas: "; cin>>n;
    cout<<"Ingrese el numero de columnas: "; cin>>m;
    int matriz1[n][m], matriz2[n][m];

    // Llenas la matriz con numeros aleatorios entre 1 y 100
    srand(time(NULL));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            matriz1[i][j] = 1 + rand() % 100;
        }
    }

    // Copiar la matriz1 en la matriz2
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            matriz2[i][j] = matriz1[i][j];
        }
    }

    // Mostrar la matriz2 en pantalla
    cout<<"\tMATRIZ 2:"<<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout<<"\t"<<matriz2[i][j];
        }
        cout<<"\n";
    }
    return 0;
}