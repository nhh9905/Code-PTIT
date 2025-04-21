#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    string s;
    cin >> s;
    string tmp = "aeiouy";
    for (char x:s) {
        x = (char)tolower(x);
        if (tmp.find(x) == string::npos)
            cout << "." << x;
    }
}