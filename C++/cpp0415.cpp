#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int maxa = 0, minb = 1e9;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            maxa = max(maxa, x);
        }
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            minb = min(minb, x);
        }
        cout << (ll)maxa*minb << endl;
    }
}