//
// Created by misash on 10/09/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;
    int arr[n];

    for (int i = 0; i <n ; ++i) {
        cin>>arr[i];
    }

    for (int i = 0; i < n; ++i) {

        if(i==0){
            cout<<arr[i+1]-arr[i]<<" "<<arr[n-1]-arr[i]<<"\n";
        }else if(i == n-1){
            cout<<arr[i]-arr[i-1]<<" "<<arr[i]-arr[0]<<"\n";
        }else{
            cout<<min(abs(arr[i]-arr[i-1]),abs(arr[i]-arr[i+1]))<<" ";
            cout<<max(abs(arr[i]-arr[n-1]),abs(arr[i]-arr[0]))<<"\n";
        }
    }

}