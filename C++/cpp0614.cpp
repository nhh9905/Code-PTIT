#include <bits/stdc++.h>
#define ll long long
using namespace std;
class NhanVien {
	private:
		string id, ten, gt, ngaySinh, dc, mst, ngayKy;
		static int dem;
	public:
		friend istream& operator >> (istream &in, NhanVien &a);
		friend ostream& operator << (ostream &out, NhanVien a);
};
int NhanVien::dem = 0;
istream& operator >> (istream &in, NhanVien &a) {
	in.ignore();
	getline(in, a.ten);
	in >> a.gt >> a.ngaySinh;
	in.ignore();
	getline(in, a.dc);
	in >> a.mst >> a.ngayKy;
	++NhanVien::dem;
	a.id = string(5 - to_string(NhanVien::dem).size(), '0') + to_string(NhanVien::dem);
	return in;
}
ostream& operator << (ostream &out, NhanVien a) {
	out << a.id << " " << a.ten << " " << a.gt << " " << a.ngaySinh << " " << a.dc << " " << a.mst << " " << a.ngayKy << endl;
	return out;
}
int main() {
//	freopen("a.inp", "r", stdin);
	NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> ds[i];
    for(i=0;i<N;i++) cout << ds[i];
    return 0;
}
