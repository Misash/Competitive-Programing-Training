//
// Created by misash on 22/07/21.
//

#include <bits/stdc++.h>

using namespace std;


int main(){

    int t,n,k,x,sum,ans;

    cin>>t;

    while(t--){
        cin>>n>>k;
        sum=0;ans=0;
        vector<int> vec;
        for (int i = 0; i < n; ++i) {
            cin>>x;vec.push_back(x);
            sum+=x;
        }

        while(((sum+ans)/n) > k){
            n=vec.size()+1;
            ans++;
        }
        cout<<ans<<"\n";

    }


}