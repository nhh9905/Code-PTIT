#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll f[1005];
void fibo() {
    f[0] = 0, f[1] = 1;
    for (int i = 2; i <= 1000; i++) {
        f[i] = f[i - 1] + f[i - 2];
        f[i] %= mod;
    }
}
int main() {
    fibo();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
}