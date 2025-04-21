#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        map<int, int> m;
        int n, cnt = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            m[x]++;
        }
        for (auto x:m) {
            if (m[x.first] > 1)
                cnt += m[x.first];
        }
        cout << cnt << endl;
    }
}
