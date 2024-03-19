/* EJERCICIO 28
Realice un programa que solicite al usuario que piense un numero
entero entre 1 y 100. El programa debe generar un numero
aleatorio en ese mismo rango [1-100], e indicarle al usuario
si el numero que digito es menor o mayor al numero aleatorio,
asi hasta que lo adivine. Por ultimo mostrarle el numero
de intentos que le llevo.

variable = limite_inf + rand() % (limite_sup + 1 - limite_inf)
*/
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main() {
    int numero, dato, contador = 0;

    srand(time(NULL)); //genera un numero aleatorio
    dato = 1 + rand() % 100;

    do{
        cout<<"Ingrese un numero entre 1 y 100: "; cin>>numero;
        if (numero > dato) {
            cout<<"Ingrese un numero menor"<<endl;
        }
        if (numero < dato) {
            cout<<"Ingrese un numero mayor"<<endl;
        }
        contador++;
    } while(numero != dato);

    cout<<"Adivinaste el numero!!!"<<endl;
    cout<<"El numero de intentos fue: "<<contador<<endl;

    return 0;
}