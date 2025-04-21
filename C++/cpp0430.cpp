#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, cnt = 0;
        cin >> n;
        set<int> s;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        int minn = *s.begin(), maxx = *s.rbegin();
        for (int i = minn; i <= maxx; i++) {
            if (s.find(i) == s.end())
                ++cnt;
        }
        cout << cnt << endl;
    }
}