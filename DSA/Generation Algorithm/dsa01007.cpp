#include <bits/stdc++.h>
#define ll long long
using namespace std;
int x[1005];

void print(int n) {
	for (int i = 1; i <= n; i++)
		cout << (char)x[i];
	cout << " ";
}

void Try(int n, int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j + (int)'A';
		if (i == n)
			print(n);
		else
			Try(n, i + 1);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		Try(n, 1);
		cout << endl;
	}
	return 0;
}