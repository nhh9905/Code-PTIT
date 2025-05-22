#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

void solve(string a, string b) {
    int i = a.size() - 1, j = b.size() - 1, cnt = 0;
    ll ans = 0;

    for (int k = j; k >= 0; k--) {
        string s = "";
        for (int h = i; h >= 0; h--) {
            int tich = (b[k] - '0')*(a[h] - '0');
            s = to_string(tich) + s;
        }

        if (k != j) {
            ++cnt;
            for (int i = 1; i <= cnt; i++)
                s = s + "0";
        }
        
        ll tmp = 0;
        for (int idx = s.size() - 1; idx >= 0; --idx) {
            tmp += (s[idx] - '0')*pow(2, s.size() - idx - 1);
        }

        ans += tmp;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t; cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;

        solve(a, b);
    }

    return 0;
}