#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool ok;
void sinh(int a[], int n) {
    int i = n - 1;
    while (i >= 1 && a[i] < a[i + 1])
        --i;
    if (i == 0)
        ok = 0;
    else {
        int j = n;
        while (a[i] < a[j])
            --j;
        swap(a[i], a[j]);
        int l = i + 1, r = n;
        reverse(a + l, a + 1 + r);
    }
}
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        ok = 1;
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sinh(a, n);
        if (ok) {
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
        }
        else {
            for (int i = n; i >= 1; i--)
                cout << a[i] << " ";
        }
        cout << endl;
    }
}