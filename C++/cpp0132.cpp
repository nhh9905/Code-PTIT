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
        ll n;
        cin >> n;
        if (check(n)) {
            cout << n << endl;
            continue;
        }
        ll k = n, maxx = 0;
        for (int i = 2; i <= sqrt(k); i++) {
            while (n % i == 0)
                n /= i;
            if (n == 1) {
                cout << i << endl;
                break;
            }
        }
        if (n != 1)
            cout << n << endl;
    }
}