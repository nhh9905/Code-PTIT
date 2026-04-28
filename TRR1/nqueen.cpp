#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, x[105], a[105][105], cnt = 0;
bool xuoi[105], nguoc[105], cot[105];
void in(int n) {
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++)
        a[i][x[i]] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (cot[j] && xuoi[i - j + n] && nguoc[i + j - 1]) {
            x[i] = j;
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 0;
            if (i == n) {
                in(n);
                ++cnt;
            }
            else
                Try(i + 1);
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 1;
        }
    }
}
int main() {
    freopen("a.out", "w", stdout);
    cin >> n;
    memset(cot, 1, sizeof(cot));
    memset(xuoi, 1, sizeof(xuoi));
    memset(nguoc, 1, sizeof(nguoc));
    Try(1);
}