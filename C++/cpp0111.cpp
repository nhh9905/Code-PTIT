#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        bool dd = 0;
        string s;
        cin >> s;
        for (int i = 1; i < s.size(); i++) {
            if (abs(s[i] - s[i - 1]) != 1) {
                cout << "NO\n";
                dd = 1;
                break;
            }
        }
        if (!dd)
            cout << "YES\n";
    }
}