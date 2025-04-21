#include <bits/stdc++.h>
#define ll long long
using namespace std;

void tower(int n, char a, char b, char c) {
	if (n == 1)
		cout << a << " -> " << c << endl;
	else {
		tower(n - 1, a, c, b);
		tower(1, a, b, c);
		tower(n - 1, b, a, c);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int n;
	cin >> n;

	tower(n, 'A', 'B', 'C');

	return 0;
}