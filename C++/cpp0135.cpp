#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool check(int n) {
    return sqrt(n) == round(sqrt(n));
}
bool snt(int n) {
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
        int n;
        cin >> n;
        for (int i = 4; i <= n; i++) {
            if (check(i) && snt(sqrt(i)))
                cout << i << " ";
        }
        cout << endl;
    }
}