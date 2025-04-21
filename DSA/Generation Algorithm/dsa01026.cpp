#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, x[1005];
vector<vector<int>> v;

// 0: 8; 1: 6

bool check() {
	if (x[1] || x[n] != 1)
		return 0;
	for (int i = 1; i < n; i++) {
		if (x[i] == x[i + 1] && !x[i])
			return 0;
		if (x[i] == x[i + 1] && x[i + 1] == x[i + 2] && x[i + 2] == x[i + 3] && x[i] == 1)
			return 0;
	}
	return 1;
}

void print() {
	vector<int> tmp;
	for (int i = 1; i <= n; i++) {
		if (!x[i])
			tmp.push_back(8);
		else
			tmp.push_back(6);
	}
	v.push_back(tmp);
}

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n) {
			if (check())
				print();
		}
		else
			Try(i + 1);
	}
}

int main() {
	// freopen("a.inp", "r", stdin);
	cin >> n;
	memset(x, 2, sizeof(x));

	Try(1);

	sort(v.begin(), v.end());
	for (vector<int> x:v) {
		for (int k:x)
			cout << k;
		cout << endl;
	}
	return 0;
}