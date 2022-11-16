//
// Created by misash on 05/11/22.
//


#include <iostream>

using namespace std;

int cuadrado(int num){
    int resultado = num * num;
    return resultado;
}

void cuadrado_(int num,int& res){
    res = num * num;
}


int main(){

    cout<<"\nsin referencia\n";
    cout<<cuadrado(2)<<"\n";


    int resultado=0;
    cout<<"\ncon referencia\n";
    cuadrado_(2,resultado);
    cout<<resultado;

//    int luis = 10;
//
//    int &lucho = luis;
//
//    lucho = 8;
//
//    cout<<luis;


}



