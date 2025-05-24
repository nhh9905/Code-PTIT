#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n;
string s[30];

bool check(string s) {
    int cnt = 0, d[1005] = {};

    for (char x:s) {
        if (!d[x])
            ++cnt;
        d[x]++;
    }

    return cnt == 26;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);
        
    cin >> n;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    for (int i = 1; i <= n; i++) {
        string tmp = s[i];

        if (check(tmp))
            ++ans;

        for (int j = i + 1; j <= n; j++) {
            tmp += s[j];
            
            if (check(tmp))
                ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}