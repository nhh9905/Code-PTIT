#include <bits/stdc++.h>
#define ll long long
using namespace std;

// 0: A, 1: B
int x[1005], num = 0;
vector<char> v[1005];

bool check(int n, int k) {
	int cnt = 1, check = 0;
	for (int i = 1; i < n; i++) {
		if (x[i] == x[i + 1] && !x[i]) {
			++cnt;
			if (cnt == k) {
				++check;
			}
			if (cnt > k)
				return 0;
		}
		else
			cnt = 1;
	}
	if (check == 1)
		return 1;
	return 0;
}

void print(int n) {
	for (int i = 1; i <= n; i++) {
		if (!x[i])
			v[num].push_back('A');
		else
			v[num].push_back('B');
	}
}

void Try(int n, int k, int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n) {
			if (check(n, k)) {
				print(n);
				++num;
			}
		}
		else
			Try(n, k, i + 1);
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	Try(n, k, 1);

	cout << num << endl;
	for (int i = 0; i < num; i++) {
		for (char x:v[i])
			cout << x;
		cout << endl;
	}
	return 0;
}