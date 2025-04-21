#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        string s;
        int k, cnt = 0;
        bool d[125] = {0};
        cin >> s >> k;
        for (char x:s)
            d[x] = 1;
        for (char i = 'a'; i <= 'z'; i++) {
            if (!d[i])
                ++cnt;
        }
        if (cnt > k)
            cout << "0\n";
        else
            cout << "1\n";
    }
}