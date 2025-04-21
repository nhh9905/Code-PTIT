#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);    
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        bool dd = 0;
        cin >> n >> x;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == x && !dd)
                dd = 1;
        }
        if (!dd)
            cout << "-1\n";
        else
            cout << "1\n";
    }
}