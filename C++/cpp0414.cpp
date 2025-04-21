#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            while (x > 0) {
                s.insert(x % 10);
                x /= 10;
            }
        }
        while (!s.empty()) {
            cout << *s.begin() << " ";
            s.erase(*s.begin());
        }
        cout << endl;
    }
}