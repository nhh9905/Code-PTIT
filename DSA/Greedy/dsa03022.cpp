#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int n;
	cin >> n;
	int a[n + 5];

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a + 1, a + 1 + n);

	int ans = max(a[1]*a[2], max(a[1]*a[2]*a[n], max(a[n - 1]*a[n], a[n - 2]*a[n - 1]*a[n])));
	cout << ans << endl;

	return 0;
}