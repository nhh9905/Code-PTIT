#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, c[105][105], deg_in[105], deg_out[105];
vector<int> adj[105];

void bai1() {
	for (int i = 1; i <= n; i++)
		cout << deg_in[i] << " " << deg_out[i] << endl;
	cout << endl;
}

void bai2() {
	cout << n << endl;

	for (int i = 1; i <= n; i++) {
		cout << adj[i].size() << " ";
		
		for (int v:adj[i])
			cout << v << " ";
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);
	freopen("DT.INP", "r", stdin);
	freopen("DT.OUT", "w", stdout);

	int t;
	cin >> t;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
			if (c[i][j]) {
				++deg_out[i];
				++deg_in[j];
				adj[i].push_back(j);
			}
		}
	}

	if (t == 1)
		bai1();
	else
		bai2();	

	return 0;
}