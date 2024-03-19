/*EJERCICIO 6
La calificacion final de un estudiante es la media
ponderada de tres notas: La nota de practicas
que cuenta un 30% del total, la nota teorica que
cuenta un 60% y la nota de participacion que cuenta
10% restante.
Escriba un programa que lea de la entrada estandar
las tres notas de un alumno y escriba en la salida
estandar su nota final.*/

#include <iostream>

using namespace std;

int main() {
    float nota_practicas, nota_teoria, nota_participacion, nota_final = 0;
    cout<<"Ingrese la nota de practica: "; cin>>nota_practicas;
    cout<<"Ingrese la nota de teoria: "; cin>>nota_teoria;
    cout<<"Ingrese la nota de participacion: "; cin>>nota_participacion;

    nota_final = nota_practicas*0.3 + nota_teoria*0.6 + nota_participacion*0.1;
    cout<<"\nLa nota final es: "<<nota_final<<endl;

    return 0;
}