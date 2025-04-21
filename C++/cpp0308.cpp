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
        int d[305] = {0};
        for (char x:s)
            d[x]++;
        for (char x:s) {
            if (d[x] == 1)
                cout << x;
        }
        cout << endl;
    }
}