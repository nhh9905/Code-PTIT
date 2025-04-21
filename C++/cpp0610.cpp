#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll bcnn(ll a, ll b) {
	return (a*b)/__gcd(a, b);
}
class PhanSo {
	private:
		ll tu, mau;
	public:
		PhanSo(ll tu, ll mau);
		friend istream& operator >> (istream &in, PhanSo &a);
		friend ostream& operator << (ostream &out, PhanSo a);
		friend PhanSo operator + (PhanSo a, PhanSo b);
};
PhanSo::PhanSo(ll tu, ll mau) {
	this->tu = tu;
	this->mau = mau;
}
istream& operator >> (istream &in, PhanSo &a) {
	in >> a.tu >> a.mau;
	return in;
}
PhanSo operator + (PhanSo a, PhanSo b) {
	PhanSo tong(1, 1);
	ll k = __gcd(a.tu, a.mau);
	a.tu /= k;
	a.mau /= k;
	k = __gcd(b.tu, b.mau);
	b.tu /= k;
	b.mau /= k;
	k = bcnn(a.mau, b.mau);
	a.tu *= k/a.mau;
	b.tu *= k/b.mau;
	tong.tu = a.tu + b.tu;
	tong.mau = k;
	return tong;
}
ostream& operator << (ostream &out, PhanSo a) {
	out << a.tu << "/" << a.mau;
	return out;
}
int main() {
	PhanSo p(1,1), q(1,1);
	cin >> p >> q;
	cout << p + q;
	return 0;
}