#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int a[n + 1], s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s[i] = s[i - 1] + a[i];
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << s[r] - s[l - 1] << endl;
        }
    }
}