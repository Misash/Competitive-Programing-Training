//
// Created by misash on 31/08/21.
//

#include <bits/stdc++.h>

using namespace std;

vector< vector < string > > product(250, vector< string > (252,"0"));


int main(){

    string a = "1587";
    string b = "25";

    for(int i=b.size()-1;i>=0 ;--i){
        int carry = 0;
        for (int j = a.size()-1; j>=0 ; --j) {
            int r = (b[i] - '0') * (a[j] - '0') + carry;
            if( r > 9){
                carry = r/10;
                r %=10;

            }else{
                carry = 0;
            }
            if(j ==0 && carry!=0) cout<<carry<<" ";
            cout<<r<<" ";

        }
        cout<<"\n";
    }


}




