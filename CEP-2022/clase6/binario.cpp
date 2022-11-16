#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> prices;

int binary_search(int left, int right, int key) {
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (prices[mid] <= key) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}


int main() {


    int n, q;
    cin >> n;
    prices.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    sort(prices.begin(), prices.end());
    cin >> q;
    while (q--) {
        int m;
        cin >> m;
        cout << binary_search(0, n, m) << "\n";
    }
    return 0;
}