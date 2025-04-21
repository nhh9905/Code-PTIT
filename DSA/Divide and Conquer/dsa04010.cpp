#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, a[105], s[105], ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s[i] = s[i - 1] + a[i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++)
                ans = max(ans, s[j] - s[i - 1]);
        }

        cout << ans << endl;
        ans = 0;
    }

    return 0;
}