#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		stack<int> st;
		int a[n], r[n];

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			r[i] = -1;
		}

		for (int i = 0; i < n; i++) {
			while (!st.empty() && a[i] > a[st.top()]) {
				r[st.top()] = i;
				st.pop();
			}
			st.push(i);
		}

		for (int i = 0; i < n; i++) {
			if (r[i] == -1)
				cout << "-1 ";
			else
				cout << a[r[i]] << " ";
		}
		cout << endl;
	}	

	return 0;
}