#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {    
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k, s = 0;
        cin >> n >> k;
        if (n < k) 
            s = n*(n + 1)/2;
        else if (n == k)
            s = n*(n - 1)/2;
        else {
            int x = n/(int)k;
            for (int i = 1; i <= x; i++)
                s += k*(k - 1)/2;
            x = n % k;
            s += x*(x + 1)/2;
        }
        if (s == k)
            cout << "1\n";
        else
            cout << "0\n";
    }
}