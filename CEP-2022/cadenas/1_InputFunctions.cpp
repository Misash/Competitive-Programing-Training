
// Programa en C++ para demostrar como trabajar con
// getline(), push_back() and pop_back()


#include <iostream>
#include <string> // lib para usar string
using namespace std;


int main()
{
    // Declaramos la cadena
    string str ;

    // Obtenemos la entrada de una cadena con getline()
    getline(cin, str);

    // Mostrar la cadena
    cout << "La cadena inicial es : ";
    cout << str << endl;


    // Insertando un caracter
    str.push_back('J');

    // Mostrando una cadena
    cout << "La cadena  despues del push_back es : ";
    cout << str << endl;

    // Borrar un caracter
    str.pop_back();

    // Displaying string
    cout << "La cadena  despues del pop_back operation es : ";
    cout << str << endl;

    return 0;
}
