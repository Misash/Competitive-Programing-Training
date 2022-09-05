
#include <bits/stdc++.h>

#define ll long long

using namespace std;


int zeros(ll n)
{
    if (n < 0) return -1;
    int count = 0;

    for (ll i = 5; n / i >= 1; i *= 5)
        count += n / i;

    return count;
}


int main()
{
    ll m , i=0;
    cin>>m;
    vector<int> v;

    while(zeros(i) <= m)
    {
        if(zeros(i) == m)
            v.push_back(i);

        i++;
    }

    cout<<v.size()<<"\n";
    for( int num: v)
        cout<<num<<" ";

    return 0;
}
