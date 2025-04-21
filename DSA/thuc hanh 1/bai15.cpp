#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

ll n;

bool check(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}

int tong(ll n) {
    int sum = 0;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    cin >> n;
    int cnt = 0;

    for (ll i = 1; i <= (n - 1)/2; i++) {
        ll y = n - 2*i;
        if (y > 0 && check(tong(i)) && check(tong(y)))
            ++cnt;
    }
    
    cout << cnt;

    return 0;
}