#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, k;
ll ans = 0;
priority_queue<ll, vector<ll>, greater<ll>> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    cin >> n >> k;

    ll a[n + 5];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        q.push(a[i]);
    }

    while (q.size() > 1) {
        ll sum = 0, minn = 1e18 + 5, maxx = 0;
        int x = k;
        if (k > q.size())
            x = q.size();
        while (x) {
            minn = min(minn, q.top());
            maxx = max(maxx, q.top());
            sum += q.top(); q.pop();
            --x;
        }
        q.push(sum);
        ans += maxx - minn;
    }

    cout << q.top() << endl << ans;

    return 0;
}