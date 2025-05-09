#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool used[1005];
int x[1005];
string s;

void print(int n) {
	for (int i = 1; i <= n; i++)
		cout << s[x[i] - 1];
	cout << " ";
}

void Try(int n, int i) {
	for (int j = 1; j <= n; j++) {
		if (!used[j]) {
			x[i] = j;
			used[j] = 1;
			if (i == n)
				print(n);
			else
				Try(n, i + 1);
			used[j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		memset(used, 0, sizeof(used));
		cin >> s;
		Try(s.size(), 1);
		cout << endl;
	}	

	return 0;
}