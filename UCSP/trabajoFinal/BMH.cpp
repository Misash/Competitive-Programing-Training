//
// Created by misash on 27/11/22.
//


#include <bits/stdc++.h>
using namespace std;
# define MAX 500001


void badCharHeuristic( string str, int size,
                       int badchar[MAX])
{
    int i;

    for (i = 0; i < MAX; i++)
        badchar[i] = -1;

    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

void BMH(string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();

    int badchar[MAX];


    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while(s <= (n - m))
    {
        int j = m - 1;

        while(j >= 0 && pat[j] == txt[s + j])
            j--;


        if (j < 0)
        {
            cout << s+1 << "\n";
            return;
        }

        else
            s += max(1, j - badchar[txt[s + j]]);
    }
    cout<<-1<< "\n";
}


int main()
{

    string txt,pattern;
    int n;

    cin>>txt;
    cin>>n;

    while(n--) {

        cin >> pattern;
        BMH(txt,pattern);
    }

    return 0;
}

