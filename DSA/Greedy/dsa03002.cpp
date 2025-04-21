#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	string a, b, c, d;
	cin >> a >> b;
	c = a, d = b;

	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '6')
			a[i] = '5';
	}

	for (int i = 0; i < b.size(); i++) {
		if (b[i] == '6')
			b[i] = '5';
	}

	for (int i = 0; i < c.size(); i++) {
		if (c[i] == '5')
			c[i] = '6';
	}

	for (int i = 0; i < d.size(); i++) {
		if (d[i] == '5')
			d[i] = '6';
	}

	cout << stoi(a) + stoi(b) << " " << stoi(c) + stoi(d) << endl;

	return 0;
}