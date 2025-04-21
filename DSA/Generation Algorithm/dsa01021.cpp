#include <bits/stdc++.h>
#define ll long long
using namespace std;
int ans = 0;
vector<int> v;

void sinh(int a[], int n, int k) {
	int i = k;
	while (i >= 1 && a[i] == n - k + i)
		--i;
	if (i == 0)
		ans = k;
	else {
		++a[i], ++ans;
		for (int j = i + 1; j <= k; j++) {
			a[j] = a[j - 1] + 1;
			if (!binary_search(v.begin(), v.end(), a[j]))
				++ans;
			else
				break;
		}
	}	
}

int main() {
	// freopen("a.inp", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int a[k + 5];
		for (int i = 1; i <= k; i++) {
			cin >> a[i];
			v.push_back(a[i]);
		}
		sinh(a, n, k);
		cout << ans << endl;
		ans = 0;
		v.clear();
	}	
	return 0;
}