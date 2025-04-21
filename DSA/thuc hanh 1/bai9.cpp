#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, k;
ll ans = 0;
bool used[]

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!used[j]) {
			x[i] = j;
			used[j] = 1;
			if (i == n) {
				
			}
			else
				Try(i + 1);
			used[j] = 0;
		}
	}
}

ll calc(int a[]) {
    ll sum = 0;
    for (int i = 1; i <= n - k; i++)
        sum += abs(a[i] - a[i + k]);
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("a.inp", "r", stdin);

    cin >> n >> k;
    int a[n + 5];

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    sort(a + 1, a + 1 + n);



    cout << ans;

    return 0;
}