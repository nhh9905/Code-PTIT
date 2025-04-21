#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, cnt = 0, a[105][105] = {0};
vector<int> adj[105];
vector<pii> edge;

void bai1() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;

		for (int j = 1; j <= k; j++) {
			int x;
			cin >> x;
			if (i < x) {
				adj[i].push_back(x);
				adj[x].push_back(i);	
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << adj[i].size() << " ";
	cout << endl;
}

void bai2() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;

		for (int j = 1; j <= k; j++) {
			int x;
			cin >> x;
			edge.push_back({i, x});
		}
	}

	cout << n << " " << edge.size() << endl;

	for (int i = 0; i < edge.size(); i++) {
		pii v = edge[i];
		a[v.fi][i + 1] = 1;
		a[v.se][i + 1] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= edge.size(); j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);
	// freopen("DT.INP", "r", stdin);
	// freopen("DT.OUT", "w", stdout);

	int t;
	cin >> t;

	if (t == 1)
		bai1();
	else
		bai2();	

	return 0;
}