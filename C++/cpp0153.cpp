#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {    
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        if (n < k)
            cout << n*(n + 1)/2 << endl;
        else if (n == k)
            cout << n*(n - 1)/2 << endl;
        else {
            int x = n/(int)k;
            ll s = 0;
            for (int i = 1; i <= x; i++)
                s += k*(k - 1)/2;
            x = n % k;
            s += x*(x + 1)/2;
            cout << s << endl;
        }
    }
}