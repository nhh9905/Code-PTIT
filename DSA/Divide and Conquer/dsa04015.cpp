#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);

        for (ll &x:a)
            cin >> x;
        
        int ans = lower_bound(a.begin(), a.end(), k) - a.begin();
        if (a[ans] != k)
            --ans;
        if (ans == -1)
            cout << ans;
        else
            cout << ans + 1;
        cout << endl;
    }

    return 0;
}