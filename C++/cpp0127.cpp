#include <bits/stdc++.h>
#define ll long long
const int N = 1000000;    
using namespace std;
bool dd[1000005];
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
        int n;
        bool x = 0;
        cin >> n;
        for (int i = 2; i <= n/2; i++) {
            if (dd[i] && dd[n - i]) {
                x = 1;
                cout << i << " " << n - i << endl;
                break;
            }
        }
        if (!x)
            cout << "-1\n";
    }
}