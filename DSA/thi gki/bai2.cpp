#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

struct point {
    int x, y;
};
typedef struct point point;
point a, b;
int ans = 0;

void solve() {
    if (a.x == b.x) {
        ans += abs(a.y - b.y);
        cout << ans;
        return;
    }
    if (a.y == b.y) {
        ans += abs(a.x - b.x);
        cout << ans;
        return;
    }
    
    if (a.x > b.x)
        swap(a, b);
    while (a.x != b.x) {
        ++ans;
        ++a.x;
        if (a.y < b.y)
            ++a.y;
        else if (a.y > b.y)
            --a.y;
    }

    while (a.y < b.y) {
        ++ans;
        ++a.y;
    }

    while (a.y > b.y) {
        ++ans;
        --a.y;
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    cin >> a.x >> a.y >> b.x >> b.y;

    solve();

    return 0;
}