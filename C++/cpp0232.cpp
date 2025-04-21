#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n + 1][m + 1], cot[20] = {0}, minn = 20;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        }
        for (int i = 1; i <= m; i++) {
            int x = 0;
            for (int j = 1; j <= n; j++) {
                if (a[j][i] == 1)
                    ++x;
                else {
                    cot[i] = max(cot[i], x);
                    x = 0;
                }
            }
            if (!cot[i])
                cot[i] = x;
        }
        for (int i = 1; i <= m; i++) {
            cout << cot[i] << " ";
        }
        cout << endl;
    }
}