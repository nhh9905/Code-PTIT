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
        int a[n*n + 1];
        for (int i = 1; i <= n*n; i++)
            cin >> a[i];
        int cnt = n;
        for (int i = 1; i <= n*n; i++) {
            cout << a[i] << " ";
            if (i % n == 0 && i != n*n) {
                for (int j = i + n; j >= i + 1; j--)
                    cout << a[j] << " ";
                i += n;
            }
        }
        cout << endl;
    }
}