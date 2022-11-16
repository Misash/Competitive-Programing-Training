
// Program para demostrar el trabajo de
// resize() length()

#include <iostream>
#include <string> // lib para usar string
using namespace std;

// Driver Code
int main()
{
    // Inicializando cadena
    string str = "123456789";


    // Mostrando Cadena
    cout << "The initial string is : ";
    cout << str << endl;

    // Mostrando el tamaño nicial de la cadena
    cout << "El tamaño inicial de la cadena :" << str.length()
         << endl;

    // Cambiar el tamaño de la cadena usando resize()
    str.resize(7);

    // Displaying string
    cout << "La cadena despues del resize es : ";
    cout << str << endl;


    // Mostrando el tamaño de la cadena
    cout << "El tamaño de la cadena :" << str.length()
         << endl;



    return 0;
}