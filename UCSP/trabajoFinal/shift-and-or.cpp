
#include <bits/stdc++.h>

using namespace std;

#define MAX 500000
#define int long long

static int SearchString(string text, string pattern)
{
    int m = pattern.size();
    unsigned long R;
    unsigned long patternMask[MAX+ 1];
    int i;

    if (pattern[0] == '\0') return -1;

    R = ~1;

    for (i = 0; i <= MAX ; ++i)
        patternMask[i] = ~0; //initializing pattern mask array

    for (i = 0; i < m; ++i)
        patternMask[pattern[i]] &= ~(1UL << i);

    for (i = 0; text[i] != '\0'; ++i)
    {
        R |= patternMask[text[i]];
        R <<= 1;

        if (0 == (R & (1UL << m)))
            return (i - m) + 1;
    }

    return -2;
}


signed main(){

    string txt,pattern;
    int n;

    cin>>txt;
    cin>>n;

    while(n--) {

        cin >> pattern;
        cout<<SearchString(txt,pattern)+1<<"\n";

    }
}