#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k, a[1005];
bool used[1005];

void print() {
	for (int i = 1; i <= k; i++)
		cout << a[i];
	cout << " ";
}

void Try(int i) {
	for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
		if (!used[j]) {
			used[j] = 1;
			a[i] = j;
			if (i == k)
				print();
			else
				Try(i + 1);
			used[j] = 0;
		}
	}
}

int main() {
	// freopen("a.inp", "r", stdin);
	int t;
	cin >> t;
	a[0] = 0;
	while (t--) {
		cin >> n >> k;
		memset(used, 0, sizeof(used));
		Try(1);
		cout << endl;
	}	
	return 0;
}