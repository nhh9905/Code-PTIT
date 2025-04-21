#include <bits/stdc++.h>
#define ll long long
const int N = 10000;    
using namespace std;
bool dd[10005];
void sang() {
    memset(dd, 1, sizeof(dd));
    dd[0] = 0, dd[1] = 0;
    for (int i = 2; i <= sqrt(N); i++) {
        if (dd[i]) {
            for (int j = i*i; j <= N; j += i)
                dd[j] = 0;
        }
    }
}
int main() {
    sang();
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        for (int i = a; i <= b; i++) {
            if (dd[i])
                cout << i << " ";
        }
        cout << endl;
    }
}