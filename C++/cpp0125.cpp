#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool dd[1000005];
void sang(int a, int b) {
    memset(dd, 1, sizeof(dd));
    dd[0] = 0, dd[1] = 0;
    for (int i = 2; i <= sqrt(b); i++) {
        if (dd[i]) {
            for (int j = i*i; j <= b; j += i)
                dd[j] = 0;
        }
    }
    for (int i = a; i <= b; i++) {
        if (dd[i])
            cout << i << " ";
    }
}
int main() {
    int a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    sang(a, b);
}