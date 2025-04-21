#include <bits/stdc++.h>
#define ll long long
using namespace std;
double s = 0;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        s += (double)1/i;
    cout << fixed << setprecision(4) << s;
}