#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, c[505][505];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("a.inp", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    }

    

    return 0;
}