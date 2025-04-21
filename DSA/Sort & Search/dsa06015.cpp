#include <bits/stdc++.h>
#define ll long long
using namespace std;

void merge(int a[], int l, int mid, int r) {
	vector<int> c(a + l, a + mid + 1);
	vector<int> d(a + mid + 1, a + r + 1);
	int i = 0, j = 0;

	while (i < c.size() && j < d.size()) {
		if (c[i] <= d[j]) {
			a[l] = c[i];
			++i, ++l;
		}
		else {
			a[l] = d[j];
			++j, ++l;
		}
	}

	while (i < c.size()) {
		a[l] = c[i];
		++i, ++l;
	}
	while (j < d.size()) {
		a[l] = d[j];
		++j, ++l;
	}
}

void merge_sort(int a[], int l, int r) {
	if (l >= r)
		return;
	int mid = (l + r)/2;
	merge_sort(a, l, mid);
	merge_sort(a, mid + 1, r);
	merge(a, l, mid, r);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		merge_sort(a, 0, n - 1);

		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}	

	return 0;
}