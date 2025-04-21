#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, x[15], cnt = 0;
ll f[105];
bool used[105];

void fibo() {
	f[1] = f[2] = 1;
	for (int i = 3; i < 93; i++)
		f[i] = f[i - 1] + f[i - 2];
}

void print() {
	for (int i = 1; i <= n; i++)
		cout << x[i] << " ";
	cout << endl;
}

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!used[j]) {
			x[i] = j;
			used[j] = 1;
			if (i == n) {
				++cnt;
				if (binary_search(f + 1, f + 93, cnt)) {
					cout << cnt << ": ";
					print();
				}
			}
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

	cin >> n;

	fibo();

	Try(1);

	return 0;
}