#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool check(int n) {
    while (n) {
        int k = n % 10;
        if (k == 0 || k == 6 || k == 8) {
            n /= 10;
            continue;
        }
        else
            return 0;
    }
    return 1;
}
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (check(n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}