/*EJERCICIO 8
Escriba un programa que lea dos numeros y 
determine cual de ellos es el mayor.*/
#include <iostream>

using namespace std;

int main() {
    int num1, num2;
    cout<<"Ingrese dos numeros: ";
    cin>>num1>>num2;

    if (num1 > num2) {
        cout<<"\nEl mayor es el numero 1, cuyo valor es "<<num1<<endl;
    } else if (num2 > num1) {
        cout<<"\nEl mayor es el numero 2, cuyo valor es "<<num2<<endl;
    } else {
        cout<<"\nAmbos numeros son iguales."<<endl;
    }

    return 0;
}