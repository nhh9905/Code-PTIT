#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k, a[1005], x[1005];
bool check = 0;

void print(int n) {
	check = 1;
	cout << "[";
	for (int i = 1; i < n; i++)
		cout << x[i] << " ";
	cout << x[n] << "] ";
}

void Try(int i, int u, int sum) {
	for (int j = u; j <= n; j++) {
		x[i] = a[j];
		if (sum + a[j] == k)
			print(i);
		else if (sum + a[j] < k)
			Try(i + 1, j + 1, sum + a[j]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + 1 + n);

		Try(1, 1, 0);

		if (!check)
			cout << "-1";
		cout << endl;
		check = 0;
	}	

	return 0;
}