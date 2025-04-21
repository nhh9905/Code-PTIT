#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// freopen("a.inp", "r", stdin);
	int n;
	cin >> n;
	int a[n + 5][n + 5];
	memset(a, 0, sizeof(a));
	
	for (int i = 1; i <= n; i++) {
		string s;
		getline(cin >> ws, s);
		stringstream ss(s);
		string tmp;
		int cnt = 0;
		while (ss >> tmp) {
			a[i][stoi(tmp)] = 1;
			a[stoi(tmp)][i] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}

	return 0;
}