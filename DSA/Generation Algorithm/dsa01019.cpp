#include <bits/stdc++.h>
#define ll long long
using namespace std;
int x[1005];
vector<vector<char>> v;

// 0: H; 1: A
bool check(int n) {
	if (x[1] != 0 || x[n] != 1)
		return 0;
	for (int i = 1; i < n; i++) {
		if (x[i] == x[i + 1] && !x[i])
			return 0;
	}
	return 1;
}

bool cmp(vector<char> &a, vector<char> &b) {
	return a < b;
}

void print(int n) {
	vector<char> tmp;
	for (int i = 1; i <= n; i++) {
		if (x[i] == 0)
			tmp.push_back('H');
		else
			tmp.push_back('A');
	}
	v.push_back(tmp);
}

void Try(int n, int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n) {
			if (check(n))
				print(n);
		}
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
		sort(v.begin(), v.end(), cmp);
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].size(); j++)
				cout << v[i][j];
			cout << endl;
		}
		v.clear();
	}	
	return 0;
}