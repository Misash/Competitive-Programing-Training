//
// Created by misash on 29/07/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;
    string s(n,' ');
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
    }

    int w = min(min(count(s.begin(),s.end(),'1'),count(s.begin(),s.end(),'2')),count(s.begin(),s.end(),'3'));

    int i=0,j=0,k=0;
    cout<<w<<"\n";
    while(w--){
       i = s.find('1',i);
       j = s.find('2',j);
       k = s.find('3',k);
       cout<<i+1<<" "<<j+1<<" "<<k+1<<"\n";
       i++,j++,k++;
    }






}