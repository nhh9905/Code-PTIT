#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool xuly(string s) {
    int ans = 0;
    for (char x:s)
        ans += x - '0';
    if (ans % 9 == 0 && ans)
        return 1;
    return 0;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << xuly(s) << endl;
    }
}