#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        set<int> s;
        int n;
        cin >> n;
        bool dd = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x >= 0)
                s.insert(x);
        }
        if (s.find(1) == s.end()) {
            cout << 1 << endl;
            continue;
        }
        for (int x:s) {
            if (s.find(x + 1) == s.end()) {
                dd = 1;
                cout << x + 1 << endl;
                break;
            }
        }
        if (!dd)
            cout << 1 << endl;
    }
}