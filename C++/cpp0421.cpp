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
        ll a[n];
        set<ll> s;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        for (int i = 0; i < n; i++) {
            if (s.find(i) != s.end())
                cout << i << " ";
            else
                cout << "-1 ";
        }
        cout << endl;
    }
}