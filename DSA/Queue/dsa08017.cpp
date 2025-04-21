#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, x[105];
vector<vector<int>> v;

void print(int n) {
	vector<int> tmp;
	for (int i = 1; i <= n; i++) {
		if (!x[i])
			tmp.push_back(6);
		else
			tmp.push_back(8);
	}
	v.push_back(tmp);
}

void Try(int n, int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n)
			print(n);
		else
			Try(n, i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;

		for (int i = 1; i <= n; i++)
			Try(i, 1);

		for (int i = v.size() - 1; i >= 0; i--) {
			for (int j:v[i])
				cout << j;
			cout << " ";
		}
		cout << endl;

		v.clear();
	}	

	return 0;
}