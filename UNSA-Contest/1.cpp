//
// Created by misash on 10/11/21.
//

#include <bits/stdc++.h>

using namespace  std;

#define ll long long


void removeSpaces(string &s)
{
    string txt;
    for (char i:s) if (i != ' ') txt+=i;
    s = txt;
}


int main() {

    string s ;
    getline(cin,s);

    removeSpaces(s);

    int r = floor(sqrt(s.size()));
    int c = ceil(sqrt(s.size()));

    while(r*c < s.size()){
        r++;
    }

    vector<vector<string>> arr(r,vector<string>(c," "));

    int ii=0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j <c ; ++j) {
            if(ii < s.size())
                arr[i][j] = s[ii++];
//            else
//                arr[i][j] = "";
        }
    }

//    for (int j = 0; j <r ; ++j) {
//        for (int i = 0; i <c ; ++i) {
//            cout<<arr[j][i];
//        }
//        cout<<"\n";
//    }


//    cout<<endl;

    for (int j = 0; j <c ; ++j) {
        for (int i = 0; i <r ; ++i) {
           if(arr[i][j] != " ") cout<<arr[i][j];
        }
        cout<<" ";
    }

}