#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, p;
        cin >> x >> y >> p;
        ll ans = 1;
        for (int i = 1; i <= y; i++) {
            ans *= x;
            ans %= p;
        }
        cout << ans << endl;
    }
}