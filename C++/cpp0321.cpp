#include <bits/stdc++.h>
#define ll long long
using namespace std;
void tru(string a, string b) {
    if (a.size() != b.size()) {
        if (a.size() < b.size())
            swap(a, b);
        int num = a.size() - b.size();
        for (int i = 0; i < num; i++)
            b = '0' + b;
    }
    else {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] < b[i]) {
                swap(a, b);
                break;
            }
            else if (a[i] > b[i])
                break;
        }
    }
    int ans[a.size()], muon = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] - b[i] - muon < 0) {
            ans[i] = a[i] + 10 - b[i] - muon;
            muon = 1;
        }
        else {
            ans[i] = a[i] - b[i] - muon;
            muon = 0;
        }
    }
    for (int x:ans)
        cout << x;
    cout << endl;
}
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        tru(a, b);
    }
}