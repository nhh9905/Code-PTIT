#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define endl "\n"
using namespace std;

const int N = 1e6 + 5;

int n, a[N], r[N], ans[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t; cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        stack<int> st;
        for (int i = n; i >= 1; i--) {
            while (!st.empty() && st.top() >= a[i])
                st.pop();

            if (st.empty())
                r[i] = -1;
            else
                r[i] = st.top();
            st.push(a[i]);
        }

        stack<pii> st1;
        for (int i = n; i >= 1; i--) {
            while (!st1.empty() && a[i] >= st1.top().fi)
                st1.pop();

            if (st1.empty())
                ans[i] = -1;
            else
                ans[i] = st1.top().se;
            
            st1.push({a[i], r[i]});
        }

        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}