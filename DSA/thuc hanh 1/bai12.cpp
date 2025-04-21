#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n;

ll sum(ll a[]) {
    ll l[n + 5], r[n + 5];
    stack<pii> st;
    ll sum = 0;
    int cnt;

    for (int i = 1; i <= n; i++) {
        cnt = 1;
        while (!st.empty() && a[st.top().fi] < a[i]) {
            cnt += st.top().se;
            st.pop();
        }
        l[i] = cnt;
        st.push({i, cnt});
    }

    while (!st.empty())
        st.pop();

    for (int i = n; i >= 1; i--) {
        cnt = 1;
        while (!st.empty() && a[st.top().fi] <= a[i]) {
            cnt += st.top().se;
            st.pop();
        }
        r[i] = cnt;
        st.push({i, cnt});
    }

    for (int i = 1; i <= n; i++)
        sum += a[i]*l[i]*r[i];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        ll a[n + 5];

        for (int i = 1; i <= n; i++)
            cin >> a[i];
        
        cout << sum(a) << endl;
    }

    return 0;
}