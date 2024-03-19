/*EJERCICIO 17
Escriba un programa que tome cada 4 horas
la temperatura exterior, leyendola durante un
periodo de 24 horas. Es decir, debe leer 6
temperaturas. Calcule la temperatura media
del dia, la temperatura mas alta y la mas baja.*/
#include <iostream>

using namespace std;

int main() {
    
    float temperatura, acc = 0, media = 0, t_max = 0, t_min = 300;
    for (int i = 1; i <= 6; i++) {
        cout<<"Leyendo temperatura..."; cin>>temperatura;
        acc += temperatura;
        if (temperatura >= t_max) {
            t_max = temperatura;
        }
        if (temperatura <= t_min) {
            t_min = temperatura;
        }
    }
    media = acc / 6;
    cout<<"La temperatura media del dia fue: "<<media<<" Celsius."<<endl;
    cout<<"La temperatura mas alta fue: "<<t_max<<" Celsius."<<endl;
    cout<<"La temperatura mas baja fue: "<<t_min<<" Celsius."<<endl;
    return 0;
}