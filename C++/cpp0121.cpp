#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll k = __gcd(a, b);
        cout << (a*b)/k << " " << k << endl;
    }
}