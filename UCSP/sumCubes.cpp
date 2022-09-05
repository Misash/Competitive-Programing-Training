//
// Created by misash on 04/09/22.
//


#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll N = 1000000000000;

unordered_set<ll> cubes;

//precalculo de los N cubos
inline void precal(){
    for (ll i = 1; i*i*i < N ; ++i)
        cubes.insert(i*i*i);
}


int main(){

    precal();
    ll t,n;
    cin>>t;

    while(t--){
        cin>>n;
        bool found = 0;
        for (ll i = 1; i*i*i <= n; ++i) {
            // busqueda suma de cubos
            if(cubes.count(n - i*i*i)){
                cout<<"YES\n";
                found = 1;
                break;
            }
        }
        if(!found) cout<<"NO\n";
    }


}



