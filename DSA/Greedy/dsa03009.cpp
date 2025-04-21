#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
bool check[1005];
struct cv {
    int jobld, deadline, profit;
} a[1005];

bool cmp(cv a, cv b) {
    if (a.profit != b.profit)
        return a.profit > b.profit;
    return a.deadline < b.deadline;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        int ans = 0, cnt = 0, idx = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i].jobld >> a[i].deadline >> a[i].profit;

        sort(a + 1, a + 1 + n, cmp);

        for (int i = 1; i <= n; i++) {
            for (int j = a[i].deadline; j >= 1; j--) {
                if (!check[j]) {
                    ans += a[i].profit;
                    check[j] = 1;
                    ++cnt;
                    break;
                }
            }
        }

        cout << cnt << " " << ans << endl;

        memset(check, 0, sizeof(check));
    }

    return 0;
}