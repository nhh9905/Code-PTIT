#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int BASE = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> q;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            q.push(x);
        }

        ll ans = 0;

        while (q.size() >= 2) {
            int min1 = q.top(); q.pop();
            int min2 = q.top(); q.pop();
            int sum = (min1 + min2) % BASE;
            ans = (ans + sum) % BASE;
            q.push(sum);
        }

        cout << ans << endl;
    }

    return 0;
}

// 2 3 4 6 -> 5
// 4 5 6 -> 9
// 6 9 -> 15
// 15