#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n = 8, x[10], y[10];

bool check() {
	for (int i = 1; i <= n; i++) {
		if (x[i])
			y[i] = 2;
		else
			y[i] = 0;
	}
	int ngay = y[1]*10 + y[2], thang = y[3]*10 + y[4], nam = y[5]*1000 + y[6]*100 + y[7]*10 + y[8];
	if (!ngay || !thang || thang > 12 || nam < 2000)
		return 0;
	return 1;
}

void print() {
	for (int i = 1; i <= n; i++) {
		if (x[i])
			cout << 2;
		else
			cout << 0;
		if (i == 2 || i == 4)
			cout << "/";
	}
	cout << endl;
}

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n) {
			if (check())
				print();
		}
		else
			Try(i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	Try(1);

	return 0;
}