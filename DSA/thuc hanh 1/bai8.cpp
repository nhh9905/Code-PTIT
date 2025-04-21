#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n;
ll num[35];

ll solve(int n) {
    num[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            num[i] += num[j]*num[i - j - 1];
        }
    }

    return num[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        memset(num, 0, sizeof(num));
        cin >> n;
        cout << solve(n) << endl;
    }

    return 0;
}