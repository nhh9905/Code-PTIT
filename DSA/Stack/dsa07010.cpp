#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

string tc = "+-*/";

bool check(char x) {
    for (int i = 0; i < tc.size(); i++) {
        if (x == tc[i])
            return 1;
    }
    return 0;
}

void solve(string s) {
    stack<string> st;
    int cnt = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
        if (!check(s[i])) {
            st.push(string(1, s[i]));
        }
        else {
            string tmp = "";
            tmp += st.top(); st.pop();
            tmp += st.top(); st.pop();
            tmp += s[i];
            st.push(tmp);
        }
    }

    cout << st.top() << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        solve(s);
    }

    return 0;
}