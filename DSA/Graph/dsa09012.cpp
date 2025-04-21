#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
vector<int> adj[1005];
bool visited[1005];

void dfs(int u) {
    visited[u] = 1;
    for (int v:adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

void dinhtru() {
    int tplt = 0;
    vector<int> tru;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ++tplt;
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        int dem = 0;
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                ++dem;
                dfs(j);
            }
        }

        if (dem > tplt)
            tru.push_back(i);
    }

    for (int v:tru)
        cout << v << " ";
    cout << endl;

    for (int i = 1; i <= n; i++)
        adj[i].clear();
    memset(visited, 0, sizeof(visited));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        while (m--) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        dinhtru();
    }

    return 0;
}