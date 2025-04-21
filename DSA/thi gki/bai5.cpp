#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, a[1005], ti = 0, teo = 0;

void solve() {
    int l = 1, r = n;
    
    while (l < r) {
        if (a[r] > a[l]) {
            ti += a[r];
            --r;
            if (a[r] > a[l]) {
                teo += a[r];
                --r;
            }
            else {
                teo += a[l];
                ++l;
            }
        }
        else {
            ti += a[l];
            ++l;
            if (a[r] < a[l]) {
                teo += a[l];
                ++l;
            }
            else {
                teo += a[r];
                --r;
            }
        }
    }

    if (l == r)
        ti += a[l];

    cout << ti << " " << teo;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    solve();

    return 0;
}