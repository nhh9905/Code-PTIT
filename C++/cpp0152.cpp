#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, m;
        bool dd = 0;
        cin >> a >> m;
        for (int i = 1; i < m; i++) {
            if (a*i % m == 1) {
                dd = 1;
                cout << i << endl;
                break;
            }
        }
        if (!dd)
            cout << "-1\n";
    }
}