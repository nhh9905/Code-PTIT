#include <bits/stdc++.h>
#define ll long long
using namespace std;
void genBinString(int n, string s = "") {
    if (s.size() == n) {
        cout << s << endl;
        return;
    }
    genBinString(n, s + '0');
    genBinString(n, s + '1');
}
void solve() {
    int n;
    cin >> n;
    genBinString(n);
}
int main() {
    solve();
}