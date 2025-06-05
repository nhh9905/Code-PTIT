#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define endl "\n"
using namespace std;

int a[1005], r[1005];
stack<int> st;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);

	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = n; i >= 1; i--) {
		while (!st.empty() && a[i] >= st.top())
			st.pop();

		if (st.empty())
			r[i] = -1;
		else
			r[i] = st.top();

		st.push(a[i]);
	}

	for (int i = 1; i <= n; i++)
		cout << r[i] << ' ';

	return 0;
}