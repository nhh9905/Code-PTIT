#include <bits/stdc++.h>
#define ll long long
using namespace std;
void in(int x[], int n) {
	for (int i = 1; i <= n; i++)
		cout << x[i];
	cout << " ";
}
void Try(int x[], int n, int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n)
			in(x, n);
		else
			Try(x, n, i + 1);
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int x[n + 1];
		Try(x, n, 1);
		cout << endl;
	}
}
