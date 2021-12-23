

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;
    cout<<"Input n and m :";cin>>n>>m;

    int a[n][m];

    cout<<"\narray nxm:\n";
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++)
            a[i][j]= i+j , cout<<a[i][j]<<" ";
        cout<<"\n";
    }

}