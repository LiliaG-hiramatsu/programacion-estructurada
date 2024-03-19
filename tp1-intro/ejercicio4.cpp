/*EJERCICIO 4
Escribe la siguiente expresion en C++
(a + (b / c)) / (d + (e / f))*/

#include <iostream>

using namespace std;

int main() {
    float a, b, c, d, e, f, resultado = 0;
    cout<<"Ingrese a: "; cin>>a;
    cout<<"Ingrese b: "; cin>>b;
    cout<<"Ingrese c: "; cin>>c;
    cout<<"Ingrese d: "; cin>>d;
    cout<<"Ingrese e: "; cin>>e;
    cout<<"Ingrese f: "; cin>>f;

    resultado = (a + (b / c)) / (d + (e / f));

    cout.precision(3);
    cout<<"\nEl resultado es: "<<resultado<<endl;
    return 0;
}