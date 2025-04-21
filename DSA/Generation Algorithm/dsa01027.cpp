#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, a[1005], x[1005];
bool used[1005];

void print() {
	for (int i = 1; i <= n; i++)
		cout << a[x[i]] << " ";
	cout << endl;
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
	// freopen("a.inp", "r", stdin);
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a + 1, a + 1 + n);
	Try(1);

	return 0;
}