#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, a[15][15], x[15], num = 0;

// 0: D, 1: R
void ktra() {
	int i = 1, j = 1, cnt = 1;
	bool check = 1;
	
	if (!a[i][j])
		check = 0;
	while (a[i][j]) {
		if (!x[cnt])
			++i;
		else
			++j;
		if (!a[i][j]) {
			check = 0;
			break;
		}
		if (i == n && j == n)
			break;
		++cnt;
	}
	if (check) {
		++num;
		for (int i = 1; i <= (n - 1)*2; i++) {
			if (!x[i])
				cout << 'D';
			else
				cout << 'R';
		}
		cout << " ";
	}
}

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == (n - 1)*2)
			ktra();
		else
			Try(i + 1);
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
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				cin >> a[i][j];
		}

		Try(1);

		if (!num)
			cout << -1;
		cout << endl;

		num = 0;
	}	

	return 0;
}