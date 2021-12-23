//
// Created by misash
//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);

    ll n,t,k;

    cin>>t;
    while(t--){
        ll sum=0,x,new_mx=0,mx=0;
        cin>>n>>k;
        ll arr[n];
        for (ll i = 0; i <n ; ++i) {
            cin>>arr[i];
        }

        sort(arr,arr+n);

        vector<ll> vec;
        ll num=0;
        for (ll i = 0; i <n ; ++i) {
            num += arr[i];
            if(i==n-1){
                if(arr[i] == arr[i-1]){
                    vec.push_back(num);
                }else{
                    vec.push_back(arr[i]);
                }

            }else if(arr[i]!=arr[i+1] && i<n-1){
                vec.push_back(num);
                num=0;
            }
        }

        sort(vec.begin(),vec.end());

        for (ll i = vec.size()-1; k>0 && i>=0 ; --i) {
            if(vec[i]>0){
                sum+=vec[i];
                k--;
            }

        }
        cout<<sum<<"\n";
    }

}
