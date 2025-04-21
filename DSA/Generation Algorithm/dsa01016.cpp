#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, a[1005];

void in(int n) {
	bool check = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i + 1])
			check = 0;
	}
	if (check) {
	    cout << "(";
		for (int i = 1; i < n; i++)
			cout << a[i] << " ";
		cout << a[n] << ")" << " ";
	}
}

void Try(int x, int i, int s) {
	for (int j = x; j >= 1; j--) {
		a[i] = j;
		if (j == s)
			in(i);
		else if (j < s)
			Try(n - j, i + 1, s - j);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);

	int t;
	cin >> t;
	
	while (t--) {
		cin >> n;
		Try(n, 1, n);
		cout << endl;
	}

	return 0;
}