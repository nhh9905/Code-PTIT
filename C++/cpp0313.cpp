#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    string s, x, tmp;
    getline(cin, s);
    cin >> x;
    stringstream ss(s);
    while (ss >> tmp) {
        if (tmp != x)
            cout << tmp << " ";
    }
}