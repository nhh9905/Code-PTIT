#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int n, m, p;
    cin >> n >> m >> p;
    int a[n + 1][m + 1], b[m + 1][p + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= p; j++)
            cin >> b[i][j];
    }
    int c[n + 1][p + 1] = {0}, hang = 1, cot = 1;
    while (hang <= n && cot <= p) {
        int j = 1;
        while (j <= m) {
            c[hang][cot] += a[hang][j]*b[j][cot];
            ++j;
        }
        ++cot;
        if (cot > p) {
            ++hang;
            cot = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= p; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
}