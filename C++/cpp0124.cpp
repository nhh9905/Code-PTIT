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
    int n;
    cin >> n;
    if (check(n)) {
        cout << n << " 1";
        return 0;
    }
    int k = n;
    for (int i = 2; i <= sqrt(n); i++) {
        int cnt = 0;
        while (k % i == 0) {
            ++cnt;
            k /= i;
        }
        if (cnt)
            cout << i << " " << cnt << endl;
        if (check(k)) {
            cout << k << " 1";
            break;
        }
    }
}