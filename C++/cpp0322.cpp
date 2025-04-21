#include <bits/stdc++.h>
#define ll long long
using namespace std;
void cong(string a, string b) {
    if (a.size() != b.size()) {
        if (a.size() < b.size())
            swap(a, b);
        int num = a.size() - b.size();
        for (int i = 0; i < num; i++)
            b = '0' + b;
    }
    int ans[a.size() + 1], muon = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] + b[i] - 2*'0' + muon > 9) {
            ans[i] = a[i] + b[i] - 2*'0' + muon - 10;
            muon = 1;
        }
        else {
            ans[i] = a[i] + b[i] - 2*'0' + muon;
            muon = 0;
        }
    }
    int des = a.size();
    if (muon) {
        des = a.size() + 1;
        for (int i = a.size(); i > 0; i--)
            ans[i] = ans[i - 1];
        ans[0] = muon;
    }
    for (int i = 0; i < des; i++) {
        cout << ans[i];
    }
    cout << endl;
}
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cong(a, b);
    }
}