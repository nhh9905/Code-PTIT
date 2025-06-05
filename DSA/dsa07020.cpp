#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t; cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin >> ws, s);
        stringstream ss(s);
        string tmp;

        while (ss >> tmp) {
            reverse(begin(tmp), end(tmp));
            cout << tmp << " ";
        }
        cout << endl;
    }

    return 0;
}