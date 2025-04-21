#include <bits/stdc++.h>
using namespace std;
int n, x[1005];
void print() {
	for (int i = 1; i <= n; i++)
		cout << x[i] << " ";
	cout << endl;
}
bool check() {
	int l = 1, r = n;
	while (l < r) {
		if (x[l] != x[r])
			return 0;
		++l, --r;
	}
	return 1;
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
	cin >> n;
	Try(1);
	return 0;
}