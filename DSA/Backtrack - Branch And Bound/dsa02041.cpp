#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

void solve(int n) {
    queue<pii> q;
    q.push({n, 0});

    while (!q.empty()) {
        pii v = q.front(); q.pop();

        if (v.fi == 1) {
            cout << v.se << endl;
            break;
        }

        if (v.fi % 3 == 0)
            q.push({v.fi / 3, v.se + 1});
        if (v.fi % 2 == 0)
            q.push({v.fi / 2, v.se + 1});
        if (v.fi > 1)
            q.push({v.fi - 1, v.se + 1});
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t; cin >> t;

    while (t--) {
        int n;
        cin >> n;

        solve(n);
    }

    return 0;
}