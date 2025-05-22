#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

void solve(int k, string a, string b) {
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    string ans = "";

    while (i >= 0 && j >= 0) {
        int sum = (a[i] - '0') + (b[j] - '0') + carry;
        ans = to_string(sum % k) + ans;
        carry = sum / k;
        --i, --j;
    }

    while (i >= 0) {
        int sum = (a[i] - '0') + carry;
        ans = to_string(sum % k) + ans;
        carry = sum / k;
        --i;
    }

    while (j >= 0) {
        int sum = (b[j] - '0') + carry;
        ans = to_string(sum % k) + ans;
        carry = sum / k;
        --j;
    }

    if (carry)
        ans = to_string(carry) + ans;

    cout << ans << endl;
} 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t; cin >> t;

    while (t--) {
        int k;
        string a, b;

        cin >> k >> a >> b;

        solve(k, a, b);
    }

    return 0;
}