//
// Created by misash on 10/09/21.
//

#include<bits/stdc++.h>

using namespace std;


int main(){

    int p,n;
    cin>>n;
    int arr[n];

    for (int i = 1; i <=n ; ++i) {
        cin>>p;
        arr[p-1] = i;
    }

    for (int *i = arr; i<arr+n ; ++i) cout<<*i<<" ";


}