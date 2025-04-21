#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int cnt = 0;
        cin.ignore();
        string s;
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        while (ss >> tmp)
            cnt++;
        cout << cnt << endl;
    }
}