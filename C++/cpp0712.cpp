#include <bits/stdc++.h>
#define ll long long
using namespace std;
int x[25];
void in(int k) {
    for (int i = 1; i <= k; i++)
        cout << x[i];
    cout << " ";
}
void Try(int n, int k, int i) {
    for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
        x[i] = j;
        if (i == k)
            in(k);
        else
            Try(n, k, i + 1);
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        x[0] = 0;
        Try(n, k, 1);
        cout << endl;
    }
}