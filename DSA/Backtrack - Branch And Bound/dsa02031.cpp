#include <bits/stdc++.h>
#define ll long long
using namespace std;

char c, x[1005];
bool used[1005];

void print() {
	bool check = 1;
	int n = c - 'A' + 1;

	for (int i = 2; i < n; i++) {
		if (x[i] == 'A' || x[i] == 'E') {
			if (x[i - 1] != 'A' && x[i - 1] != 'E' && x[i + 1] != 'A' && x[i + 1] != 'E') {
				check = 0;
				break;
			}
		}
	}

	if (check) {
		for (int i = 1; i <= n; i++)
			cout << x[i];
		cout << endl;
	}
}

void Try(int i) {
	for (int j = 'A'; j <= c; j++) {
		if (!used[j]) {
			x[i] = j;
			used[j] = 1;
			if (i == c - 'A' + 1)
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

	cin >> c;

	Try(1);

	return 0;
}