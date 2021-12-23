//
// Created by misash on 11/11/21.
//


#include <bits/stdc++.h>

using namespace  std;

#define ll long long


bool isleap(int year)
{

    if (year >=1919 ){
        if (year % 400 == 0)
            return true;
        if (year % 100 == 0)
            return false;
        if (year % 4 == 0)
            return true;
        return false;
    }else{
        if(year % 4 == 0) return true;
        return false;
    }
}


int main(){


    int y ,d;

    cin>>y;

    if(y == 1918){
        d = 26;
    }else{
        d = 12 + (isleap(y) == 0);
    }

    cout<<d<<".09."<<y;

}