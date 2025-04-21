#include <bits/stdc++.h>
#define ll long long
using namespace std;
set<string> st;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        st.insert(s);
    }
    cout << st.size();
}