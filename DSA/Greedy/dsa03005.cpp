#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k, a[105], s1 = 0, s2 = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        
        sort(a + 1, a + 1 + n);

        int x = k, y = n - k;

        if (x > y)
            swap(x, y);

        for (int i = 1; i <= x; i++) {
            s1 += a[i];
        }

        for (int i = x + 1; i <= n; i++)
            s2 += a[i];

        cout << abs(s2 - s1) << endl;
        s1 = s2 = 0;
    }

    return 0;
}