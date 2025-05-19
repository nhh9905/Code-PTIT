#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

ll a, b, ans = 0;
queue<ll> q;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    cin >> a >> b;

    q.push(4);
    q.push(7);

    while (q.front() <= pow(10, 10)) {
        ll tmp = q.front(); q.pop();
        v.push_back(tmp);
        v.push_back(tmp*10 + 4);
        v.push_back(tmp*10 + 7);
        q.push(tmp*10 + 4);
        q.push(tmp*10 + 7);
    }

    sort(begin(v), end(v));
 
    ll l = a;
    while (l <= b) {
        ll it = *lower_bound(begin(v), end(v), l);
        ll r = min(b, it);
        ans += it*(r - l + 1);
        l = r + 1;
    }

    cout << ans << endl;

    return 0;
}