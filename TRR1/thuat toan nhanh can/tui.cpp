#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef struct {
    int w, v;
} node;
node a[105];
int n, weight, Fopt = -1e9, x[105], value = 0, cnt = 0;
double g[105];
vector<vector<int>> v(105);
bool cmp(node a, node b) {
    return (double)a.v/a.w > (double)b.v/b.w;
}
void Branch_And_Bound(int k) {
    for (int j = 1; j >= 0; j--) {
        // ko chon do vat thu k
        if (weight - a[k].w < 0 && j)
            continue;
        x[k] = j;
        if (j == 1) {
            value += a[k].v;
            weight -= a[k].w;
        }
        if (k == n) {
            g[k] = value;
            // update lai cach chon
            if (value > Fopt) {
                Fopt = value;
                for (int i = cnt - 1; i >= 0; i--)
                    v[i].clear();
                cnt = 0;
                for (int i = 1; i <= n; i++)
                    v[cnt].push_back(x[i]);
                ++cnt;
            }
            // cap nhat nhieu cach chon
            else if (value == Fopt) {
                for (int i = 1; i <= n; i++)
                    v[cnt].push_back(x[i]);
                ++cnt;
            }
        }
        else {
            g[k] = value + weight*(double)(a[k + 1].v/a[k + 1].w);
            Branch_And_Bound(k + 1);
        }
        if (j == 1) {
            weight += a[k].w;
            value -= a[k].v;
        }
        // cat nhanh
        if (g[k] < Fopt)
            return;
    }
}
void solve() {
    cin >> n >> weight;
    for (int i = 1; i <= n; i++)
        cin >> a[i].v;
    for (int i = 1; i <= n; i++)
        cin >> a[i].w;
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
        cout << a[i].v << " " << a[i].w << endl;
    Branch_And_Bound(1);
    cout << "Fopt = " << Fopt << endl;
    cout << "Xopt = ";
    for (int i = 0; i < cnt; i++) {
        if (i)
            cout << "       ";
        for (auto x:v[i])
            cout << x << " ";
        cout << endl;
    }
}
int main() {
    freopen("a.inp", "r", stdin);
    solve();
    return 0;
}