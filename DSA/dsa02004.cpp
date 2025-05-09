#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, a[15][15], x[15], num = 0;
bool vis[15][15];
vector<char> v;

void ktra() {
	if (!v.empty()) {
		for (char x:v)
			cout << x;
		cout << " ";
		++num;
		v.clear();
	}
}

// 0: D, 1: R, 2: L, 3: U
void Try(int i, int l, int r) {
	for (int j = 0; j <= 3; j++) {
		x[i] = j;

		if (!x[i]) {
			if (a[l + 1][r] && !vis[l + 1][r]) {
				++l;
				vis[l][r] = 1;
				v.push_back('D');
			}
			else
				continue;
			if (l == n && r == n)
				ktra();
			else {
				Try(i + 1, l, r);
				continue;
			}
		}
		
		if (x[i] == 1) {
			if (a[l][r + 1] && !vis[l][r + 1]) {
				++r;
				vis[l][r] = 1;
				v.push_back('R');
			}
			else
				continue;
			if (l == n && r == n)
				ktra();
			else {
				Try(i + 1, l, r);
				continue;
			}
		}

		if (x[i] == 2) {
			if (a[l][r - 1] && !vis[l][r - 1]) {
				--r;
				vis[l][r] = 1;
				v.push_back('L');
			}
			else
				continue;
			if (l == n && r == n)
				ktra();
			else {
				Try(i + 1, l, r);
				continue;
			}
		}

		if (x[i] == 3) {
			if (a[l - 1][r] && !vis[l - 1][r]) {
				--l;
				vis[l][r] = 1;
				v.push_back('U');
			}
			else
				continue;
			if (l == n && r == n)
				ktra();
			else {
				Try(i + 1, l, r);
				continue;
			}
		}
		vis[l][r] = 0;
	}
	vis[l][r] = 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				cin >> a[i][j];
		}

		Try(1, 1, 1);

		if (!num)
			cout << -1;
		cout << endl;

		num = 0;
		memset(vis, 0, sizeof(vis));
	}	

	return 0;
}