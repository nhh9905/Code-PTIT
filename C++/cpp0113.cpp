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
        int s = n % 10;
        n /= 10;
        s += (n % 10)*10;
        if (s == 86)
            cout << "1\n";
        else
            cout << "0\n";
    }
}