//
// Created by misash on 23/07/21.
//

#include <bits/stdc++.h>

using namespace  std;

bool findOne(int M[5][5],int i){
    for (int j = 0; j <5 ; ++j) {
        cin>>M[i][j];
        if(M[i][j] ){
            cout<<abs(2-i)+abs(2-j);
            return true;
        }
    }
   return false;
}



int main(){

    int M[5][5] ;

    for (int i = 0; i <5 ; ++i)
        if (findOne(M, i))  break;

}