#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool check(ll n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (check(n)) {
            if (k == 1)
                cout << n;
            else
                cout << -1;
            cout << endl;
            continue;
        }
        int cnt = 0, x = n;
        bool dd = 0;
        for (int i = 2; i <= sqrt(x); i++) {
            while (n % i == 0) {
                ++cnt;
                if (cnt == k) {
                    dd = 1;
                    cout << i << endl;
                    break;
                }
                n /= i;
            }
        }
        if (n != 1 && !dd) {
            ++cnt;
            if (cnt == k)
                cout << n;
            else
                cout << -1;
            cout << endl;
            dd = 1;
        }
        if (!dd)
            cout << -1 << endl;
    }
}