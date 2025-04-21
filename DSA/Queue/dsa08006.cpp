#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        queue<int> q;

        q.push(9);
        while (!q.empty()) {
            if (q.front() % n == 0) {
                cout << q.front() << endl;
                break;
            }
            q.push(q.front()*10 + 0);
            q.push(q.front()*10 + 9);
            q.pop();
        }
    }

    return 0;
}