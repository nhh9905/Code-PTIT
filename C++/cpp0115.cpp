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
void solve(int n) {
    if (check(n))
        cout << n << " 1";
    else {
        int cnt;
        for (int i = 2; i <= sqrt(n); i++) {
            cnt = 0;
            while (n % i == 0) {
                ++cnt;
                n /= i;
            }
            if (cnt)
                cout << i << " " << cnt << " ";
            if (check(n)) {
                cout << n << " 1";
                break;
            }
        }
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
}