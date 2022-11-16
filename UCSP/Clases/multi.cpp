//
// Created by misash on 02/11/22.
//


#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<vector<int>> m(100);
    vector<int> d(100);
    vector<vector<list<int>>> p(100);

    int len = 4;
    int s = 10;
    int cont = 0;

    for (int len = 1; len < (s + 1); len++){

        for (int i = 1; i < ((s + 1) - len); i++){

            int j = i + len;
            m[i][j] = INT_MAX;
            int bestk = -1;
            for (int k = i; k <= (j - 1); k++) {
                 cout << cont++ << endl;
                 cout << i << " " << j << " " << len << " " << k << endl;
                int cost = m[i][k] + m[k + 1][j] + (d[i - 1] * d[k] * d[j]);
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    bestk = k;
                }
            }

            if (m[i][j - 1] < m[i + 1][j]) {
                p[i][j] = p[i][j - 1];
                p[i][j].push_back(j - 1);
            } else {
                p[i][j] = p[i + 1][j];
                p[i][j].push_back(i - 1);
            }
        }

        cout << endl;

    }

    return 0;
}