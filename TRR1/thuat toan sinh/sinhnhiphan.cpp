#include <bits/stdc++.h>
#define ll long long
using namespace std;
void genBinString(int n) {
    queue<string> q;
    q.push("0"); q.push("1");
    while (q.front().size() < n) {
        string s = q.front();
        q.pop();
        q.push(s + "0");
        q.push(s + "1");
    }
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
}
void solve() {
    int n;
    cin >> n;
    genBinString(n);
}
int main() {
    solve();
}