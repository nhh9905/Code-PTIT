#include <bits/stdc++.h>
#define ll long long
using namespace std;
class PhanSo {
	private:
		ll tu, mau;
	public:
		PhanSo(ll tu, ll mau);
		friend istream& operator >> (istream &in, PhanSo &a);
		void rutgon() {
			ll k = __gcd(tu, mau);
			tu /= k;
			mau /= k;
		}
		friend ostream& operator << (ostream &out, PhanSo a);
};
PhanSo::PhanSo(ll tu, ll mau) {
	this->tu = tu;
	this->mau = mau;
}
istream& operator >> (istream &in, PhanSo &a) {
	in >> a.tu >> a.mau;
	return in;
}
ostream& operator << (ostream &out, PhanSo a) {
	out << a.tu << "/" << a.mau;
	return out;
}
int main() {
//	freopen("a.inp", "r", stdin);
	PhanSo p(1,1);
	cin >> p;
	p.rutgon();
	cout << p;
	return 0;
}
