#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll a[1000005], cnt = 0;

void merge(ll a[], int l, int r) {
	int i = 0, j = 0;
	int mid = (l + r)/2;
	vector<ll> x(a + l, a + mid + 1), y(a + mid + 1, a + r + 1);
	while (i < x.size() && j < y.size()) {
		if (x[i] <= y[j]) {
			a[l] = x[i];
			++i, ++l;
		}
		else {
			a[l] = y[j];
			++j, ++l;
			cnt += (ll)x.size() - i;
		}
	}

	while (i < x.size()) {
		a[l] = x[i];
		++i, ++l;
	}
	while (j < y.size()) {
		a[l] = y[j];
		++j, ++l;
	}
}

void merge_sort(ll a[], int l, int r) {
	if (l < r) {
		int mid = (l + r)/2;
		merge_sort(a, l, mid);
		merge_sort(a, mid + 1, r);
		merge(a, l, r);
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
		for (int i = 0; i < n; i++)
			cin >> a[i];

		merge_sort(a, 0, n - 1);

		cout << cnt << endl;
		cnt = 0;
	}

	return 0;
}