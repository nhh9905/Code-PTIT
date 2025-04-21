#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << "Buoc 0: " << a[0] << endl;
	for (int i = 1; i < n; i++) {
		int key = a[i], j = i - 1;

		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = key;

		cout << "Buoc " << i << ": ";
		for (int j = 0; j <= i; j++)
			cout << a[j] << " ";
		cout << endl;
	}	

	return 0;
}