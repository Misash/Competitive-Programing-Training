//
// Created by misash on 26/07/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,s=0,d=0,x;
    cin>>n;
    int arr[n];

    for (int i = 0; i <n ; ++i) {
        cin>>arr[i];
    }

    int *p=arr;
    int *q=p+n-1;

    for (int i = 0; i < n; ++i) {
        if(*p > *q){
            s+=(i%2)? 0:*p;
            d+=(i%2)? *p:0;
            p++;
        } else{
            s+=(i%2)? 0:*q;
            d+=(i%2)? *q:0;
            q--;
        }
    }

    cout<<s<<" "<<d;

}