#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int n, s0 = 0, s1 = 0, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            int x;
            cin >> x;
            if (x == 1)
                ++s1;
            else
                ++s0;
        }
        if (s1 > s0)
            ++cnt;
        s0 = 0, s1 = 0;
    }
    cout << cnt;
}