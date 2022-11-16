
// Program C++ para demostrar el trabajo con
// begin(), end(), rbegin(), rend()

#include <iostream>
#include <string> // lib para usar string

using namespace std;

// Driver Code
int main()
{
    // Inicializar cadena
    string str = "hola mundo";

    // Declarar el iterador
    string::iterator it;

    // Declaring el reverse_iterator
    string::reverse_iterator it1;

    // Mostrando la cadena
    cout << "The string using forward iterators is : ";
    for (it = str.begin(); it != str.end(); it++)
        cout << *it;
    cout << endl;

    // Mostrando la cadena reversa
    cout << "The reverse string using reverse iterators is "
            ": ";
    for (it1 = str.rbegin(); it1 != str.rend(); it1++)
        cout << *it1;
    cout << endl;

    return 0;
}
