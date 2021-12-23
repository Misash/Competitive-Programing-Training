//
// Created by misash on 29/07/21.
//

#include <iostream>

using namespace std;




int menor(char *a, char *b)
{
    int lenA= 0 ,lenB=0;
    int asciiA=0,asciiB=0;

    for (char *i = a; *i != '\0' ; i++) {
        lenA++;
        asciiA+=*i;
    }

    for (char *i = b; *i != '\0' ; i++) {
        lenB++;
        asciiB+=*i;
    }

    if(lenA < lenB ) return 1;
    if(lenB < lenA )   return 2;
    if(asciiA == asciiB && lenA == lenB) return  0;
    if(asciiA > asciiB) return 2;
    else return 1;

}




int main() {
    char A[3][100] = { "Anastasia","anastasia","anabel"};

    cout<<"frase 1: "<<A[0]<<endl;
    cout<<"frase 2: "<<A[1]<<endl;
    cout<<"La frase menor es "<<menor(A[0],A[1])<<endl<<endl;

    cout<<"frase 1: "<<A[1]<<endl;
    cout<<"frase 2: "<<A[2]<<endl;
    cout<<"La frase menor es "<<menor(A[1],A[2])<<endl<<endl;

    cout<<"frase 1: "<<A[0]<<endl;
    cout<<"frase 2: "<<A[1]<<endl;
    cout<<"La frase menor es "<<menor(A[0],A[1])<<endl<<endl;


    return 0;

}