#include <bits/stdc++.h>
using namespace std;
int n, x[105];
bool ok = 1;
void ktao() {
    for (int i = 1; i <= n; i++)
        x[i] = i;
}
void in() {
    for (int i = 1; i <= n; i++)
        cout << x[i] << " ";
    cout << endl;
}
void sinh() {
    int i = n - 1;
    while (i >= 1 && x[i] > x[i + 1])
        --i;
    if (i == 0)
        ok = 0;
    else {
        int j = n;
        while (x[i] > x[j])
            --j;
        swap(x[i], x[j]);
        reverse(x + i + 1, x + 1 + n);
    }
}
int main() {
    cin >> n;
    ktao();
    while (ok) {
        in();
        sinh();
    }
}