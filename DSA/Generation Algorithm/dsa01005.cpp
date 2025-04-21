#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, x[1005];
bool used[1005];

void print() {
	for (int i = 1; i <= n; i++)
		cout << x[i];
	cout << " ";
}

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!used[j]) {
			x[i] = j;
			used[j] = 1;
			if (i == n)
				print();
			else
				Try(i + 1);
			used[j] = 0;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		Try(1);
		cout << endl;
	}	
	return 0;
}