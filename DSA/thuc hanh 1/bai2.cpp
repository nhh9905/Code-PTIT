#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, k, a[25], x[25];
vector<string> v;

void print() {
    string tmp = "";
    for (int i = 1; i <= k; i++)
        tmp += to_string(a[x[i]]) + " ";
    v.push_back(tmp);
}

void Try(int i) {
    for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
        x[i] = j;
        if (i == k)
            print();
        else
            Try(i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);

    x[0] = 0;
    Try(1);

    sort(begin(v), end(v));
    for (string x:v)
        cout << x << endl;

    return 0;
}