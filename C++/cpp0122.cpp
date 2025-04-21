#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll bcnn(ll a, ll b) {
    return (ll)(a*b)/__gcd(a, b);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll ans = 1;
        for (ll i = 2; i <= n; i++) {
            ans = bcnn(ans, i);
        }
        cout << ans << endl;
    }
}