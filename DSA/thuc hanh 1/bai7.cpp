#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, x, y, z;
pii a[20005];
vector<int> v;
ll ans = 0;

bool cmp(pii a, pii b) {
    if (a.fi != b.fi)
        return a.fi < b.fi;
    return a.se < b.se;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    cin >> n >> x >> y >> z;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
        v.push_back(a[i].fi);
        v.push_back(a[i].se + 1);
    }

    sort(a + 1, a + 1 + n, cmp);

    for (int num:v) {
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            if (num < a[i].fi)
                sum += x;
            else {
                if (num <= a[i].se)
                    sum += y;
                else
                    sum += z;
            }
            ans = max(ans, sum);
        }   
    }

    cout << ans;

    return 0;
}