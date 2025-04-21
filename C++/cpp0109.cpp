#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool check(int n) {
    int chan = 0, le = 0;
    while (n) {
        if ((n % 10) % 2)
            ++le;
        else
            ++chan;
        n /= 10;
    }
    return le == chan;
}
int main() {
    int n, d = 0;
    bool x = 0;
    cin >> n;
    int a = 1, b = 1;
    for (int i = 1; i < n; i++) {
        a *= 10;
        b *= 10;
    }
    b *= 10;
    --b;
    for (int i = a; i <= b; i++) {
        if (check(i)) {
            cout << i << " ";
            ++d;
            x = 0;
        }
        if (d % 10 == 0 && !x) {
            x = 1;
            cout << endl;
        }
    }
}