#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << fixed << setprecision(4) << sqrt((c - a)*(c - a) + (d - b)*(d - b)) << endl;
    }
}