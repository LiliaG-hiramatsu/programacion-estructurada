/*EJERCICIO 15
Realice un programa que lea de la entrada numeros
hasta que se introduzca un cero.
En ese momento el programa debe terminar
y mostrar en la salida el numero de valores
mayores que cero leidos.*/
#include <iostream>

using namespace std;

int main() {
    int numero, contador = 0;

    do{
        cout<<"Ingrese un numero: "; cin>>numero;
        if (numero>0) {
            contador++;
        }
    } while (numero!=0);

    cout<<"La cantidad de valores mayores a cero ingresados es: "<<contador<<endl;

    return 0;
}