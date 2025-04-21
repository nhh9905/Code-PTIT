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
        int a[n], minn = 1e9 + 5;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for (int i = 1; i < n; i++)
            minn = min(minn, a[i] - a[i - 1]);
        cout << minn << endl;
    }
}