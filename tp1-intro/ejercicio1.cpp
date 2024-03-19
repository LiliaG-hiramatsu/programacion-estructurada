/* EJERCICIO 1
Escribe un programa que lea de la entrada estandar dos numeros y
muestre en la salida estandar su suma, resta, multiplicacion y division
*/

#include <iostream>

using namespace std;

int main() {
    int n1, n2, suma = 0, resta = 0, multiplicacion = 0, division = 0;

    cout<<"Ingrese el primer numero: "; cin>>n1;
    cout<<"Ingrese el segundo numero: "; cin>>n2;

    suma = n1 + n2;
    cout<<"\nLa suma es: "<<suma<<endl;
    resta = n1 - n2;
    cout<<"La resta es: "<<resta<<endl;
    multiplicacion = n1 * n2;
    cout<<"La multiplicacion es: "<<multiplicacion<<endl;
    if (n2 != 0) {
        division = n1 / n2;
        cout<<"La division es: "<<division<<endl;
    } else {
        cout<<"La division por cero no esta definida.";
    }
    return 0;
}