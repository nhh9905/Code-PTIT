#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef struct num {
	int data, fre;
} num;
int cnt = 0;
bool cmp(const num &a, const num &b) {
	if (a.fre == b.fre)
		return a.data < b.data;
	return a.fre > b.fre;
}
int main() {
//	freopen("a.inp", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		cnt = 0;
		int n;
		cin >> n;
		num a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i].data;
			a[i].fre = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[j].data == a[i].data)
					a[i].fre++;
			}
		}
		sort(a, a + n, cmp);
		for (int i = 0; i < n; i++)
			cout << a[i].data << " ";
		cout << endl;
	}
}
