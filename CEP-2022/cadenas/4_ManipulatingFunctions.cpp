
// Program C++ para demostrar el trabajo con
 //swap()

#include <iostream>
#include <string> // lib para usar string

using namespace std;


int main()
{
    // Declarando cadena 1
    string str1 = "hola mundo";

    // Declarando cadena 2
    string str2 = "me gusta programar";


    // Declarando cadenas antes del intermcambio con swap()
    cout << "cadena 1 : ";
    cout << str1 << endl;
    cout << "cadena 2 : ";
    cout << str2 << endl;

    cout<<"\n swap( cadena1 , cadena2 )\n\n";
    // usando swap() para intercambiar valores
    str1.swap(str2);

    // Mostrar las cadenas despues del intercambio
    cout << "cadena 1 : ";
    cout << str1 << endl;
    cout << "cadena 2 : ";
    cout << str2 << endl;

    return 0;
}
