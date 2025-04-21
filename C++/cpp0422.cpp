#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, cnt = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            if (x)
                cout << x << " ";
            else
                ++cnt;
        }
        while (cnt) {
            cout << "0 ";
            --cnt;
        }
        cout << endl;
    }
}