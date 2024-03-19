/*EJERCICIO 27
En una clase de 5 alumnos se han realizado tres
examenes y se requiere determinar el numero de:
a) Alumnos que aprobaron todos los examenes.
b) Alumnos que aprobaron al menos un examen.
c) Alumnos que aprobaron unicamente el ultimo examen.
Realice un programa que permita la lectura de los datos
y el calculo de las estadisticas.
*/
#include <iostream>

using namespace std;

int main() {
    int alumnos = 5, examenes = 3, nota, contador_aprobado = 0;
    for (int i=0; i<alumnos; i++) {
        cout<<"Ingrese la nota del alumno "<<i+1<<": "; cin>>nota;
        if (nota >= 6) {
            contador_aprobado++;
        }
    }
    
    return 0;
}