#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        string s;
        ll m, ans = 0;
        cin >> s >> m;
        for (char x:s) {
            ans = ans*10 + x - '0';
            ans %= m;
        }
        cout << ans << endl;
    }
}