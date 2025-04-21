#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                cout << "NO\n";
                break;
            }
            ++l;
            --r;
        }
        if (l >= r)
            cout << "YES\n";
    }
}