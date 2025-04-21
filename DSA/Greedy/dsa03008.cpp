#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
struct cv {
    int s, f;
} a[1005];

bool cmp(cv a, cv b) {
    if (a.f != b.f)
        return a.f < b.f;
    return a.s < b.s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("a.inp", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i].s;
        for (int i = 1; i <= n; i++)
            cin >> a[i].f;

        sort(a + 1, a + 1 + n, cmp);

        int idx = 1, d = 1;

        for (int i = 2; i <= n; i++) {
            if (a[i].s >= a[idx].f) {
                idx = i;
                ++d;
            }
        }

        cout << d << endl;
    }

    return 0;
}