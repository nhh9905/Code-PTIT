#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define endl "\n"
using namespace std;

void solve(string s) {
    stack<char> st;

    vector<char> vec;
    for (char x:s) {
        if (x != '<' and x != '>' and x != '-')
            vec.push_back(x);
        else {
            if (x == '<') {
                if (!vec.empty()) {
                    st.push(vec.back());
                    vec.pop_back();
                }
            }
            if (x == '>') {
                if (!st.empty()) {
                    vec.push_back(st.top()); st.pop();
                }
            }
            if (x == '-') {
                if (!vec.empty())
                    vec.pop_back();
            }
        }
    }

    while (!st.empty()) {
        vec.push_back(st.top());
        st.pop();
    }

    for (char x:vec)
        cout << x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    string s;
    cin >> s;

    solve(s);

    return 0;
}