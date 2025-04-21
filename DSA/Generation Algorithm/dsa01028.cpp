```
// 0.04s
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int x[1005];
vector<int> v;

void print(int n, int k) {
	for (int i = 1; i <= k; i++)
		cout << v[x[i] - 1] << " ";
	cout << endl;
}

void Try(int n, int k, int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k)
			print(n, k);
		else
			Try(n, k, i + 1);
	}
}

int main() {
	// freopen("a.inp", "r", stdin);
	int n, k, a[1005];
	cin >> n >> k;
	x[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (!binary_search(v.begin(), v.end(), a[i])) {
			v.push_back(a[i]);
			sort(v.begin(), v.end());
		}
	}
	sort(v.begin(), v.end());
	Try(v.size(), k, 1);
	return 0;
}
```

```
// 0.05s
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int x[1005];
set<int> s;

void print(int n, int k) {
	for (int i = 1; i <= k; i++) {
		auto it = next(s.begin(), x[i] - 1);
		cout << *it << " ";
	}
	cout << endl;
}

void Try(int n, int k, int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k)
			print(n, k);
		else
			Try(n, k, i + 1);
	}
}

int main() {
	// freopen("a.inp", "r", stdin);
	int n, k, a[1005];
	cin >> n >> k;
	x[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	Try(s.size(), k, 1);
	return 0;
}
```