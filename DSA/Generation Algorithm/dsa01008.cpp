#include <bits/stdc++.h>
#define ll long long
using namespace std;
int x[1005];

bool check(int n, int k) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (x[i])
			++cnt;
	}
	if (cnt == k)
		return 1;
	return 0;
}

void print(int n) {
	for (int i = 1; i <= n; i++)
		cout << x[i];
	cout << endl;
}

void Try(int n, int k, int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n) {
			if (check(n, k))
				print(n);
		}
		else
			Try(n, k, i + 1);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		Try(n, k, 1);
	}	
	return 0;
}