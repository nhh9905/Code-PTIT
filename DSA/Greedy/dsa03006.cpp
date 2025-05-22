#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, a[1005];

void solve(int a[], int n) {
    if (a[1] > a[n])
        swap(a[1], a[n]);

    int l = 2, r = n - 1;
    while (l < r) {
        if (a[l] > a[r])
            swap(a[l], a[r]);

        if (a[l - 1] > a[l] || a[r] > a[r + 1])
            break;

        ++l, --r;
    }

    if (l < r)
        cout << "No\n";
    else
        cout << "Yes\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t; cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        solve(a, n);
    }

    return 0;
}