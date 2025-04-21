#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, maxx = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            maxx = max(maxx, x);
        }
        cout << maxx << endl;
    }
}