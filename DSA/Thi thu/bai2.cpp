#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int N = 200005;

int n, k, a[N];

void slidingWindow() {
    deque<int> dq;

    for (int i = 1; i <= n; i++) {
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        if (a[i] < 0)
            dq.push_back(i);

        if (i >= k) {
            if (!dq.empty())
                cout << a[dq.front()] << " ";
            else
                cout << "0 ";
        }
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("a.inp", "r", stdin);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    slidingWindow();

    return 0;
}