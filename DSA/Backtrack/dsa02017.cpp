#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[9][9], maxx = 0, x[105];
bool cot[105], d1[105], d2[105];

void duyet() {
	int ans = 0;
	for (int i = 1; i <= 8; i++)
		ans += a[i][x[i]];
	maxx = max(maxx, ans);
}

void Try(int i) {
	for (int j = 1; j <= 8; j++) {
		if (cot[j] && d1[i - j + 8] && d2[i + j - 1]) {
			x[i] = j;
			cot[j] = d1[i - j + 8] = d2[i + j - 1] = 0;

			if (i == 8)
				duyet();
			else
				Try(i + 1);

			cot[j] = d1[i - j + 8] = d2[i + j - 1] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		memset(cot, 1, sizeof(cot));
		memset(d1, 1, sizeof(d1));
		memset(d2, 1, sizeof(d2));
		maxx = 0;

		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++)
				cin >> a[i][j];
		}

		Try(1);

		cout << maxx << endl;
	}	

	return 0;
}