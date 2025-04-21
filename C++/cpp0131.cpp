#include <bits/stdc++.h>
#define ll long long
using namespace std;
void pt(int n) {
    int i = 2;
    while (n > 0) {
        if (n % i == 0) {
            cout << i << " ";
            break;
        }
        ++i;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            if (i == 1)
                cout << "1 ";
            else
                pt(i);
        }
        cout << endl;
    }
}