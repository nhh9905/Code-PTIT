#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    queue<int> q;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (!dq.empty() && !(dq.front() ^ (i - k))) // dq.front() == i - k
            dq.pop_front();
        while (!dq.empty() && a[dq.back()] < a[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
            q.push(a[dq.front()]);
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}