#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef struct PhanSo {
	ll tu, mau;
} PhanSo;
ll bcnn(ll a, ll b) {
	return (a*b)/__gcd(a, b);
}
void process(PhanSo a, PhanSo b) {
	ll mauC = bcnn(a.mau, b.mau);
	ll tuC = a.tu*(mauC/a.mau) + b.tu*(mauC/b.mau);
	ll k = tuC;
	tuC /= __gcd(k, mauC);
	mauC /= __gcd(k, mauC);
	tuC *= tuC, mauC *= mauC;
	cout << tuC << "/" << mauC << " ";
	ll tuD = a.tu*b.tu*tuC, mauD = a.mau*b.mau*mauC;
	k = tuD;
	tuD /= __gcd(k, mauD);
	mauD /= __gcd(k, mauD);
	cout << tuD << "/" << mauD << endl;
}
int main() {
	// freopen("a.inp", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		PhanSo A;
		PhanSo B;
		cin >> A.tu >> A.mau >> B.tu >> B.mau;
		process(A, B);
	}
}
