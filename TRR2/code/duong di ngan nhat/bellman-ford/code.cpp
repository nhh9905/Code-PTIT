#include <bits/stdc++.h>

using namespace std;

struct edge {
    int x, y, w;
};
int n, m;
vector<edge> dscanh;
int d[1005];

void nhap() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        dscanh.push_back({x, y, w});
    }
}

void Bellman_ford(int s) {
    // gan nhan duong di
    // cac dinh khong phai dinh goc deu co chi phi duong di la vo cung
    // dinh goc co chi phi duong di la 0
    for (int i = 0; i <= n; i++)
        d[i] = 1e9;
    d[s] = 0;

    // buoc lặp n - 1
    for (int i = 0; i < n - 1; i++) {
        // duyệt tất cả các cạnh trên đồ thị
        // relaxation
        for (int j = 0; j < m; j++) {
            edge tmp = dscanh[j];
            if (d[tmp.x] < 1e9)
                d[tmp.y] = min(d[tmp.y], d[tmp.x] + tmp.w);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    nhap();
    Bellman_ford(1);
    return 0;
}