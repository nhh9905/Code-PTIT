#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        int l = 0, r = n - 1;
        while (l < r) {
            cout << a[r] << " " << a[l] << " ";
            ++l, --r;
        }
        if (l == r)
            cout << a[l];
        cout << endl;
    }
}