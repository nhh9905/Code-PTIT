#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k >> n;
        multiset<int> s;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                s.insert(x);
            }
        }
        for (int x:s)
            cout << x << " ";
        cout << endl;
        s.clear();
    }
}