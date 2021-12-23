
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    int x;double y;

    cin>>x>>y;

    if(x % 5 == 0 && y-x-0.5>=0){
        cout<<fixed<<setprecision(2)<<y-(x+0.5);
    }else{
        cout<<fixed<<setprecision(2)<<y;
    }

}