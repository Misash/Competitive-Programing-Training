//
// Created by misash on 04/09/22.
//


#include <bits/stdc++.h>
#include <time.h>
#include <chrono>

using namespace std;

#define ll long long
const ll N = 1000000000000;

unordered_set<ll> cubes;
set<ll> cubes2;

//precalculo de los N cubos
inline void precal(){
    for (ll i = 1; i*i*i < N ; ++i)
        cubes.insert(i*i*i);
}

inline void precal2(){
    for (ll i = 1; i*i*i < N ; ++i)
        cubes2.insert(i*i*i);
}


int main(){

    chrono::duration<float,milli> duration;


//    auto start = chrono::system_clock::now();
//    precal2();
//    ll t,n;
//    cin>>t;
//
//    while(t--){
//        cin>>n;
//        bool found = 0;
//        for (ll i = 1; i*i*i <= n; ++i) {
//            // busqueda suma de cubos
//            if(cubes2.find(n - i*i*i) !=  cubes2.end()){
//                cout<<"YES\n";
//                found = 1;
//                break;
//            }
//        }
//        if(!found) cout<<"NO\n";
//    }
//    auto end = chrono::system_clock::now();
//    duration = end - start;
//    cout<<"Tiempo usando set : " << duration.count() << " ms\n";


    auto start = chrono::system_clock::now();
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
    auto end = chrono::system_clock::now();
    duration = end - start;
    cout<<"\nTiempo usando unordered_set : " << duration.count() << " ms\n";






}



