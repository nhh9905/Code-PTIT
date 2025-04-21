#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        size_t found = s.find("084");
        if (found != string::npos)
            s.erase(found, 3);
        cout << s << endl;
    }
}