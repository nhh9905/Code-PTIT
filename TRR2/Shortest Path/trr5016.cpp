#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define endl "\n"
using namespace std;

int n, a[1005][1005], c[1005][1005], par[1005][1005];

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (c[i][j] > c[i][k] + c[k][j]) {
                    c[i][j] = c[i][k] + c[k][j];
                    par[i][j] = par[i][k];
                }
            }
        }
    }

    int maxx = -1, s, t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (c[i][j] > maxx && c[i][j] != 10000) {
                maxx = c[i][j];
                s = i, t = j;
            }
        }
    }

    // ko tim thay duong di
    if (maxx == -1) {
        cout << 0;
        return;
    }

    cout << s << " " << t << " " << maxx << endl;
    
    // truy vet
    vector<int> vec;
    while (s != t) {
        vec.push_back(s);
        s = par[s][t];
    }
    vec.push_back(t);

    for (int x:vec)
        cout << x << ' ';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    cin >> n;
    memset(c, 10000, sizeof c);
    for (int i = 1; i <= n; i++)
        c[i][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            if (c[i][j] > 0 && c[i][j] <= 50)
                par[i][j] = j;
        }
    }

    floyd();

    return 0;
}