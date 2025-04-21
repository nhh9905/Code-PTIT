#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, x[105];
bool used[105];

bool check() {
	for (int i = 1; i < n; i++) {
		if (abs(x[i + 1] - x[i]) == 1)
			return 0;
	}
	return 1;
}

void print() {
	if (check()) {
		for (int i = 1; i <= n; i++)
			cout << x[i];
		cout << endl;
	}
}

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!used[j]) {
			x[i] = j;
			used[j] = 1;
			if (i == n)
				print();
			else
				Try(i + 1);
			used[j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	x[0] = 0;
	while (t--) {
		cin >> n;
		Try(1);
	}

 	return 0;
}