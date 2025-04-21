#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int x, sc = 0, sl = 0, n = 0;
        while (scanf("%d", &x) != -1) {
            if (x % 2 == 0)
                ++sc;
            else
                ++sl;
            ++n;
            char k = getchar();
            if (k == '\n')
                break;
        }
        if (n % 2 == 0) {
            if (sc > sl)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else {
            if (sl > sc)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}