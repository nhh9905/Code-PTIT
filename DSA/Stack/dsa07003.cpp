#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

void solve(string s) {
    stack<char> st;
    bool check = 0;

    for (char x:s) {
        if (x == '(' || x == '+' || x == '-' || x == '*' || x == '/')
            st.push(x);
        if (x == ')') {
            if (st.top() == '(') {
                check = 1;
                break;
            }
            while (!st.empty() && st.top() != '(')
                st.pop();
            st.pop();
        }
    }

    if (check)
        cout << "Yes";
    else
        cout << "No";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin >> ws, s);
        solve(s);
    }

    return 0;
}