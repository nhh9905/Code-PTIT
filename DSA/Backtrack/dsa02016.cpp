#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool cot[1005], d1[1005], d2[1005];
int n, cnt = 0;

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (cot[j] && d1[i - j + n] && d2[i + j -1]) {
			cot[j] = d1[i - j + n] = d2[i + j - 1] = 0;

			if (i == n)
				++cnt;
			else
				Try(i + 1);

			cot[j] = d1[i - j + n] = d2[i + j - 1] = 1;
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
		cin >> n;

		cnt = 0;
		memset(cot, 1, sizeof(cot));
		memset(d1, 1, sizeof(d1));
		memset(d2, 1, sizeof(d2));

		Try(1);

		cout << cnt << endl;
	}	

	return 0;
}