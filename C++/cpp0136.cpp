#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool check(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        int cnt = 0;
        cin >> n;
        for (int i = 2; i <= sqrt(n); i++) {
            if (check(i) && i*i <= n)
                ++cnt;
        }
        cout << cnt << endl;
    }
}