#include <bits/stdc++.h>
#define ll long long
using namespace std;
string ma101 = "ABBADCCABDCCABD";
string ma102 = "ACCABCDDBBCDDBB";
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        string s;
        int ma;
        char a[16];
        cin >> ma;
        for (int i = 1; i <= 15; i++) {
            cin >> a[i];
            s += a[i];
        }
        int cnt = 0;
        if (ma == 101) {
            for (int i = 0; i < 15; i++) {
                if (s[i] == ma101[i])
                    ++cnt;
            }
        }
        else {
            for (int i = 0; i < 15; i++) {
                if (s[i] == ma102[i])
                    ++cnt;
            }
        }
        cout << fixed << setprecision(2) << (float)cnt/15*10 << endl;
    }
}