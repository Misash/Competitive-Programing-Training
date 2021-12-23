
#include <bits/stdc++.h>

using namespace std;

bool complement(vector<int> brr,int num,int x){
    sort(brr.begin(),brr.end());

    int a = 0, b = brr.size()-1;
    while (a <= b) {
        int k = (a+b)/2;
        if (brr[k] == x-num) {
            return true;
        }
        if (brr[k] < x) a = k+1;
        else b = k-1;
    }
    return false;
}


int main(){

    int x,n,e;
    vector<int> arr,brr;
    cin>>n>>x;

    for (int i = 0; i < n; i++)
        cin>>e , arr.push_back(e);

    string output="IMPOSSIBLE";;
    for (int i = 0; i < n; i++)
    {
        if(complement(arr,arr[i],x)){
            for (int j = i+1; j <n ; ++j) {
                if(x-arr[i] == arr[j]){
                    output= to_string(++i)+" "+to_string(++j);
                    break;
                }
            }
            break;
        }

    }
    cout<<output;



}
