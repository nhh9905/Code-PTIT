#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[25], s = 0;
void gt() {
    f[1] = 1;
    for (int i = 2; i <= 20; i++)
        f[i] = i*f[i - 1];
}
int main() {
    gt();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        s += f[i];
    cout << s;
}