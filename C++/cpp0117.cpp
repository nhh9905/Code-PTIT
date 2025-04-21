#include <bits/stdc++.h>
#define ll long long
using namespace std;
int solve(int n) {
    int s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
        if (!n) {
            if (s >= 10) {
                n = s;
                s = 0;
            }
        }
    }
    return s;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
}