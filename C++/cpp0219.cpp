#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, m, cnt = 0;
        cin >> n;
        int a[n*n];
        for (int i = 0; i < n*n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n - 1) {
                for (int j = 0; j < n; j++) {
                    cout << a[cnt] << " ";
                    ++cnt;
                }
            }
            else {
                for (int j = 0; j < n; j++) {
                    if (j == 0 || j == n - 1)
                        cout << a[cnt] << " ";
                    else
                        cout << "  ";
                    ++cnt;
                }
            }
            cout << endl;
        }
    }
}