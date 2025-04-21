#include <bits/stdc++.h>
#define ll long long
using namespace std;
void chia(string a, string b) {
    
    string tmp = a.substr(b.size() + 1);
    chia(tmp, b);
}
void solve() {
    string x, y;
    cin >> x >> y;

}
int main() {
    freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
//523152351235132532/528716352